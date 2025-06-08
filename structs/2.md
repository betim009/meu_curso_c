
# Relação entre o Exercício 2 e o Exercício 1 – Lista Circular em C

## ❓ A dúvida

> O Exercício 2 depende do Exercício 1 para funcionar?

---

## ✅ Resposta curta

- **Lógica interna (o que a função faz)**: **NÃO depende**
- **Estrutura e preparação da lista**: **SIM, depende**

---

## 🧠 Explicando melhor

### O que o Exercício 2 faz?

- Ele **conta** quantos valores na lista são **maiores que um número N**.
- Não altera nada.
- Só **percorre** a lista e **compara valores**.

### O que ele precisa para funcionar?

- Uma lista circular já pronta.
- Essa lista precisa estar estruturada com os **nós conectados corretamente**.

---

## 🧱 Por que depende do Exercício 1?

Porque o Exercício 1 define:

- A estrutura `No`
- As funções de criação e montagem da lista
  - `criarNo`
  - `inserirOrdenado`, `inserirFim`, etc.

Sem essas funções, você **não consegue criar a lista circular na prática**, e portanto não tem como testar o exercício 2.

---

## 🧩 Exemplo prático de dependência

Você só conseguiria testar o exercício 2 assim:

```c
No* lista = NULL;
lista = inserirFim(lista, 5);
lista = inserirFim(lista, 10);
lista = inserirFim(lista, 20);

int resultado = contarMaioresQue(lista, 6);
printf("Maiores que 6: %d", resultado);
```

Aqui, você usou **funções do exercício 1** para construir a lista.

---

## 🔁 Mas a lógica é independente

- A função `contarMaioresQue()` só precisa:
  - de um ponteiro `inicio`
  - de um número `N`
- Ela **não chama** nenhuma função do exercício 1
- Portanto, sua **lógica é autônoma**

---

## 🎓 Conclusão

| Aspecto                        | Depende do Ex. 1? |
|-------------------------------|-------------------|
| Estrutura `No`                | ✅ Sim            |
| Inserir/remover para montar   | ✅ Sim            |
| Lógica de contagem interna    | ❌ Não            |
| Saber percorrer lista         | ✅ Sim (conceito) |

Você pode entender e aplicar o exercício 2 **sem dominar inserção/remoção**, mas precisa que a lista esteja montada antes — mesmo que seja usando código pronto.

----

# Relação entre o Exercício 2 e o Exercício 1 – Lista Circular em C

## ❓ A dúvida

> O Exercício 2 depende do Exercício 1 para funcionar?

---

## ✅ Resposta curta

- **Lógica interna (o que a função faz)**: **NÃO depende**
- **Estrutura e preparação da lista**: **SIM, depende**

---

## 🧠 Explicando melhor

### O que o Exercício 2 faz?

- Ele **conta** quantos valores na lista são **maiores que um número N**.
- Não altera nada.
- Só **percorre** a lista e **compara valores**.

### O que ele precisa para funcionar?

- Uma lista circular já pronta.
- Essa lista precisa estar estruturada com os **nós conectados corretamente**.

---

## 🧱 Por que depende do Exercício 1?

Porque o Exercício 1 define:

- A estrutura `No`
- As funções de criação e montagem da lista
  - `criarNo`
  - `inserirOrdenado`, `inserirFim`, etc.

Sem essas funções, você **não consegue criar a lista circular na prática**, e portanto não tem como testar o exercício 2.

---

## 🧩 Exemplo prático de dependência

Você só conseguiria testar o exercício 2 assim:

```c
No* lista = NULL;
lista = inserirFim(lista, 5);
lista = inserirFim(lista, 10);
lista = inserirFim(lista, 20);

int resultado = contarMaioresQue(lista, 6);
printf("Maiores que 6: %d", resultado);
```

Aqui, você usou **funções do exercício 1** para construir a lista.

---

## 🔁 Mas a lógica é independente

- A função `contarMaioresQue()` só precisa:
  - de um ponteiro `inicio`
  - de um número `N`
- Ela **não chama** nenhuma função do exercício 1
- Portanto, sua **lógica é autônoma**

---

## 🎓 Conclusão

| Aspecto                        | Depende do Ex. 1? |
|-------------------------------|-------------------|
| Estrutura `No`                | ✅ Sim            |
| Inserir/remover para montar   | ✅ Sim            |
| Lógica de contagem interna    | ❌ Não            |
| Saber percorrer lista         | ✅ Sim (conceito) |

Você pode entender e aplicar o exercício 2 **sem dominar inserção/remoção**, mas precisa que a lista esteja montada antes — mesmo que seja usando código pronto.


```c

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista circular
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Cria um novo nó com valor
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = novo;
    return novo;
}

// Insere no final da lista circular
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

// Imprime os valores da lista
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

// Exercício 2: Conta quantos valores são maiores que N
int contarMaioresQue(No* inicio, int N) {
    if (!inicio) return 0;

    int cont = 0;
    No* atual = inicio;

    do {
        if (atual->valor > N) {
            cont++;
        }
        atual = atual->prox;
    } while (atual != inicio);

    return cont;
}

// Função principal para teste
int main() {
    No* lista = NULL;

    // Montando a lista circular com alguns valores
    lista = inserirFim(lista, 5);
    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 12);
    lista = inserirFim(lista, 4);
    lista = inserirFim(lista, 7);

    printf("Lista: ");
    imprimirLista(lista);

    int N = 6;
    int resultado = contarMaioresQue(lista, N);
    printf("Valores maiores que %d: %d\n", N, resultado);

    return 0;
}

```