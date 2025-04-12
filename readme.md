# Capítulo 1: Fundamentos da Linguagem C

## 🔥 Introdução

C é uma linguagem de programação de **baixo nível**, muito utilizada para sistemas operacionais, embarcados, jogos e sistemas que exigem alto desempenho. Ela é **compilada**, ou seja, precisa ser transformada em código de máquina antes de rodar.

---

## ✅ Estrutura Básica de um Programa em C

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

- `#include <stdio.h>`: importa biblioteca padrão de entrada e saída.
- `main()`: ponto de entrada do programa.
- `printf()`: imprime na tela.
- `return 0;`: indica fim do programa com sucesso.

---

## ⚖️ Tipos de Dados e Variáveis

```c
int idade = 25;
float altura = 1.75;
double peso = 70.5;
char letra = 'A';
```

- `%d`: int
- `%f`: float
- `%lf`: double
- `%c`: char

```c
printf("Idade: %d\n", idade);
```

---

## ✉️ Entrada de Dados com `scanf`

```c
int idade;
printf("Digite sua idade: ");
scanf("%d", &idade);
printf("Idade digitada: %d\n", idade);
```

- Sempre usar `&` antes da variável no `scanf`.

---

## ⚡️ Operadores

### Aritméticos

```c
+, -, *, /, %
```

### Relacionais

```c
==, !=, >, <, >=, <=
```

### Lógicos

```c
&& (E), || (OU), ! (NÃO)
```

---

## Condicionais

### `if`, `else if`, `else`

```c
if (idade >= 18) {
    printf("Maior de idade\n");
} else {
    printf("Menor de idade\n");
}
```

### `switch`

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

---

## ♻️ Repetições

### `for`

```c
for (int i = 0; i < 5; i++) {
    printf("i = %d\n", i);
}
```

### `while`

```c
int i = 0;
while (i < 5) {
    printf("i = %d\n", i);
    i++;
}
```

---

## ⚙️ Funções

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

## 📂 Arrays

### Array de inteiros

```c
int numeros[5] = {1, 2, 3, 4, 5};
```

### Array 2D (matriz)

```c
int matriz[2][2] = {{1, 2}, {3, 4}};
```

---

## 🔎 Strings

```c
char nome[20];
printf("Digite seu nome: ");
scanf("%s", nome);
printf("Olá, %s!\n", nome);
```

- Para ler frases completas, use:

```c
fgets(nome, 20, stdin);
```

---

## 🤍 Ponteiros

```c
int x = 10;
int *p = &x;
printf("Valor de x: %d\n", *p);
```

- `*p`: acessa valor apontado
- `&x`: pega endereço de x

---

## 📚 Structs (Registros)

```c
struct Pessoa {
    char nome[50];
    int idade;
};

struct Pessoa p1 = {"Ana", 30};
printf("%s tem %d anos\n", p1.nome, p1.idade);
```

---

## 📌 Comentários

- Comentário de linha:

```c
// Isso é um comentário
```

- Comentário de bloco:

```c
/* Comentário
   em várias linhas */
```

---

## 🔢 Exercícios Práticos

1. Crie um programa que leia dois números e mostre a soma.
2. Crie um programa que leia o nome e a idade e imprima-os.
3. Crie uma função que receba dois inteiros e retorne a média.
4. Crie um programa que leia 5 notas e calcule a média.

---


### 2️⃣ Estrutura Básica de um Programa em C
```c
#include <stdio.h>  // Biblioteca padrão para entrada e saída

int main() {  // Ponto de entrada do programa
    printf("Hello, world!\n");  // Imprime na tela
    return 0;  // Indica que o programa rodou sem erros
}
```

📌 O `#include <stdio.h>` importa uma biblioteca para lidar com entrada/saída.  
📌 `main()` é a função principal, **todo programa em C começa nela**.  
📌 `printf()` é usado para imprimir coisas na tela.  
📌 `\n` quebra a linha.

🛠 **Compilação e execução:**  
Se estiver no Linux/macOS, compile com `gcc`:
```sh
gcc programa.c -o programa
./programa
```
No Windows, use o **MinGW** ou rode no **WSL**.

---- 

### 3️⃣ Variáveis e Tipos de Dados
```c
#include <stdio.h>

int main() {
    int idade = 25;
    float altura = 1.75;
    double peso = 70.5;
    char inicial = 'A';

    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);
    printf("Peso: %.1lf kg\n", peso);
    printf("Inicial do nome: %c\n", inicial);

    return 0;
}
```

📌 `%d` para **inteiro**, `%f` para **float**, `%lf` para **double**, `%c` para **char**.  
📌 **Float e double precisam de `.` para números decimais.**  
📌 `char` usa **aspas simples ('A')**, strings usam **aspas duplas ("Hello")**.

---

### 4️⃣ Entrada de Dados (`scanf`)
```c
#include <stdio.h>

int main() {
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Sua idade é %d anos.\n", idade);
    return 0;
}
```

