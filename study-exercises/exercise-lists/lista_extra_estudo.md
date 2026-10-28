# Lista Extra de Exercícios
### Linguagem de Programação — Material de apoio para estudo pessoal

Exercícios elaborados com o mesmo nível de dificuldade das listas 3 e 4 da disciplina, cobrindo passagem de vetores e matrizes como parâmetro de função, encadeamento de funções, manipulação de vetores do tipo `char` e lógica estrutural sobre matrizes.

---

## 1) Encadeamento de funções com vetor de dados reais

Escreva um programa que leia 7 valores reais representando as temperaturas registradas ao longo de um dia, dentro de uma função chamada **`lerTemperaturas( )`**. Em seguida, passe esse vetor como parâmetro para uma função chamada **`calcularAmplitudeTermica( )`**, que deverá identificar a maior e a menor temperatura do vetor e retornar a diferença entre elas (amplitude). Por fim, o valor retornado deve ser passado para uma terceira função, **`classificarClima( )`**, que deverá exibir uma das mensagens abaixo, conforme o valor da amplitude:

- Amplitude até 5.0 → `"Clima estável"`
- Amplitude entre 5.1 e 10.0 → `"Clima variável"`
- Amplitude acima de 10.0 → `"Clima instável"`

> **Obs:** o valor da amplitude deve ser exibido junto com a mensagem, arredondado para uma casa decimal.

---

## 2) Manipulação de vetor do tipo `char`

Desenvolva um programa em que seja possível passar duas palavras (dois vetores de `char`) para uma função chamada **`saoAnagramas( )`**, que deverá verificar se a segunda palavra é um anagrama da primeira, ou seja, se é formada exatamente pelas mesmas letras, em qualquer ordem, sem letras a mais ou a menos. A função deve retornar um valor inteiro (1 para verdadeiro, 0 para falso) para a `main( )`, que será responsável por exibir a mensagem final ao usuário.

**Exemplo:**
```
Entrada 1: "amor"    Entrada 2: "roma"  → Saída: "São anagramas"
Entrada 1: "livro"   Entrada 2: "lobo"  → Saída: "Não são anagramas"
```

> **Obs:** desconsidere diferenças entre maiúsculas e minúsculas, mas não utilize nenhuma função pronta de ordenação de string da biblioteca padrão — a comparação deve ser feita por contagem de ocorrências de cada letra.

---

## 3) Construção de um novo vetor a partir de dois vetores de entrada

Crie uma função chamada **`gerarCodigoProduto( )`** que recebe dois vetores como parâmetro: um vetor de `char` contendo o prefixo do produto (3 letras) e um vetor de inteiros contendo 3 dígitos numéricos. Essa função deve intercalar os elementos dos dois vetores, alternando uma letra e um dígito, formando um novo vetor de `char` (o código final do produto). Esse novo vetor deve ser passado para uma outra função, chamada **`exibirCodigo( )`**, responsável apenas por imprimi-lo na tela.

**Exemplo:**
```
Entrada "prefixo": MSE      Entrada "digitos": 7 2 9
Saída do vetor "codigo":    M7S2E9
```

> **Obs:** a função `gerarCodigoProduto` não deve imprimir nada, apenas montar e retornar (ou preencher por referência) o vetor resultante — toda a exibição fica a cargo de `exibirCodigo`.

---

## 4) Matriz como parâmetro de função — comparação de regiões

Escreva um programa que faça a carga de uma matriz quadrada de ordem 4, com elementos fornecidos pelo usuário, e que essa estrutura seja passada como parâmetro para uma função chamada **`compararRegioes( )`**. Essa função deve calcular separadamente a soma dos elementos que compõem a **borda** da matriz (primeira e última linha, primeira e última coluna) e a soma dos elementos que compõem o **centro** da matriz (os elementos internos, que não pertencem à borda), apontando qual das duas regiões possui a maior soma.

**Exemplo (ordem 4):**

| 2 | 9 | 4 | 1 |
|---|---|---|---|
| 7 | **5** | **3** | 8 |
| 6 | **1** | **8** | 2 |
| 3 | 4 | 7 | 9 |

> **Obs 1:** na matriz acima, os elementos em **negrito** representam o centro; os demais compõem a borda.
>
> **Obs 2:** a mensagem final deve informar o valor de cada soma e qual região prevalece, no formato `"Região [borda/centro] possui a maior soma, com valor XX"`.

---

## 5) (Desafio) Verificação estrutural de matriz triangular superior

Engendre uma solução em código C para analisar uma matriz quadrada de ordem escolhida pelo usuário, que aponte se ela é ou não uma **Matriz Triangular Superior**, ou seja, se todos os elementos posicionados abaixo da diagonal principal são iguais a zero, independentemente dos valores acima ou sobre a diagonal.

**Exemplo:**

| 4 | 8 | 1 |
|---|---|---|
| 0 | 5 | 3 |
| 0 | 0 | 7 |

> **Obs 1:** na matriz exemplo acima, todos os elementos abaixo da diagonal principal são zero, portanto ela é classificada como Triangular Superior.
>
> **Obs 2:** os dados devem ser inseridos por meio de uma função chamada **`carregarMatriz( )`** e a análise estrutural deve ser feita em uma outra função, chamada **`verificarTriangularSuperior( )`**, que deverá receber a matriz como parâmetro.
>
> **Obs 3:** o programa deve funcionar corretamente para qualquer ordem escolhida pelo usuário (não fixar a ordem em tempo de compilação).

---

*Sugestão de uso: implemente cada exercício isoladamente, compile e teste com valores diferentes dos exemplos antes de considerar a questão concluída.*
