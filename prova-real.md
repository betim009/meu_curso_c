## 1
```c
#include <stdio.h>

float converter(float temperatura) {
    return temperatura * (9.0 / 5.0) + 32.0;
}

int main() {
    float f = converter(55.5);

    printf("Fahrenheit: %.2f\n", f);

    return 0;
}
```

## 2 
```c
#include <stdio.h>

int somaEntre(int x, int y) {
    int soma = 0, i;

    for (i = x + 1; i < y; i++) {
        soma = soma + i;
    }

    return soma;
}

int main() {
    int resultado = somaEntre(5, 10);

    printf("%d\n", resultado);

    return 0;
}
```

## 3
```c
#include <stdio.h>

float calcular(float a, float b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') return a / b;
    return 0;
}

int main() {

    float resultado = calcular(5.0, 5.0, '+');

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
```
## 4
```c
#include <stdio.h>

void trocar(double a, double b) {
    double temp;

    temp = a;
    a = b;
    b = temp;

    printf("A: %.2f\n", a);
    printf("B: %.2f\n", b);
}

int main() {
    double a = 5, b = 10;

    trocar(a, b);

    return 0;
}
```

## 5
```c
#include <stdio.h>

void maiorMenor(int n) {
    int valor, maior, menor;

    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);

        if (i == 0) {
            maior = valor;
            menor = valor;
        } else {
            if (valor > maior) maior = valor;
            if (valor < menor) menor = valor;
        }
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
}

int main() {
    int n = 5;

    maiorMenor(n);

    return 0;
}
```

## 6
```c
#include <stdio.h>

void esfera(float r) {
    float pi = 3.14;
    float v, a;

    v = (4.0/3.0) * pi * r * r * r;
    a = 4 * pi * r * r;

    printf("Volume: %.2f\n", v);
    printf("Area: %.2f\n", a);
}

int main() {
    float r;

    scanf("%f", &r);

    esfera(r);

    return 0;
}
```

## 7
```c
#include <stdio.h>

int main() {
    int v[6];
    int i;

    for (i = 0; i < 6; i++) {
        scanf("%d", &v[i]);
    }

    for (i = 5; i >= 0; i--) {
        printf("%d\n", v[i]);
    }

    return 0;
}
```

## 8
```c
#include <stdio.h>

int main() {
    int v[10];
    int i;
    int somaPares = 0;
    int qtdImpares = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &v[i]);

        if (v[i] % 2 == 0) {
            somaPares = somaPares + v[i];
            printf("Par: %d\n", v[i]);
        } else {
            qtdImpares++;
            printf("Impar: %d\n", v[i]);
        }
    }

    printf("Soma pares: %d\n", somaPares);
    printf("Qtd impares: %d\n", qtdImpares);

    return 0;
}
```

## 9
```c
#include <stdio.h>

int main() {
    int a[5] = {2,4,6,8,10};
    int b[5] = {1,3,5,7,9};
    int c[10];
    int i;

    for (i = 0; i < 5; i++) {
        c[i*2] = b[i];
        c[i*2 + 1] = a[i];
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
```

## 10
```c
#include <stdio.h>

int main() {
    int m[3][3];
    int i, j, soma = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i > j) {
                soma = soma + m[i][j];
            }
        }
    }

    printf("%d\n", soma);

    return 0;
}
```

## 11
```c
#include <stdio.h>

int main() {
    float a[2][2], b[2][2], c[2][2];
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%f", &b[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%.2f ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

## 12
```c
#include <stdio.h>

