# Lista de Estudo para a Prova
### Linguagem de Programação em C — 10 exercícios inéditos

Os enunciados cobrem os assuntos já trabalhados no repositório `c_exercises`: funções, passagem de parâmetros por valor e por referência, ponteiros, vetores e matrizes em funções, vetores de `char`, recursão direta e indireta, manipulação de arquivos texto e som/cor no console. Nenhum enunciado repete os exercícios já resolvidos nem os cinco da `lista_extra_estudo.md`.

| # | Assunto | Nível | Revisar no repositório |
|---|---------|-------|------------------------|
| 1 | Vetores e encadeamento de funções | Básico | `arrays-in-functions`, `study-exercises` |
| 2 | Ponteiros e passagem por referência (com ponteiro para ponteiro) | Intermediário / Desafio | `parameter-passing-by-value-and-by-reference`, `exercises/challenge` |
| 3 | Vetor de `char` e tabela ASCII | Intermediário | `exercises/verificaPalindromo.c`, `exercises/criptografiaDados.c` |
| 4 | Matriz quadrada em funções | Intermediário | `matrix-in-functions` |
| 5 | Matriz retangular e vetores de resultado | Intermediário | `matrix-in-functions`, `arrays-in-functions` |
| 6 | Recursão direta | Intermediário | `introduction-to-recursion`, `logic-reinforcement` |
| 7 | Recursão indireta | Intermediário | `indirect-recursion` |
| 8 | Arquivos texto | Intermediário | `manipulating-files` |
| 9 | Som e cor no console (Windows) | Básico | `sounds-and-colors` |
| 10 | (Desafio) Lógica estrutural sobre matriz | Desafio | `exercises/quadradoMagico.c`, `exercises/determinarMaiorConjunto.c` |

---

## 1) Vetores e encadeamento de funções — pesquisa de satisfação

Uma empresa de entregas coletou 10 avaliações de clientes, cada uma com uma nota inteira de 1 a 5. Escreva um programa que, dentro de uma função chamada **`lerAvaliacoes( )`**, carregue um vetor com as 10 notas, repetindo a leitura sempre que a nota digitada estiver fora do intervalo permitido. Em seguida, passe esse vetor para a função **`contarNotas( )`**, que deverá preencher um segundo vetor de 5 posições (recebido como parâmetro, sem retorno) em que a posição `i` guarda quantas vezes a nota `i + 1` foi dada. Por fim, o vetor de contagem deve ser passado para **`exibirResumo( )`**, que mostrará:

- um histograma horizontal, com um `#` para cada ocorrência de cada nota;
- a nota mais frequente (em caso de empate, vale a maior nota);
- a média das avaliações, com uma casa decimal, e a classificação geral:
  - média a partir de 4.5 → `"Excelente"`
  - média a partir de 3.5 → `"Bom"`
  - média a partir de 2.5 → `"Regular"`
  - abaixo disso → `"Crítico"`

**Exemplo:**
```
Entrada: 5 4 4 5 3 5 2 4 5 1

Nota 1 | #     (1)
Nota 2 | #     (1)
Nota 3 | #     (1)
Nota 4 | ###   (3)
Nota 5 | ####  (4)

Nota mais frequente: 5
Média: 3.8 - Bom
```

> **Obs:** a média deve ser calculada a partir do vetor de contagem, e não do vetor original. O histograma deve ser desenhado com laços, sem um `printf` para cada nota.

---

## 2) Ponteiros e passagem por referência — voltas de um piloto

**a)** Um cronômetro registrou o tempo, em segundos (inteiros), de 8 voltas de um piloto. Carregue os tempos em um vetor na `main( )` e passe-o para a função **`analisarVoltas( )`**, do tipo `void`, que deverá devolver **exclusivamente por ponteiros**: o melhor tempo (o menor), o pior tempo (o maior), o número da volta (de 1 a 8) em que ocorreu o melhor tempo e a média dos tempos. A `main( )` exibe os quatro resultados.

**b) (Desafio)** Crie a função **`apontarMelhorVolta( )`**, que receba o vetor, o seu tamanho e um ponteiro para ponteiro (`int **`), fazendo com que um ponteiro declarado na `main( )` passe a apontar para o elemento de menor tempo dentro do vetor. De posse desse ponteiro, a `main( )` deverá:

