# Introdução à Programação em C: Variáveis, Leitura e Exibição de Dados

Se você vem do JavaScript, aprender C pode parecer desafiador no início. C é uma linguagem mais "próxima do hardware", com mais controle sobre como a memória é manipulada. Vamos por partes, com muitos exemplos para você entender cada passo.

---

## 1. Declaração de Variáveis

### JavaScript:
```javascript
let idade = 25;
```

### C:
```c
int idade = 25;
```

### Diferenças:
- Em C, você precisa dizer o **tipo da variável** (int, float, char, etc).
- Não existe `let`, `const` ou `var`.
- O ponto e vírgula `;` é sempre obrigatório.

### Tipos comuns:
- `int`: números inteiros (ex: 10, -3)
- `float`: números com casas decimais (ex: 3.14)
- `char`: um caractere (ex: 'A')
- `double`: número decimal com maior precisão que `float`
- `char[]`: array de caracteres (string)

### Exemplos:
```c
int idade = 30;
float altura = 1.75;
char letra = 'Z';
char nome[20] = "Alberto";
```

---

## 2. Exibir Dados (output)

### JavaScript:
```javascript
console.log("Idade:", idade);
```

### C:
```c
printf("Idade: %d", idade);
```

### Formatadores usados no printf:
- `%d` → `int`
- `%f` → `float`
- `%lf` → `double`
- `%c` → `char`
- `%s` → `string` (vetor de `char`)

### Exemplo completo:
```c
#include <stdio.h>

int main() {
    int idade = 25;
    float altura = 1.78;
    char letra = 'A';
    char nome[] = "Carlos";

    printf("Nome: %s\n", nome);
    printf("Letra: %c\n", letra);
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura); // %.2f exibe duas casas decimais

    return 0;
}
```

---

## 3. Leitura de Dados (input)

### JavaScript:
```javascript
let nome = prompt("Digite seu nome:");
```

### C:
```c
char nome[50];
scanf("%s", nome);
```

### Detalhes:
- `scanf` é usado para ler dados.
- `%d`, `%f`, `%s` também são usados aqui.
- `scanf` para números exige o uso de `&` (endereço da variável):
```c
int idade;
scanf("%d", &idade);
```

### Problemas com scanf:
- Ele para a leitura no primeiro espaço. Para ler uma frase ou nome completo:
```c
fgets(nome, sizeof(nome), stdin);
```

### Exemplo:
```c
#include <stdio.h>

int main() {
    char nome[50];
    int idade;

    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Nome: %s", nome);
    printf("Idade: %d\n", idade);

    return 0;
}
```

---

## 4. Ponteiros (Introdução e Troca de Valores)

JavaScript não possui ponteiros diretamente acessíveis. Em C, ponteiros são fundamentais para manipular **endereços de memória**.

### O que é um ponteiro?
Um ponteiro é uma variável que **guarda o endereço de outra variável**.

### Sintaxe básica:
```c
int idade = 25;
int *p; // ponteiro para int
p = &idade; // p guarda o endereço de idade
```

### Termos importantes:
- `&idade` → endereço da variável `idade`
- `*p` → valor que está no endereço guardado por `p`

### Exemplo explicando cada parte:
```c
#include <stdio.h>

int main() {
    int idade = 40;
    int *p = &idade;

    printf("Valor da idade: %d\n", idade);
    printf("Endereço de idade: %p\n", (void*)&idade);
    printf("Valor via ponteiro: %d\n", *p);
    printf("Endereço guardado em p: %p\n", (void*)p);

    return 0;
}
```

### Trocando valores usando ponteiros

Imagine que você quer trocar os valores de duas variáveis. Em JavaScript, você pode fazer:
```javascript
let a = 10, b = 20;
let temp = a;
a = b;
b = temp;
```

Em C, podemos fazer o mesmo, mas também podemos usar **funções e ponteiros**:

### Exemplo com ponteiros:
```c
#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    printf("Antes da troca: x = %d, y = %d\n", x, y);
    trocar(&x, &y);
    printf("Depois da troca: x = %d, y = %d\n", x, y);

    return 0;
}
```

