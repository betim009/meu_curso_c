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

### a) Programa que lê dois números inteiros e exibe a soma:
```c
int a, b;
printf("Digite dois números: ");
scanf("%d %d", &a, &b);
printf("Soma: %d\n", a + b);
```

### b) Programa que calcula a média de duas notas:
```c
float n1, n2, media;
printf("Digite duas notas: ");
scanf("%f %f", &n1, &n2);
media = (n1 + n2) / 2;
printf("Média: %.2f\n", media);
```

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

