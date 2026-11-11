// Feito com auxilio de uma ferramenta de inteligência artificial

#include <windows.h>
#include <mmsystem.h>   /* Apenas constantes (SND_MEMORY, SND_SYNC); a funcao e carregada em tempo de execucao */
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Taxa de amostragem do audio gerado (Hz) */
#define TAXA_AMOSTRAGEM 44100

/* Volume do audio gerado: 0.0 (mudo) a 1.0 (maximo digital, sem folga) */
#define VOLUME 1.35

/* Frequencias das notas (Hz) */
#define SOLS3 208
#define LA3   220
#define SI3   247
#define DO4   262
#define DOS4  277
#define RE4   294
#define MI4   330
#define FA4   349
#define FAS4  370
#define SOL4  392
#define SOLS4 415
#define LA4   440
#define SI4   494

/* Frequencia 0 representa silencio (pausa) */
#define PAUSA 0

/* Duracoes das notas (ms) */
#define CURTA 320
#define MEDIA 480
#define LONGA 720
#define FINAL 950

/* Pausas entre trechos da melodia (ms) */
#define PAUSA_ENTRE_FRASES   180
#define PAUSA_ENTRE_ESTROFES 500

/* Capacidade maxima da partitura (notas + pausas) */
#define MAX_NOTAS 256

/* Calcula a quantidade de elementos de um array estatico */
#define TAMANHO(vetor) ((int)(sizeof(vetor) / sizeof((vetor)[0])))

/* Uma nota: frequencia em Hz e duracao em ms */
typedef struct {
    int frequencia;
    int duracaoMs;
} Nota;

/* Partitura completa: sequencia de notas e quantas ja foram gravadas */
typedef struct {
    Nota notas[MAX_NOTAS];
    int total;
} Partitura;

/* Assinatura de PlaySoundA, usada para carregar a funcao de winmm.dll sem flag de linker */
typedef BOOL (WINAPI *PlaySoundAFn)(LPCSTR, HMODULE, DWORD);

/* Escreve um inteiro de 16 bits em little-endian no buffer WAV */
static void escrever16(unsigned char *wav, size_t pos, uint16_t valor) {
    wav[pos]     = valor & 0xFF;
    wav[pos + 1] = (valor >> 8) & 0xFF;
}

/* Escreve um inteiro de 32 bits em little-endian no buffer WAV */
static void escrever32(unsigned char *wav, size_t pos, uint32_t valor) {
    wav[pos]     = valor & 0xFF;
    wav[pos + 1] = (valor >> 8) & 0xFF;
    wav[pos + 2] = (valor >> 16) & 0xFF;
    wav[pos + 3] = (valor >> 24) & 0xFF;
}

/* Adiciona uma nota (ou pausa) a partitura. Retorna 0 se a capacidade acabou */
static int adicionarNota(Partitura *partitura, int frequencia, int duracaoMs) {
    if (partitura->total >= MAX_NOTAS)
        return 0;

    partitura->notas[partitura->total].frequencia = frequencia;
    partitura->notas[partitura->total].duracaoMs = duracaoMs;
    partitura->total++;
    return 1;
}

/* Adiciona uma frase inteira, seguida da pausa curta entre frases */
static int adicionarFrase(Partitura *partitura, const Nota *notas, int quantidade) {
    int i;

    /* Copia cada nota da frase para a partitura */
    for (i = 0; i < quantidade; i++) {
        if (!adicionarNota(partitura, notas[i].frequencia, notas[i].duracaoMs))
            return 0;
    }

    /* Pausa curta ao final da frase */
    return adicionarNota(partitura, PAUSA, PAUSA_ENTRE_FRASES);
}

/* Adiciona uma pausa longa (separacao de estrofes) */
static int adicionarPausa(Partitura *partitura, int duracaoMs) {
    return adicionarNota(partitura, PAUSA, duracaoMs);
}

/* Monta a melodia completa do hino, na mesma ordem do codigo original.
   Retorna 0 se a partitura estourar a capacidade */
