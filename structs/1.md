
# Lista Circular Dinâmica em C – Exercício 1 Completo

## ✅ Código funcional completo

```c
#include <stdio.h>
#include <stdlib.h>

// Definindo estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Criar novo nó
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = novo;
    return novo;
}

// Imprimir lista
void imprimirLista(No* inicio) {
    if (!inicio) {
        printf("Lista vazia!\n");
        return;
    }

    No* atual = inicio;
    do {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while (atual != inicio);
    printf("\n");
}

// Inserir ordenado
No* inserirOrdenado(No* inicio, int valor) {
    No* novo = criarNo(valor);
    if (!inicio) return novo;

    No *atual = inicio, *anterior = NULL;

    do {
        if (valor < atual->valor) break;
        anterior = atual;
        atual = atual->prox;
    } while (atual != inicio);

    if (!anterior) {
        No* ultimo = inicio;
        while (ultimo->prox != inicio) ultimo = ultimo->prox;
        novo->prox = inicio;
        ultimo->prox = novo;
        return novo;
    }

    anterior->prox = novo;
    novo->prox = atual;
    return inicio;
}

// Remover valor específico
No* removerValor(No* inicio, int valor) {
    if (!inicio) return NULL;

    No *atual = inicio, *anterior = NULL;

    do {
        if (atual->valor == valor) break;
        anterior = atual;
        atual = atual->prox;
    } while (atual != inicio);

    if (atual->valor != valor) return inicio;

    if (atual == inicio && atual->prox == inicio) {
        free(inicio);
        return NULL;
    }

    if (atual == inicio) {
        No* ultimo = inicio;
        while (ultimo->prox != inicio) ultimo = ultimo->prox;
        inicio = inicio->prox;
        ultimo->prox = inicio;
        free(atual);
        return inicio;
    }

    anterior->prox = atual->prox;
    free(atual);
    return inicio;
}

// Inserir no início
No* inserirInicio(No* inicio, int valor) {
    No* novo = criarNo(valor);
    if (!inicio) return novo;

    No* ultimo = inicio;
    while (ultimo->prox != inicio) ultimo = ultimo->prox;

    novo->prox = inicio;
    ultimo->prox = novo;

    return novo;
}

// Remover no início
No* removerInicio(No* inicio) {
    if (!inicio) return NULL;

    if (inicio->prox == inicio) {
        free(inicio);
        return NULL;
    }

    No* ultimo = inicio;
    while (ultimo->prox != inicio) ultimo = ultimo->prox;

    No* temp = inicio;
    inicio = inicio->prox;
    ultimo->prox = inicio;
    free(temp);

    return inicio;
}

// Inserir no fim
No* inserirFim(No* inicio, int valor) {
    No* novo = criarNo(valor);
    if (!inicio) return novo;

    No* ultimo = inicio;
    while (ultimo->prox != inicio) ultimo = ultimo->prox;

    ultimo->prox = novo;
    novo->prox = inicio;

    return inicio;
}

// Remover no fim
No* removerFim(No* inicio) {
    if (!inicio) return NULL;

    if (inicio->prox == inicio) {
        free(inicio);
        return NULL;
    }

    No *atual = inicio, *anterior = NULL;
    while (atual->prox != inicio) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = inicio;
    free(atual);
    return inicio;
}

// Buscar valor
int buscarNumero(No* inicio, int valor) {
    if (!inicio) return 0;

    No* atual = inicio;
    do {
        if (atual->valor == valor) return 1;
        atual = atual->prox;
    } while (atual != inicio);

    return 0;
}

// Função principal
int main() {
    No* lista = NULL;

    lista = inserirOrdenado(lista, 10);
    lista = inserirOrdenado(lista, 5);
    lista = inserirOrdenado(lista, 20);
    imprimirLista(lista);

    lista = inserirInicio(lista, 1);
    imprimirLista(lista);

    lista = inserirFim(lista, 30);
    imprimirLista(lista);

    lista = removerInicio(lista);
    imprimirLista(lista);

    lista = removerFim(lista);
    imprimirLista(lista);

    lista = removerValor(lista, 10);
    imprimirLista(lista);

    printf("Buscar 20: %s\n", buscarNumero(lista, 20) ? "Sim" : "Não");
    printf("Buscar 99: %s\n", buscarNumero(lista, 99) ? "Sim" : "Não");

    return 0;
}
```

---

## 📚 Explicação didática (para quem nunca viu C)

### 🧱 Estrutura básica

```c
typedef struct No {
    int valor;
    struct No* prox;
} No;
```
> Criamos um tipo chamado `No` (nó), que tem um número (`valor`) e aponta para o próximo.

### 📦 Funções principais

- `criarNo`: aloca memória e cria o nó com valor inicial.
- `inserirOrdenado`: insere mantendo a ordem (menores antes).
- `removerValor`: remove um valor específico.
- `inserirInicio` / `removerInicio`: trabalham no início da lista.
- `inserirFim` / `removerFim`: trabalham no final da lista.
- `buscarNumero`: procura um valor na lista circular.

### 🔁 Lista Circular

- O último elemento aponta de volta para o primeiro.
- Sempre percorremos com `do...while (atual != inicio);`.

### 🧪 `main()` faz tudo isso:

1. Insere 3 valores ordenados
2. Mostra a lista
3. Insere no início e no fim
4. Remove do início e do fim
5. Remove um valor específico
6. Testa se certos valores existem na lista

---

Você pode colar esse código no [https://onlinegdb.com/online_c_compiler](https://onlinegdb.com/online_c_compiler) e ver tudo funcionando.