### Explicação passo a passo:
1. `trocar` recebe os **endereços** de `x` e `y` (`&x`, `&y`).
2. Dentro da função, `*a` e `*b` acessam os valores que estão nesses endereços.
3. A troca acontece diretamente na memória — as variáveis originais `x` e `y` são modificadas!

### Visualizando a memória:
```c
x = 5   → memória 0x100 → valor 5
        *a = valor em 0x100 = 5
        &x = 0x100

y = 10  → memória 0x104 → valor 10
        *b = valor em 0x104 = 10
        &y = 0x104
```

### Mais exemplos com ponteiros:

#### Atribuindo valor via ponteiro:
```c
#include <stdio.h>

int main() {
    int valor;
    int *p = &valor;

    *p = 99; // atribuimos o valor diretamente na memória

    printf("Valor: %d\n", valor);  // 99
    printf("Valor via ponteiro: %d\n", *p);  // 99

    return 0;
}
```

#### Ponteiro para ponteiro:
```c
#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;
    int **pp = &p;

    printf("Valor de a: %d\n", a);
    printf("Valor via *p: %d\n", *p);
    printf("Valor via **pp: %d\n", **pp);

    return 0;
}
```

#### Passando endereço para função e alterando valor:
```c
#include <stdio.h>

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

Esses exemplos mostram como C permite **alterar variáveis fora da função**, pois estamos manipulando diretamente o conteúdo da memória.

---

## 5. Constantes

```c
#define PI 3.14
const int ANO = 2025;
```
- `#define` é como um "substituir tudo" (pré-processador).
- `const` é uma variável que não pode mudar depois.

---

## 6. Exercícios sugeridos


### c) Programa que troca os valores de duas variáveis usando ponteiros:
```c
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    trocar(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

---

# Entendendo Variáveis, Constantes e Ponteiros em C

Neste material, vamos revisar o conceito de variáveis, constantes e ponteiros em C, com exemplos práticos para comparar o uso de variáveis normais com ponteiros.

---

## ✅ Variável normal

Uma variável comum armazena diretamente um valor e pode ser alterada.

```c
#include <stdio.h>

int main() {
    int x = 10;
    x = x + 5;  // altera diretamente o valor de x
    printf("Valor de x: %d\n", x);  // Saída: 15
    return 0;
}
```

### ❌ Limitação
Se você passar `x` para uma função, ele será copiado. Alterar o valor dentro da função não afeta a variável original.

```c
void modifica(int valor) {
    valor = 100;  // apenas modifica a cópia
}

int main() {
    int x = 10;
    modifica(x);
    printf("x: %d\n", x);  // Saída: 10 (continua igual)
    return 0;
}
```

---

## ✨ Usando ponteiro para alterar o valor original

Com ponteiro, passamos o **endereço** da variável para a função, que assim consegue alterar seu valor original.

```c
#include <stdio.h>

void modifica(int *ptr) {
    *ptr = 100;  // altera o valor no endereço apontado
}

int main() {
    int x = 10;
    modifica(&x);  // passamos o endereço de x
    printf("x: %d\n", x);  // Saída: 100
    return 0;
}
```

---

## ✅ Constantes

Uma `const` é usada quando você **não quer que o valor seja alterado**.

```c
#include <stdio.h>

int main() {
    const int idade = 25;
    // idade = 30; // ERRO: não pode alterar
    printf("Idade: %d\n", idade);
    return 0;
}
```

---

## 🔁 Comparando os dois casos

### Sem ponteiro:
```c
void dobrar(int valor) {
    valor = valor * 2;
}

int main() {
    int x = 5;
    dobrar(x);
    printf("x: %d\n", x); // Saída: 5 (não mudou)
    return 0;
}
```

### Com ponteiro:
```c
void dobrar(int *p) {
    *p = *p * 2;
}