static int montarHino(Partitura *hino) {
    /* Primeira estrofe */
    static const Nota f1[] = {{FA4, MEDIA}, {MI4, MEDIA}, {DO4, LONGA}, {LA3, FINAL}, {LA3, FINAL}};
    static const Nota f2[] = {{LA3, CURTA}, {LA3, CURTA}, {SI3, CURTA}, {DO4, MEDIA}, {MI4, MEDIA}, {RE4, CURTA}, {DO4, CURTA}, {SI3, FINAL}};
    static const Nota f3[] = {{RE4, MEDIA}, {SI3, MEDIA}, {LA3, MEDIA}, {SOLS3, LONGA}, {SOLS3, FINAL}};
    static const Nota f4[] = {{SOLS3, CURTA}, {SOLS3, CURTA}, {LA3, CURTA}, {SI3, MEDIA}, {RE4, MEDIA}, {DO4, CURTA}, {SI3, CURTA}, {MI4, FINAL}};

    /* Segunda estrofe */
    static const Nota f5[] = {{MI4, MEDIA}, {RE4, CURTA}, {DOS4, CURTA}, {RE4, MEDIA}, {RE4, FINAL}};
    static const Nota f6[] = {{RE4, CURTA}, {RE4, CURTA}, {MI4, MEDIA}, {FA4, MEDIA}, {LA4, LONGA}, {FA4, MEDIA}, {SOLS4, CURTA}, {DO4, FINAL}};
    static const Nota f7[] = {{LA4, MEDIA}, {MI4, MEDIA}, {DO4, LONGA}, {SI3, MEDIA}, {SI3, FINAL}};
    static const Nota f8[] = {{RE4, MEDIA}, {MI4, MEDIA}, {FA4, LONGA}, {MI4, MEDIA}, {RE4, MEDIA}, {DO4, CURTA}, {SI3, CURTA}, {LA3, FINAL}};

    /* Refrao (as duas frases se repetem) */
    static const Nota refraoA[] = {{MI4, MEDIA}, {FAS4, MEDIA}, {SOLS4, MEDIA}, {LA4, MEDIA}, {SI4, MEDIA}, {DO4, MEDIA}, {RE4, LONGA}, {SI3, FINAL}};
    static const Nota refraoB[] = {{RE4, MEDIA}, {FA4, MEDIA}, {MI4, MEDIA}, {RE4, MEDIA}, {DO4, MEDIA}, {RE4, MEDIA}, {MI4, FINAL}};

    /* Encerramento */
    static const Nota f13[] = {{MI4, MEDIA}, {RE4, CURTA}, {DOS4, CURTA}, {RE4, MEDIA}, {RE4, FINAL}};
    static const Nota f14[] = {{RE4, MEDIA}, {DO4, MEDIA}, {SI3, LONGA}, {DO4, MEDIA}, {DO4, FINAL}};
    static const Nota f15[] = {{LA3, MEDIA}, {MI4, MEDIA}, {DO4, LONGA}, {SI3, FINAL}};
    static const Nota f16[] = {{SI3, MEDIA}, {DO4, MEDIA}, {RE4, MEDIA}, {MI4, LONGA}, {DO4, MEDIA}, {SI3, CURTA}, {SI3, MEDIA}, {LA3, FINAL}};

    /* A cadeia com && interrompe na primeira falha de capacidade */
    return adicionarFrase(hino, f1, TAMANHO(f1))
        && adicionarFrase(hino, f2, TAMANHO(f2))
        && adicionarFrase(hino, f3, TAMANHO(f3))
        && adicionarFrase(hino, f4, TAMANHO(f4))
        && adicionarPausa(hino, PAUSA_ENTRE_ESTROFES)

        && adicionarFrase(hino, f5, TAMANHO(f5))
        && adicionarFrase(hino, f6, TAMANHO(f6))
        && adicionarFrase(hino, f7, TAMANHO(f7))
        && adicionarFrase(hino, f8, TAMANHO(f8))
        && adicionarPausa(hino, PAUSA_ENTRE_ESTROFES)

        && adicionarFrase(hino, refraoA, TAMANHO(refraoA))
        && adicionarFrase(hino, refraoB, TAMANHO(refraoB))
        && adicionarFrase(hino, refraoA, TAMANHO(refraoA))
        && adicionarFrase(hino, refraoB, TAMANHO(refraoB))
        && adicionarPausa(hino, PAUSA_ENTRE_ESTROFES)

        && adicionarFrase(hino, f13, TAMANHO(f13))
        && adicionarFrase(hino, f14, TAMANHO(f14))
        && adicionarFrase(hino, f15, TAMANHO(f15))
        && adicionarFrase(hino, f16, TAMANHO(f16));
}

/* Conta quantas amostras a partitura inteira vai gerar */
static size_t contarAmostras(const Partitura *partitura) {
    size_t total = 0;
    int i;

    for (i = 0; i < partitura->total; i++)
        total += (size_t)TAXA_AMOSTRAGEM * partitura->notas[i].duracaoMs / 1000;

    return total;
}

/* Grava em "destino" as amostras PCM (16 bits, mono) de uma nota senoidal,
   com envelope de 8 ms no inicio e no fim para evitar estalos entre notas.
   Pausas (frequencia 0) ficam como silencio, pois o buffer ja vem zerado.
   Retorna quantas amostras foram gravadas */