1. exibir o valor apontado e o seu endereço de memória (`%p`);
2. descobrir a posição do elemento no vetor por aritmética de ponteiros (diferença entre o endereço do elemento e o endereço do início do vetor);
3. somar 5 segundos de penalidade ao melhor tempo diretamente pelo ponteiro, sem usar índice, e exibir o vetor novamente.

**Exemplo:**
```
Entrada:  92 88 95 87 91 90 89 94

Melhor tempo: 87 (volta 4)
Pior tempo: 95
Média: 90.75

Valor apontado: 87 | Posição no vetor: 3
Vetor após a penalidade: 92 88 95 92 91 90 89 94
```

> **Obs:** o endereço exibido varia a cada execução; a posição, não.

---

## 3) Vetor de `char` e tabela ASCII — cifra de deslocamento

Escreva um programa que leia uma frase (com espaços) e um deslocamento inteiro entre 1 e 25. Crie a função **`cifrar( )`**, que recebe o vetor de `char` e o deslocamento e altera o **próprio vetor**, deslocando cada letra para frente no alfabeto, com retorno circular (depois do `z` vem o `a`). Maiúsculas continuam maiúsculas, minúsculas continuam minúsculas, e espaços, dígitos e pontuação permanecem inalterados. A função deve retornar a quantidade de letras alteradas.

Crie também a função **`decifrar( )`**, que restaura o texto original reaproveitando a `cifrar( )` (sem duplicar a lógica). A `main( )` deve exibir a frase original, a frase cifrada com a quantidade de letras alteradas e a frase decifrada.

**Exemplo:**
```
Frase: Prova de C, 25/11!
Deslocamento: 3

Original: Prova de C, 25/11!
Cifrada: Surya gh F, 25/11!  (8 letras alteradas)
Decifrada: Prova de C, 25/11!
```

> **Obs:** não utilize `string.h` nem `ctype.h`. A identificação de letras deve ser feita comparando os caracteres com `'a'`, `'z'`, `'A'` e `'Z'`.

---

## 4) Matriz quadrada em funções — transposta e simetria

Escreva um programa que carregue, por meio da função **`carregarMatriz( )`**, uma matriz quadrada de ordem 4 com valores inteiros fornecidos pelo usuário. Crie a função **`gerarTransposta( )`**, que recebe a matriz original e uma matriz de destino e a preenche com a transposta (as linhas viram colunas), sem retorno. Crie ainda a função **`ehSimetrica( )`**, que recebe a matriz e retorna 1 se ela for igual à sua transposta (ou seja, `mat[i][j] == mat[j][i]` para todos os elementos) e 0 caso contrário.

A `main( )` exibe a matriz original, a transposta e a mensagem final informando se a matriz é ou não simétrica.

**Exemplo:**
```
Original:        Transposta:
1 2 3 4          1 5 9 4
5 6 7 8          2 6 1 5
9 1 2 3          3 7 2 6
4 5 6 7          4 8 3 7

A matriz NAO eh simetrica.
```

> **Obs 1:** a função `ehSimetrica( )` deve percorrer apenas os elementos acima da diagonal principal e encerrar a análise assim que encontrar a primeira diferença.
>
> **Obs 2:** a exibição das matrizes fica a cargo de uma função separada, chamada **`exibirMatriz( )`**.

---

## 5) Matriz retangular e vetores de resultado — boletim da turma

Uma turma tem 4 alunos e cada um fez 3 provas. Escreva um programa que carregue, na função **`carregarNotas( )`**, uma matriz `notas[4][3]` do tipo `float`, aceitando apenas valores entre 0 e 10 (repita a leitura se o valor for inválido). Em seguida:

- **`calcularMediasAlunos( )`** recebe a matriz e um vetor de 4 posições, e o preenche com a média de cada aluno (média de cada linha);
- **`calcularMediasProvas( )`** recebe a matriz e um vetor de 3 posições, e o preenche com a média de cada prova (média de cada coluna);
- **`exibirBoletim( )`** recebe a matriz e os dois vetores e mostra a nota de cada aluno, sua média e sua situação (média a partir de 6.0 → `Aprovado`; a partir de 4.0 → `Exame`; abaixo disso → `Reprovado`). Ao final, deve apontar o **melhor aluno** (maior média) e a **prova mais difícil** (menor média entre as provas).