int main() {
    int a[3][3], b[3][3], c[3][3];
    int i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (k = 0; k < 3; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

## 13
```c
#include <stdio.h>

int main() {
    int a = 40;
    int *p;

    p = &a;

    printf("Endereco com &a: %p\n", &a);
    printf("Endereco com p: %p\n", p);

    scanf("%d", p);

    printf("Valor de a: %d\n", a);

    return 0;
}
```

## 14
```c
#include <stdio.h>
// int anda 4, double 8, char 1

int main() {
    int v1 = 1;
    double v2 = 2;
    char c = 'a';

    int *p_v1;
    double *p_v2;
    char *p_c;

    p_v1 = &v1;
    p_v2 = &v2;
    p_c = &c;

    printf("Endereco de v1: %p\n", p_v1);
    printf("Endereco de v2: %p\n", p_v2);
    printf("Endereco de c: %p\n", p_c);

    printf("Endereco +1 de v1: %p\n", p_v1 + 1);
    printf("Endereco +1 de v2: %p\n", p_v2 + 1);
    printf("Endereco +1 de c: %p\n", p_c + 1);

    printf("Endereco -1 de v1: %p\n", p_v1 - 1);
    printf("Endereco -1 de v2: %p\n", p_v2 - 1);
    printf("Endereco -1 de c: %p\n", p_c - 1);

    return 0;
}
```

## 15
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int **m;
    int linhas, colunas;
    int i, j;

    scanf("%d %d", &linhas, &colunas);

    m = (int **) malloc(linhas * sizeof(int *));

    for (i = 0; i < linhas; i++) {
        m[i] = (int *) malloc(colunas * sizeof(int));
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < linhas; i++) {
        free(m[i]);
    }

    free(m);

    return 0;
}
```

## 16
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v;
    int i;

    v = (int *) malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++) {
        scanf("%d", &v[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("%d\n", v[i]);
    }

    free(v);

    return 0;
}
```

## 17
```c
#include <stdio.h>

struct Conta {
    char nome[50];
    int numCC;
};

void preencher(struct Conta *c) {
    scanf(" %[^
]", c->nome);
    scanf("%d", &c->numCC);
}

void imprimir(struct Conta c) {
    printf("Nome: %s\n", c.nome);
    printf("Conta: %d\n", c.numCC);
}

int main() {
    struct Conta c;

    preencher(&c);
    imprimir(c);

    return 0;
}
```

## 18
```c
#include <stdio.h>

int ehPrimo(int n) {
    int i;

    if (n < 2) {
        return 0;
    }

    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

void primo(int m, int *p1, int *p2) {
    int i;

    for (i = m - 1; i >= 2; i--) {
        if (ehPrimo(i)) {
            *p1 = i;
            break;
        }
    }

    for (i = m + 1; ; i++) {
        if (ehPrimo(i)) {
            *p2 = i;
            break;
        }
    }
}

int main() {
    int m, p1, p2;

    scanf("%d", &m);

    primo(m, &p1, &p2);

    printf("Primo menor: %d\n", p1);
    printf("Primo maior: %d\n", p2);

    return 0;
}
```

## 19
```c
#include <stdio.h>

int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * fatorial(n - 1);
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%d\n", fatorial(n));

    return 0;
}
```

## 20
```c
#include <stdio.h>
#include <stdlib.h>

struct Musica {
    char titulo[50];
    char artista[50];
    char genero[50];
    float duracao;
    double numReproducoes;
};

struct Musica* criarLista(int n) {
    return (struct Musica*) malloc(n * sizeof(struct Musica));
}

void cadastrar(struct Musica lista[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        scanf(" %[^
]", lista[i].titulo);
        scanf(" %[^
]", lista[i].artista);
        scanf(" %[^
]", lista[i].genero);
        scanf("%f", &lista[i].duracao);
        scanf("%lf", &lista[i].numReproducoes);
    }
}

void maiorDuracao(struct Musica lista[], int n) {
    int i, pos = 0;

    for (i = 1; i < n; i++) {
        if (lista[i].duracao > lista[pos].duracao) {
            pos = i;
        }
    }

    printf("Titulo: %s\n", lista[pos].titulo);
    printf("Artista: %s\n", lista[pos].artista);
    printf("Genero: %s\n", lista[pos].genero);
    printf("Duracao: %.2f\n", lista[pos].duracao);
    printf("Reproducoes: %.0lf\n", lista[pos].numReproducoes);
}

int main() {
    struct Musica *lista;
    int n;

    scanf("%d", &n);

    lista = criarLista(n);

    cadastrar(lista, n);

    maiorDuracao(lista, n);

    free(lista);

    return 0;
}
```