static size_t gerarAmostrasNota(unsigned char *wav, size_t posInicial, Nota nota) {
    const double PI = 3.14159265358979323846;
    const int quantidade = TAXA_AMOSTRAGEM * nota.duracaoMs / 1000;
    const int envelope = TAXA_AMOSTRAGEM * 8 / 1000;
    int i;

    if (nota.frequencia != PAUSA) {
        for (i = 0; i < quantidade; i++) {
            /* Amplitude base com fade-in e fade-out */
            double amplitude = VOLUME;
            double onda;
            int16_t amostra;

            if (i < envelope)
                amplitude *= (double)i / envelope;
            if (i > quantidade - envelope)
                amplitude *= (double)(quantidade - i) / envelope;

            onda = sin(2.0 * PI * nota.frequencia * i / TAXA_AMOSTRAGEM);
            amostra = (int16_t)(onda * amplitude * 32767);

            escrever16(wav, posInicial + (size_t)i * 2, (uint16_t)amostra);
        }
    }

    return (size_t)quantidade;
}

/* Monta o arquivo WAV em memoria (cabecalho de 44 bytes + dados PCM).
   Retorna NULL se faltar memoria; o chamador deve liberar com free() */
static unsigned char *montarWav(const Partitura *partitura, size_t *tamanhoTotal) {
    const size_t amostras = contarAmostras(partitura);
    const uint32_t tamanhoDados = (uint32_t)(amostras * 2);
    unsigned char *wav = (unsigned char *)calloc(44 + (size_t)tamanhoDados, 1);
    size_t posicao = 44;
    int i;

    if (wav == NULL)
        return NULL;

    /* Cabecalho WAV */
    memcpy(&wav[0], "RIFF", 4);
    escrever32(wav, 4, 36 + tamanhoDados);
    memcpy(&wav[8], "WAVE", 4);
    memcpy(&wav[12], "fmt ", 4);
    escrever32(wav, 16, 16);                    /* tamanho do bloco fmt */
    escrever16(wav, 20, 1);                     /* formato PCM */
    escrever16(wav, 22, 1);                     /* mono */
    escrever32(wav, 24, TAXA_AMOSTRAGEM);       /* taxa de amostragem */
    escrever32(wav, 28, TAXA_AMOSTRAGEM * 2);   /* bytes por segundo */
    escrever16(wav, 32, 2);                     /* bytes por amostra */
    escrever16(wav, 34, 16);                    /* bits por amostra */
    memcpy(&wav[36], "data", 4);
    escrever32(wav, 40, tamanhoDados);

    /* Grava as notas em sequencia apos o cabecalho */
    for (i = 0; i < partitura->total; i++)
        posicao += gerarAmostrasNota(wav, posicao, partitura->notas[i]) * 2;

    *tamanhoTotal = 44 + (size_t)tamanhoDados;
    return wav;
}

/* Carrega PlaySoundA direto de winmm.dll em tempo de execucao.
   Evita o erro "undefined reference to __imp_PlaySoundA" sem precisar de -lwinmm */
static PlaySoundAFn carregarPlaySound(void) {
    HMODULE biblioteca = LoadLibraryA("winmm.dll");

    if (biblioteca == NULL)
        return NULL;

    return (PlaySoundAFn)GetProcAddress(biblioteca, "PlaySoundA");
}

int main(void) {
    Partitura hino;
    unsigned char *wav;
    size_t tamanhoWav = 0;
    PlaySoundAFn tocarSom;

    /* Obtem a funcao de audio do sistema; encerra com aviso se nao estiver disponivel */
    tocarSom = carregarPlaySound();
    if (tocarSom == NULL) {
        MessageBoxA(NULL, "Nao foi possivel carregar winmm.dll.", "Erro", MB_ICONERROR);
        return 1;
    }

    /* Monta a partitura; falha apenas se MAX_NOTAS for insuficiente */
    hino.total = 0;
    if (!montarHino(&hino)) {
        fprintf(stderr, "Partitura excede MAX_NOTAS (%d).\n", MAX_NOTAS);
        return 1;
    }

    /* Converte a partitura em um unico WAV em memoria */
    wav = montarWav(&hino, &tamanhoWav);
    if (wav == NULL) {
        fprintf(stderr, "Memoria insuficiente para gerar o audio.\n");
        return 1;
    }

    /* Toca o hino inteiro de uma vez; SND_SYNC bloqueia ate o fim */
    tocarSom((LPCSTR)wav, NULL, SND_MEMORY | SND_SYNC);

    /* Libera o buffer somente apos o fim da reproducao */
    free(wav);
    return 0;
}
