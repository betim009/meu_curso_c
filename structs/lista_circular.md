
# Exercício 3 – Remover todos os elementos iguais a um valor X

## 🧩 Enunciado resumido

> Crie uma função que **remova todos os elementos da lista circular** que contenham um valor igual ao número `X` passado como parâmetro.

---

## 🧠 O que esse exercício quer

1. **Percorrer toda a lista circular**.
2. Verificar se cada nó tem o valor `X`.
3. Remover **cada ocorrência** desse valor (não só a primeira).
4. Atualizar os ponteiros corretamente a cada remoção.
5. Retornar a lista modificada.

---

## 🧪 Exemplo prático

Lista original: `5 → 10 → 7 → 10 → 3 → (volta ao 5)`  
Valor `X = 10`

Após a função, a lista fica: `5 → 7 → 3 → (volta ao 5)`

---

## 📚 Conceitos envolvidos

| Conceito                        | Explicação                                                   |
|---------------------------------|---------------------------------------------------------------|
| Laço `do...while`               | Para percorrer a lista circular                               |
| Uso da função de remoção        | Reutiliza `removerValor()` do exercício 1                     |
| Laços encadeados/remoções múltiplas | Pode ser necessário rodar várias vezes até eliminar todos |
| Atualização da lista            | A cada remoção, a lista pode mudar, inclusive o `inicio`      |

---

## 🧱 Diferença em relação aos anteriores

| Exercício                        | Característica                                                |
|----------------------------------|----------------------------------------------------------------|
| Exercício 1                      | Funções básicas (uma remoção por vez)                         |
| Exercício 2                      | Somente leitura, sem alterar a lista                          |
| **Exercício 3**                  | Remove **vários nós** da lista, iterativamente               |

---

## 🎯 Estratégia sugerida

Uma maneira simples e segura de fazer isso é:

1. Verificar se a lista está vazia.
2. Usar um laço `while` que continua **enquanto ainda houver o valor X** na lista.
3. Em cada iteração, **chamar a função `removerValor()`**.
4. Retornar a lista no final.

---

## ✅ Código funcional com explicações

```c
No* removerTodosIguais(No* inicio, int valor) {
    if (!inicio) return NULL;

    // Enquanto encontrar o valor, continua removendo
    while (buscarNumero(inicio, valor)) {
        inicio = removerValor(inicio, valor);
    }

    return inicio;
}
```

---

## 🧪 Exemplo de uso

```c
lista = removerTodosIguais(lista, 10);
```

Se a lista tinha dois nós com valor 10, os dois serão removidos.

---

## 🎓 Conclusão

Essa função:
- Reaproveita a lógica de remoção do exercício 1.
- Aplica quantas vezes for necessário até limpar todos os valores iguais ao desejado.
- Altera a lista original, incluindo o ponteiro de início (caso o primeiro nó seja removido).

É o primeiro exercício que faz **várias modificações em sequência**, exigindo atenção ao ciclo da lista.

```c

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista circular
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Cria um novo nó
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = novo;
    return novo;
}

// Insere no final da lista
No* inserirFim(No* inicio, int valor) {
    No* novo = criarNo(valor);
    if (!inicio) return novo;

    No* atual = inicio;
    while (atual->prox != inicio)
        atual = atual->prox;

    atual->prox = novo;
    novo->prox = inicio;

    return inicio;
}

// Imprime a lista circular
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

// Busca valor na lista
int buscarNumero(No* inicio, int valor) {
    if (!inicio) return 0;

    No* atual = inicio;
    do {
        if (atual->valor == valor) return 1;
        atual = atual->prox;
    } while (atual != inicio);

    return 0;
}

// Remove a primeira ocorrência de um valor
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
        while (ultimo->prox != inicio)
            ultimo = ultimo->prox;

        inicio = inicio->prox;
        ultimo->prox = inicio;
        free(atual);
        return inicio;
    }

    anterior->prox = atual->prox;
    free(atual);
    return inicio;
}

// Exercício 3: Remove todos os nós com valor igual a X
No* removerTodosIguais(No* inicio, int valor) {
    if (!inicio) return NULL;

    while (buscarNumero(inicio, valor)) {
        inicio = removerValor(inicio, valor);
    }

    return inicio;
}

// Testando exercício 3
int main() {
    No* lista = NULL;

    // Inserindo valores na lista
    lista = inserirFim(lista, 5);
    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 7);
    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 3);

    printf("Lista original: ");
    imprimirLista(lista);

    int X = 10;
    lista = removerTodosIguais(lista, X);

    printf("Lista após remover todos os %d: ", X);
    imprimirLista(lista);

    return 0;
}
```