**Exemplo:**
```
         P1    P2    P3   Média   Situação
Aluno 1  7.0   8.0   9.0  8.00    Aprovado
Aluno 2  4.0   5.0   6.0  5.00    Exame
Aluno 3  10.0  9.0   8.0  9.00    Aprovado
Aluno 4  3.0   1.0   4.0  2.67    Reprovado

Média das provas: P1 = 6.00 | P2 = 5.75 | P3 = 6.75
Melhor aluno: Aluno 3
Prova mais difícil: P2
```

> **Obs:** a matriz não é quadrada, então o número de colunas precisa constar no parâmetro das funções.

---

## 6) Recursão direta — três funções, sem laços e sem variáveis globais

Escreva um programa com as três funções recursivas abaixo. Nenhuma delas pode usar laços (`for`, `while`) nem variáveis globais: todo o estado deve trafegar por parâmetros e retornos.

- **`somaDigitos(int n)`**: retorna a soma dos algarismos de um inteiro positivo.
- **`imprimirBinario(int n)`**: imprime na tela a representação binária de um inteiro positivo, sem armazená-la em vetor.
- **`tribonacci(int n)`**: retorna o n-ésimo termo da sequência em que `T(0) = 0`, `T(1) = 1`, `T(2) = 1` e, para `n >= 3`, `T(n) = T(n-1) + T(n-2) + T(n-3)`.

A `main( )` lê os valores necessários, chama as três funções e exibe os resultados. Para a sequência, ela deve mostrar os termos de `T(0)` a `T(7)` (aqui sim, um laço na `main( )` é permitido).

**Exemplo:**
```
Soma dos dígitos de 4827: 21
37 em binário: 100101
Tribonacci (T0 a T7): 0 1 1 2 4 7 13 24
```

> **Obs:** pense em qual é o caso base de cada função antes de escrever o código, e em qual momento a impressão acontece em `imprimirBinario( )` (na ida ou na volta da recursão).

---

## 7) Recursão indireta — caixa de padaria

Simule o caixa de uma padaria usando **recursão indireta** entre duas funções:

- **`lerPreco( )`** solicita o preço de um item e o envia para `registrarItem( )`;
- **`registrarItem( )`** soma o preço ao total da compra e à contagem de itens e, se o preço digitado for diferente de zero, volta a chamar `lerPreco( )`. Se o preço for 0 (sinal de fim da compra), ela encerra o ciclo e exibe o fechamento.

O total acumulado e a quantidade de itens não podem ser variáveis globais: devem ser passados de uma função para a outra como parâmetros. No fechamento, exiba a quantidade de itens, o total bruto, o desconto de 5% (aplicado apenas quando o total bruto for superior a R$ 50,00), o total a pagar e o valor médio por item. Se nenhum item for registrado, exiba apenas `"Nenhum item registrado."`.

**Exemplo:**
```
Preço do item (0 para encerrar): 12.00
Preço do item (0 para encerrar): 8.00
Preço do item (0 para encerrar): 40.00
Preço do item (0 para encerrar): 0

Itens: 3
Total bruto: R$ 60.00
Desconto (5%): R$ 3.00
Total a pagar: R$ 57.00
Média por item: R$ 20.00
```

> **Obs:** o laço de repetição do programa deve existir apenas por causa das chamadas entre as duas funções; não use `for` nem `while`.

---

## 8) Arquivos texto — diário formatado

Crie, na mesma pasta do executável, um arquivo chamado `diario.txt` com pelo menos 4 linhas de texto. Escreva um programa que:

1. abra `diario.txt` em modo leitura e valide a abertura com `perror( )`, encerrando o programa em caso de falha;
2. leia o arquivo linha a linha com `fgets( )`;
3. grave em `diario_formatado.txt` (modo escrita) cada linha numerada no formato `001 | TEXTO`, com todas as letras convertidas para maiúsculas, caractere por caractere, usando `fputc( )`;
4. ao final, reabra `diario_formatado.txt` em modo anexar e acrescente um rodapé com o total de linhas e o total de caracteres lidos, sem contar o `'\n'`;
5. feche todos os arquivos abertos.

A conversão de cada linha deve estar em uma função chamada **`converterLinha( )`**, que recebe a linha, o arquivo de saída e o número da linha. O rodapé deve ser gravado por uma segunda função, **`gravarRodape( )`**.