int main() {
    int x = 5;
    dobrar(&x);
    printf("x: %d\n", x); // Saída: 10 (alterado)
    return 0;
}
```

---

### ✅ Existem 3 formas principais de lidar com valores em C:
**- Variável normal**

1. Armazena diretamente um valor.

2. Pode ser alterada.

`Ex: int x = 10;`

**- Constante (const)**

1. Armazena um valor que não pode ser alterado.

`Ex: const int idade = 20;`

**- Ponteiro**

1. Armazena o endereço de memória de outra variável.

2. Serve para acessar e manipular essa variável indiretamente.

`Ex: int *p = &x;`

**🎯 Quando usar cada um:**

✅ Usa const quando você quer garantir que o valor não será alterado.

✅ Usa variável normal quando você quer guardar e alterar valores diretamente.



## 📌 Quando usar ponteiros?

Use ponteiros quando:
- Você precisa **alterar uma variável fora da função**.
- Quer **evitar copiar dados grandes**.
- Vai trabalhar com **alocação dinâmica de memória** (malloc).
- Precisa manipular **arrays, strings ou estruturas** de forma eficiente.

Caso contrário, variáveis comuns funcionam muito bem para tarefas simples!

---

## 🔁 Comparando:

| Situação                            | Usa ponteiro?         |
|------------------------------------|------------------------|
| Só quer usar o valor               | ❌ Não                 |
| Quer alterar o valor original      | ✅ Sim                 |
| Vai passar a variável pra função   | ✅ Se for alterar lá dentro |
| Quer evitar variável global        | ✅ Sim                 |

---

# 📘 Manipulando Variáveis e Ponteiros em C

Este documento mostra, com exemplos comentados, as diferenças e aplicações entre:
- Variáveis comuns
- Ponteiros
- Funções que recebem variáveis diretamente vs. ponteiros

---

## 🧪 Exemplo 1 – Alterando valor com ponteiro via função

```c
#include <stdio.h>

int muda(int *p) {
    return *p = 100; // altera diretamente o valor apontado
}

int main() {
    int x = 10;
    muda(&x);  // passamos o endereço de x
    printf("%d", x);  // Saída: 100
    return 0;
}
```

### ✅ Explicação:
- `muda` recebe um ponteiro para `int`.
- A função altera o valor original de `x`, pois trabalha direto no endereço.

---

## 🧪 Exemplo 2 – Usando variável comum (sem ponteiro)

```c
#include <stdio.h>

int main() {
    int numero = 10;
    numero += numero;  // dobra o valor

    printf("%d", numero);  // Saída: 20
    return 0;
}
```

### ✅ Explicação:
- Simples manipulação de variável comum.
- Não precisa de ponteiro quando não há passagem para outra função nem necessidade de alterar fora do escopo.

---

## 🧪 Exemplo 3 – Função dobrando valor com ponteiro

```c
#include <stdio.h>

int dobrar(int *p) {
    *p += *p;  // dobra o valor apontado
    return *p;
}

int main() {
    int numero = 10;
    dobrar(&numero);  // passamos o endereço de numero

    printf("%d", numero);  // Saída: 20
    return 0;
}
```

### ✅ Explicação:
- A função `dobrar` altera o valor de `numero` porque trabalha com ponteiro.
- Útil para reaproveitar lógica e modificar valores diretamente na memória.

---

## 🧪 Exemplo 4 – Exibindo dados usando ponteiros

```c
#include <stdio.h>

void exibindo(const char *pNome, int *pIdade) {
    printf("%s tem %d anos de idade.\n", pNome, *pIdade);
}

int main() {
    char nome[20] = "Jean";
    int numero = 10;

    exibindo(nome, &numero);
    return 0;
}
```

### ✅ Explicação:
- `char nome[20]` é um array, que se comporta como ponteiro ao ser passado.
- `int *pIdade` é ponteiro, permitindo ler o valor da idade.
- A função apenas **lê os valores**, não altera.

---

## 🆚 Comparando:

| Situação                            | Usa ponteiro?         |
|------------------------------------|------------------------|
| Só quer usar o valor               | ❌ Não                 |
| Quer alterar o valor original      | ✅ Sim                 |
| Vai passar a variável pra função   | ✅ Se for alterar lá dentro |
| Quer evitar variável global        | ✅ Sim                 |

---

## 🧠 Dica extra – Criando função que retorna string formatada

```c
#include <stdio.h>

char* frase(const char *nome, int idade) {
    static char texto[100];
    sprintf(texto, "%s tem %d anos.", nome, idade);
    return texto;
}

int main() {
    printf("%s\n", frase("Jean", 20));
    return 0;
}
```

### ✅ Explicação:
- Usa `sprintf` para formatar a string.
- `static char texto[]` garante que o ponteiro retornado continue válido após sair da função.

---




