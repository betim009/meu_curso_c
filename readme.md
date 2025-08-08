# Apostila de Programação em C

## Sumário
- [Introdução à Linguagem C](#introducao)
- [Variáveis e Tipos de Dados](#variaveis)
- [Entrada e Saída de Dados](#entrada-saida)
- [Operadores](#operadores)
- [Estruturas de Controle](#controle)
- [Funções](#funcoes)
- [Arrays](#arrays)
- [Strings](#strings)
- [Ponteiros](#ponteiros)
- [Constantes](#constantes)
- [Structs](#structs)
- [Exercícios Práticos](#exercicios)
- [Dicas e Comparações](#dicas)

---

## <a name="introducao"></a>Introdução à Linguagem C
C é uma linguagem de programação de baixo nível, muito utilizada para sistemas operacionais, embarcados, jogos e sistemas que exigem alto desempenho. Ela é compilada, ou seja, precisa ser transformada em código de máquina antes de rodar.

Exemplo mínimo:
```c
#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}
```

---


```bash
gcc arquivo.c -o nome_do_executavel

./nome_do_executavel
```

## <a name="variaveis"></a>Variáveis e Tipos de Dados
- Em C, você precisa declarar o tipo da variável: `int`, `float`, `char`, `double`, `char[]` (string).
- O ponto e vírgula `;` é sempre obrigatório.

Exemplo:
```c
int idade = 30;
float altura = 1.75;
char letra = 'Z';
char nome[20] = "Alberto";
```

---

## <a name="entrada-saida"></a>Entrada e Saída de Dados
- Use `printf` para exibir dados.
- Use `scanf` para ler dados do usuário.

Exemplo:
```c
#include <stdio.h>
int main() {
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Idade digitada: %d\n", idade);
    return 0;
}
```

Para ler strings/frases completas:
```c
fgets(nome, sizeof(nome), stdin);
```

---

## <a name="operadores"></a>Operadores
- Aritméticos: `+`, `-`, `*`, `/`, `%`
- Relacionais: `==`, `!=`, `>`, `<`, `>=`, `<=`
- Lógicos: `&&`, `||`, `!`

---

## <a name="controle"></a>Estruturas de Controle
### Condicionais
```c
if (idade >= 18) {
    printf("Maior de idade\n");
} else {
    printf("Menor de idade\n");
}
```

### Switch
```c
int opcao = 2;
switch (opcao) {
    case 1:
        printf("Opção 1\n");
        break;
    case 2:
        printf("Opção 2\n");
        break;
    default:
        printf("Opção inválida\n");
}
```

### Repetição
```c
for (int i = 0; i < 5; i++) {
    printf("i = %d\n", i);
}
```

---

## <a name="funcoes"></a>Funções
### Sem retorno
```c
void saudacao() {
    printf("Bem-vindo!\n");
}
```
### Com retorno
```c
int soma(int a, int b) {
    return a + b;
}
```

---

## <a name="arrays"></a>Arrays
```c
int numeros[5] = {1, 2, 3, 4, 5};
```
Percorra com for:
```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", numeros[i]);
}
```

---

## <a name="strings"></a>Strings
```c
char nome[20];
printf("Digite seu nome: ");
scanf("%s", nome);
printf("Olá, %s!\n", nome);
```
Para frases completas:
```c
fgets(nome, 20, stdin);
```

---

## <a name="ponteiros"></a>Ponteiros
- Ponteiro é uma variável que guarda o endereço de outra variável.
- Use `*` para declarar e acessar o valor apontado.

Exemplo básico:
```c
int idade = 25;
int *p = &idade;
printf("Valor da idade: %d\n", idade);
printf("Endereço de idade: %p\n", (void*)&idade);
printf("Valor via ponteiro: %d\n", *p);
printf("Endereço guardado em p: %p\n", (void*)p);
```

### Passando endereço para função
```c
void dobrar(int *num) {
    *num = *num * 2;
}
int main() {
    int valor = 7;
    dobrar(&valor);
    printf("Valor dobrado: %d\n", valor); // 14
    return 0;
}
```

### Quando usar ponteiros?
- Para alterar uma variável fora da função
- Evitar copiar dados grandes
- Trabalhar com alocação dinâmica
- Manipular arrays, strings ou structs

---

## <a name="constantes"></a>Constantes
```c
#define PI 3.14
const int ANO = 2025;
```
- `#define` substitui texto (pré-processador)
- `const` impede alteração do valor

---

## <a name="structs"></a>Structs
```c
struct Pessoa {
    char nome[50];
    int idade;
};
struct Pessoa p1 = {"Ana", 30};
printf("%s tem %d anos\n", p1.nome, p1.idade);
```

---

## <a name="exercicios"></a>Exercícios Práticos
### 1. Encontrar o maior número em um array
```c
#include <stdio.h>
int main() {
    int array[5] = {7, 3, 12, 5, 9};
    int maior = array[0];
    for (int i = 1; i < 5; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    printf("Maior número: %d\n", maior);
    return 0;
}
```

### 2. Função para encontrar o maior número
```c
int encontrarMaior(int array[], int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}
```

### 3. Trocar valores usando ponteiros
```c
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### 4. Dobrar valor usando ponteiro
```c
void dobrar(int *p) {
    *p = *p * 2;
}
```

### 5. Exibir dados usando ponteiros
```c
void exibindo(const char *pNome, int *pIdade) {
    printf("%s tem %d anos de idade.\n", pNome, *pIdade);
}
```

---

## <a name="dicas"></a>Dicas e Comparações
- Use ponteiros para modificar valores fora da função.
- Prefira `const` para valores que não devem ser alterados.
- Arrays e strings são passados como ponteiros para funções.
- Em C, tudo que envolve manipulação direta de memória é feito com ponteiros.
- Para quem vem de JavaScript: C exige declaração de tipo, uso de ponteiros e manipulação manual de memória.

---