**Exemplo:**
```
diario.txt:
Hoje estudei ponteiros.
Amanha tem prova!

diario_formatado.txt:
001 | HOJE ESTUDEI PONTEIROS.
002 | AMANHA TEM PROVA!
--- Total de linhas: 2 | Total de caracteres: 40
```

> **Obs 1:** não use `toupper( )`. A conversão deve ser feita com a tabela ASCII (a diferença entre uma letra minúscula e sua maiúscula é constante).
>
> **Obs 2:** o `fgets( )` mantém o `'\n'` no final do vetor, e a última linha do arquivo pode não ter esse caractere. O programa precisa funcionar nos dois casos.

---

## 9) Som e cor no console (Windows) — mini piano

Utilizando `windows.h` e `conio.h`, escreva um programa que transforme as teclas de `1` a `8` em um mini piano:

| Tecla | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|-------|---|---|---|---|---|---|---|---|
| Nota | DO | RE | MI | FA | SOL | LA | SI | DO |
| Frequência (Hz) | 262 | 294 | 330 | 349 | 392 | 440 | 494 | 523 |

Guarde as frequências em um vetor e use **`getch( )`** para ler cada tecla sem precisar do Enter. A cada tecla válida:

- a função **`tocarNota( )`** deve emitir o som com `Beep( )`, com duração de 300 ms;
- a função **`exibirNota( )`** deve mostrar o nome da nota (use `switch`) com uma cor diferente para cada nota, definida por uma função **`definirCor( )`** que utilize `SetConsoleTextAttribute( )`. Dica: a cor `9 + (indice % 7)` faz o DO agudo repetir a cor do DO grave.

Qualquer outra tecla deve emitir um som grave (150 Hz, 100 ms) e a mensagem `"Tecla invalida"` em vermelho. A tecla **ESC** (código ASCII 27) encerra o programa, que deve restaurar a cor padrão (7) e mostrar a quantidade de notas válidas tocadas.

**Exemplo:**
```
Teclas pressionadas: 1 3 5 x ESC

DO
MI
SOL
Tecla invalida

Notas validas tocadas: 3
```

> **Obs:** a cor padrão do console deve ser restaurada antes de encerrar, mesmo que o último texto exibido tenha sido colorido.

---

## 10) (Desafio) Lógica estrutural sobre matriz — cartela de bingo

Engendre uma solução em C para simular uma cartela de bingo. A cartela é uma matriz quadrada de ordem 5 com números inteiros distintos entre 1 e 75, carregada na função **`carregarCartela( )`**. Em seguida, o programa deve ler os números sorteados, um a um, até que ocorra um BINGO ou até que o usuário digite 0 para desistir.

A cada número sorteado:

- **`marcarNumero( )`** recebe a cartela e o número, marca o número encontrado trocando seu valor por `-1` e retorna 1 se a marcação foi feita, ou 0 se o número não está na cartela (ou já estava marcado);
- a cartela é exibida, mostrando `XX` nas posições marcadas;
- há **BINGO** quando existir ao menos uma linha, coluna ou diagonal inteiramente marcada. Essa verificação deve ser feita por três funções independentes: **`contarLinhasCompletas( )`**, **`contarColunasCompletas( )`** e **`contarDiagonaisCompletas( )`**, cada uma retornando a quantidade encontrada.

Ao final, o programa informa quantas linhas, colunas e diagonais foram completadas.

**Exemplo:**
```
Cartela:
 5  12  33  47  61
 8  19  28  52  70
 3  14   1  41  66
 9  22  37  55  73
 2  25  31  49  75

Sorteados: 5 19 1 55 75

BINGO! Linhas: 0 | Colunas: 0 | Diagonais: 1
```

> **Obs 1:** números sorteados fora do intervalo de 1 a 75 devem ser recusados, e a leitura repetida.
>
> **Obs 2:** o programa deve funcionar mesmo quando uma única marcação completa mais de uma linha, coluna ou diagonal ao mesmo tempo.

---

*Sugestão de uso: implemente cada exercício isoladamente, compile e teste com valores diferentes dos exemplos antes de considerar a questão concluída. Nos exercícios 6 e 7, vale conferir à mão o que cada chamada recursiva devolve antes de executar o programa.*