📌 `scanf("%d", &idade);` lê um **inteiro** do usuário.  
📌 **Atenção:** O `&` antes da variável é obrigatório!

---

### 5️⃣ Condicionais (`if`, `else`)
```c
#include <stdio.h>

int main() {
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18) {
        printf("Você é maior de idade.\n");
    } else {
        printf("Você é menor de idade.\n");
    }

    return 0;
}
```

---

### 6️⃣ Laços de Repetição (`for`, `while`)

#### 🔹 `for` (contador)
```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        printf("Número %d\n", i);
    }
    return 0;
}
```

#### 🔹 `while`
```c
#include <stdio.h>

int main() {
    int numero = 1;
    while (numero <= 5) {
        printf("Número %d\n", numero);
        numero++;
    }
    return 0;
}
```

---

### 7️⃣ Funções

#### 🔹 Sem retorno (`void`)
```c
#include <stdio.h>

void saudacao() {
    printf("Olá, bem-vindo!\n");
}

int main() {
    saudacao();
    return 0;
}
```

#### 🔹 Com retorno
```c
#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado = soma(3, 4);
    printf("Resultado: %d\n", resultado);
    return 0;
}
```

---

### 8️⃣ Strings em C (Array de `char`)
```c
#include <stdio.h>

int main() {
    char nome[20];
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Olá, %s!\n", nome);
    return 0;
}
```

#### Para ler frases completas:
```c
fgets(nome, 20, stdin);
```

---

### 9️⃣ Ponteiros
```c
#include <stdio.h>

int main() {
    int numero = 10;
    int *ptr = &numero;

    printf("Valor de numero: %d\n", numero);
    printf("Endereço de numero: %p\n", &numero);
    printf("Valor armazenado em ptr: %p\n", ptr);
    printf("Valor apontado por ptr: %d\n", *ptr);

    return 0;
}
```


# Aprendendo C com Comparações em JavaScript

Este guia foi feito para quem já domina JavaScript e quer aprender a linguagem C de forma simples, prática e comparativa.

---

## 1. Hello World

### JavaScript:
```js
function hello(name) {
  return `Hello ${name}`;
}

console.log(hello("Alberto"));
```

### C:
```c
#include <stdio.h>

void hello(const char *name) {
    printf("Hello %s\n", name);
}

int main() {
    hello("Alberto");
    return 0;
}
```

---

# Introdução a Strings em C

## 1. Variáveis em C

Diferente de JavaScript, onde não precisamos declarar o tipo das variáveis, em C é necessário especificar o tipo.

### Exemplo de variáveis em C:

```c
int numero = 10;    // Número inteiro
float altura = 1.75; // Número decimal
char letra = 'A';   // Um caractere único
```

## 2. Strings em C

Em JavaScript, strings são tipos nativos, mas em C, strings são **arrays de caracteres**.

### Exemplo de string em C:

```c
char nome[50] = "Alberto";  // String com até 50 caracteres
```

Isso cria um array de caracteres onde cada letra é armazenada separadamente na memória.

### Representação interna:

```c
char nome[] = {'A', 'l', 'b', 'e', 'r', 't', 'o', '\0'};
```

O `\0` indica o final da string.

## 3. `%s` para Manipulação de Strings

O **`%s`** é um especificador de formato usado em funções como `printf()` e `scanf()` para manipular strings.

### Exemplo de Impressão de String:

```c
#include <stdio.h>

int main() {
    char nome[] = "Alberto";
    printf("Olá, %s!\n", nome);  // %s substitui "Alberto"
    return 0;
}
```

**Saída:**

```
Olá, Alberto!
```

### Exemplo de Leitura de String com `scanf()`:

```c
#include <stdio.h>

int main() {
    char nome[50];
    printf("Digite seu nome: ");
    scanf("%49s", nome);  // Lê a string
    printf("Olá, %s!\n", nome);
    return 0;
}
```

⚠️ **Limitação**: `scanf("%s")`**só lê até o primeiro espaço**! Para ler nomes completos, use `fgets()`:

```c
fgets(nome, 50, stdin);
```

## 4. Retornando Strings de Funções

Como strings são arrays, não podemos simplesmente retorná-las como fazemos em JavaScript. Podemos usar um **buffer estático**:

```c
#include <stdio.h>
#include <string.h>

char* hello(const char *name) {
    static char result[100];  // Buffer estático
    snprintf(result, sizeof(result), "Hello %s", name);
    return result;
}

int main() {
    char name[50];
    printf("Digite seu nome: ");
    scanf("%49s", name);

    printf("%s\n", hello(name));
    return 0;
}
```

## 5. Resumo Rápido

* **`%s`** → Usado no `printf()` e `scanf()` para strings.
* **Strings em C** → Arrays de `char`, terminados com `\0`.
* **`scanf("%s")`** → Não lê espaços; use `fgets()` para isso.
* **Retornando Strings** → Use um **buffer estático** ou aloque memória dinamicamente.

---
