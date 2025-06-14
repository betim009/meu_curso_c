
# Exercício 6 – Lista Duplamente Encadeada em C

## 📌 Entendendo o Enunciado

O exercício pede para criar uma **Lista Duplamente Encadeada** que armazene **números inteiros** e tenha as seguintes funcionalidades:

| Letra | O que fazer                                    |
|------|-------------------------------------------------|
| a)   | Inserir na lista de forma ordenada (crescente)  |
| b)   | Remover um número da lista de forma ordenada    |
| c)   | Inserir no início da lista                     |
| d)   | Remover no início da lista                     |
| e)   | Inserir no fim da lista                        |
| f)   | Remover no fim da lista                        |
| g)   | Pesquisar se um número existe na lista          |

---

## ✅ Conceitos básicos antes de programar

### O que é uma Lista Duplamente Encadeada?

- Cada nó tem **dois ponteiros**:
  - Um que aponta para o **próximo nó**
  - Um que aponta para o **nó anterior**

---

### Estrutura típica do nó:

```c
typedef struct No {
    int valor;
    struct No* ant;  // Anterior
    struct No* prox; // Próximo
} No;
```

---

## ✅ Diferenças entre Lista Circular e Lista Duplamente Encadeada

| Item                          | Lista Circular Simples           | Lista Duplamente Encadeada Linear |
|-------------------------------|----------------------------------|----------------------------------|
| Ponteiros por nó              | Apenas "próximo"                 | "Anterior" e "Próximo"           |
| Sentido de navegação          | Só para frente                   | Frente e trás                    |
| Fim da lista                  | Último nó aponta pro início      | Último nó aponta para NULL       |
| Tipo de ciclo                 | Tem ciclo (nunca acaba)          | Não tem ciclo (fim claro)        |

---

## ✅ Conceitos fundamentais para o aluno saber antes de codar:

| Conceito                      | Por que é importante?                                |
|-------------------------------|------------------------------------------------------|
| Uso de `struct`               | Para criar o modelo do nó                           |
| Ponteiros                     | Para conectar os nós                                |
| Alocação dinâmica (malloc)    | Para criar nós em tempo de execução                 |
| Liberação de memória (free)   | Para evitar vazamento de memória                    |
| Controle de NULL              | Saber quando chegou no fim da lista                 |
| Atualização dupla de ponteiros| Porque cada nó tem dois ponteiros a serem ajustados |

---

## ✅ O que o aluno vai treinar com esse exercício:

- Percorrer listas nos dois sentidos
- Atualizar múltiplos ponteiros ao inserir ou remover
- Pensar com mais atenção nos casos de início e fim da lista
- Garantir que a lista não quebre a sequência (não deixar ponteiros soltos)

---

## ✅ Conclusão antes de partir para o código:

> Esse exercício é uma evolução da lista simples.  
Agora, além de controlar o "próximo", o aluno precisa também controlar o "anterior".  
Isso dá mais poder de navegação, mas também exige mais cuidado ao alterar a lista.


-----


# Lista Duplamente Encadeada em C – Estrutura do Nó + criarNo()

## ✅ Estrutura do Nó

```c
typedef struct No {
    int valor;            // Valor guardado no nó
    struct No* ant;       // Ponteiro para o nó anterior
    struct No* prox;      // Ponteiro para o próximo nó
} No;
```

### ✅ Explicação:

- `int valor;` → Guarda o número do nó.
- `struct No* ant;` → Aponta para o nó anterior.
- `struct No* prox;` → Aponta para o próximo nó.

Essa estrutura permite andar **para frente e para trás** na lista.

---

## ✅ Função criarNo()

```c
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));  // Aloca memória para o novo nó
    novo->valor = valor;                  // Define o valor
    novo->ant = NULL;                     // Sem anterior no início
    novo->prox = NULL;                    // Sem próximo no início
    return novo;                          // Retorna o ponteiro para o nó criado
}
```

### ✅ Explicação linha por linha:

- `malloc(sizeof(No))`: Reserva espaço na memória para um nó.
- `(No*)`: Faz o casting para ponteiro do tipo `No`.
- `novo->valor = valor;`: Coloca o número informado dentro do campo `valor`.
- `novo->ant = NULL;`: Inicializa o ponteiro anterior como vazio.
- `novo->prox = NULL;`: Inicializa o ponteiro próximo como vazio.
- `return novo;`: Devolve o nó pronto para quem chamou a função.

---

## ✅ Exemplo de uso:

```c
No* primeiro = criarNo(10);
No* segundo = criarNo(20);
```
Aqui, criamos dois nós, mas **eles ainda não estão ligados**. Vamos fazer isso nas funções de inserção (próxima etapa).

---


# Lista Duplamente Encadeada em C – Função inserirInicio()

## ✅ Função inserirInicio

```c
No* inserirInicio(No* inicio, int valor) {
    No* novo = criarNo(valor);

    if (!inicio) {
        return novo;  // Se a lista estava vazia, o novo nó vira o início
    }

    novo->prox = inicio;        // Novo aponta para o antigo início
    inicio->ant = novo;         // O antigo início aponta de volta para o novo
    return novo;                // O novo agora é o primeiro da lista
}
```

---

## ✅ Explicação detalhada:

- **Parâmetros recebidos:**
  - `inicio`: ponteiro para o início da lista atual.
  - `valor`: número que queremos adicionar.

- **Processo:**

| Linha                               | O que faz                                          |
|-------------------------------------|----------------------------------------------------|
| `No* novo = criarNo(valor);`        | Cria um novo nó com o valor informado              |
| `if (!inicio) return novo;`         | Se a lista estava vazia, o novo nó vira o início   |
| `novo->prox = inicio;`              | Faz o novo nó apontar para o antigo início         |
| `inicio->ant = novo;`               | Faz o antigo início apontar de volta para o novo   |
| `return novo;`                      | Retorna o novo início da lista                     |

---

## 🧪 Exemplo prático de uso:

Lista antes:
```
[10] → [20] → [30]
```

Chamada:
```c
inicio = inserirInicio(inicio, 5);
```

Lista depois:
```
[5] → [10] → [20] → [30]
```

Onde:
- O campo `ant` de `10` agora aponta para o `5`.
- O novo início é o `5`.

---

## ✅ Conclusão:

Essa função adiciona um novo valor no **começo da lista duplamente encadeada**, cuidando de atualizar os dois ponteiros (anterior e próximo).

---


# Lista Duplamente Encadeada em C – Função inserirFim()

## ✅ Função inserirFim

```c
No* inserirFim(No* inicio, int valor) {
    No* novo = criarNo(valor);

    if (!inicio) {
        return novo;  // Se a lista estiver vazia, o novo nó vira o início
    }

    No* atual = inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;  // Avança até o último nó
    }

    atual->prox = novo;   // O último nó aponta para o novo
    novo->ant = atual;    // O novo aponta de volta para o antigo último
    return inicio;        // O início da lista não muda
}
```

---

## ✅ Explicação detalhada:

- **Parâmetros recebidos:**
  - `inicio`: ponteiro para o início da lista atual.
  - `valor`: número que queremos adicionar no final.

- **Processo:**

| Linha                               | O que faz                                          |
|-------------------------------------|----------------------------------------------------|
| `No* novo = criarNo(valor);`        | Cria o novo nó com o valor informado              |
| `if (!inicio) return novo;`         | Se a lista estiver vazia, o novo vira o início    |
| `No* atual = inicio;`               | Começa a percorrer a lista                        |
| `while (atual->prox != NULL)`       | Avança até o último nó                            |
| `atual->prox = novo;`               | Faz o último nó apontar para o novo               |
| `novo->ant = atual;`                | Faz o novo nó apontar para o antigo último        |
| `return inicio;`                    | Retorna o início da lista                         |

---

## 🧪 Exemplo prático de uso:

Lista antes:
```
[5] → [10] → [20]
```

Chamada:
```c
inicio = inserirFim(inicio, 30);
```

Lista depois:
```
[5] → [10] → [20] → [30]
```

Onde:
- O campo `prox` de `20` agora aponta para `30`.
- O campo `ant` de `30` aponta para `20`.

---

## ✅ Conclusão:

Essa função adiciona um novo valor **no final da lista**, mantendo o encadeamento duplo (frente e trás).

---


# Lista Duplamente Encadeada em C – Função inserirOrdenado()

## ✅ Função inserirOrdenado

```c
No* inserirOrdenado(No* inicio, int valor) {
    No* novo = criarNo(valor);

    if (!inicio || valor < inicio->valor) {
        novo->prox = inicio;
        if (inicio) {
            inicio->ant = novo;
        }
        return novo;
    }

    No* atual = inicio;
    while (atual->prox && atual->prox->valor < valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    if (atual->prox) {
        atual->prox->ant = novo;
    }
    atual->prox = novo;
    novo->ant = atual;

    return inicio;
}
```

---

## ✅ Explicação detalhada:

| Linha                                | O que faz                                          |
|--------------------------------------|----------------------------------------------------|
| `No* novo = criarNo(valor);`         | Cria o novo nó com o valor informado              |
| `if (!inicio || valor < inicio->valor)` | Se a lista estiver vazia ou o valor for o menor, insere no início |
| `novo->prox = inicio;`               | Liga o novo nó ao antigo início                   |
| `if (inicio) inicio->ant = novo;`    | Atualiza o ponteiro anterior do antigo início     |
| Percorre com `atual`                 | Anda pela lista até achar a posição certa         |
| Ligações finais                      | Ajusta os ponteiros do novo, do atual e do próximo |
| `return inicio;`                     | Retorna o início da lista                         |

---

## 🧪 Exemplo prático:

Lista antes:
```
[5] → [10] → [20]
```

Chamada:
```c
inicio = inserirOrdenado(inicio, 15);
```

Lista depois:
```
[5] → [10] → [15] → [20]
```

---

## ✅ Conclusão:

Essa função insere o novo valor na **posição correta da lista**, mantendo a ordem crescente e atualizando os ponteiros `ant` e `prox` de forma segura.

---


# Lista Duplamente Encadeada em C – Função removerInicio()

## ✅ Função removerInicio

```c
No* removerInicio(No* inicio) {
    if (!inicio) return NULL;  // Lista vazia

    No* temp = inicio;         // Guarda o primeiro nó para liberar depois
    inicio = inicio->prox;     // O novo início é o próximo da lista

    if (inicio) {
        inicio->ant = NULL;    // Se ainda houver nós, ajusta o anterior para NULL
    }

    free(temp);                // Libera o antigo primeiro nó
    return inicio;             // Retorna o novo início
}
```

---

## ✅ Explicação detalhada:

| Linha                                | O que faz                                          |
|--------------------------------------|----------------------------------------------------|
| `if (!inicio) return NULL;`          | Verifica se a lista está vazia                    |
| `No* temp = inicio;`                 | Guarda o nó que vai ser removido                  |
| `inicio = inicio->prox;`             | Atualiza o início da lista                        |
| `if (inicio) inicio->ant = NULL;`    | Se houver novo início, ajusta o campo `ant`       |
| `free(temp);`                        | Libera o nó antigo da memória                     |
| `return inicio;`                     | Retorna o novo início da lista                    |

---

## 🧪 Exemplo prático:

Lista antes:
```
[5] → [10] → [20]
```

Chamada:
```c
inicio = removerInicio(inicio);
```

Lista depois:
```
[10] → [20]
```

---

## ✅ Conclusão:

Essa função **remove o primeiro nó da lista**, atualizando os ponteiros corretamente para manter a integridade da lista duplamente encadeada.

---


# Lista Duplamente Encadeada em C – Função removerFim()

## ✅ Função removerFim

```c
No* removerFim(No* inicio) {
    if (!inicio) return NULL;  // Lista vazia

    if (!inicio->prox) {
        free(inicio);          // Só tem um nó
        return NULL;
    }

    No* atual = inicio;
    while (atual->prox) {
        atual = atual->prox;   // Anda até o último nó
    }

    atual->ant->prox = NULL;   // Penúltimo nó vira o último
    free(atual);               // Libera o antigo último
    return inicio;             // Retorna o início da lista
}
```

---

## ✅ Explicação detalhada:

| Linha                                | O que faz                                          |
|--------------------------------------|----------------------------------------------------|
| `if (!inicio) return NULL;`          | Verifica se a lista está vazia                    |
| `if (!inicio->prox)`                 | Caso especial: lista com apenas um nó             |
| `No* atual = inicio;`                | Começa a percorrer a lista                        |
| `while (atual->prox)`                | Avança até o último nó                            |
| `atual->ant->prox = NULL;`           | O penúltimo nó passa a ser o último               |
| `free(atual);`                       | Libera o antigo último da memória                 |
| `return inicio;`                     | Retorna o início da lista                         |

---

## 🧪 Exemplo prático:

Lista antes:
```
[5] → [10] → [20]
```

Chamada:
```c
inicio = removerFim(inicio);
```

Lista depois:
```
[5] → [10]
```

---

## ✅ Conclusão:

A função **remove o último elemento da lista**, atualizando o ponteiro do penúltimo nó para `NULL`.

----


# Lista Duplamente Encadeada em C – Funções removerValor() e buscarNumero()

## 🧩 Função removerValor()

```c
No* removerValor(No* inicio, int valor) {
    if (!inicio) return NULL;  // Lista vazia

    No* atual = inicio;

    while (atual && atual->valor != valor) {
        atual = atual->prox;  // Percorre a lista
    }

    if (!atual) return inicio;  // Valor não encontrado

    if (!atual->ant && !atual->prox) {
        free(atual);            // Único nó da lista
        return NULL;
    }

    if (!atual->ant) {
        inicio = atual->prox;
        inicio->ant = NULL;
    } else if (!atual->prox) {
        atual->ant->prox = NULL;
    } else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }

    free(atual);
    return inicio;
}
```

### ✅ Explicação passo a passo:

| Linha                                  | O que faz                                   |
|----------------------------------------|-------------------------------------------|
| `if (!inicio) return NULL;`            | Se a lista estiver vazia                   |
| Percorre com `while`                   | Busca o nó com o valor informado           |
| `if (!atual) return inicio;`           | Se o valor não for encontrado              |
| Caso de único nó                      | Remove e retorna NULL                      |
| Caso de primeiro nó                  | Ajusta o início da lista                   |
| Caso de último nó                    | Ajusta o penúltimo nó                      |
| Caso no meio                         | Ajusta os dois ponteiros (ant e prox)       |
| `free(atual);`                         | Libera o nó da memória                     |

---

## 🧩 Função buscarNumero()

```c
int buscarNumero(No* inicio, int valor) {
    No* atual = inicio;

    while (atual) {
        if (atual->valor == valor) {
            return 1;  // Encontrado
        }
        atual = atual->prox;
    }

    return 0;  // Não encontrado
}
```

### ✅ Explicação passo a passo:

| Linha                      | O que faz                       |
|----------------------------|---------------------------------|
| `No* atual = inicio;`       | Começa a percorrer do início    |
| `while (atual)`            | Anda até o final da lista       |
| `if (atual->valor == valor)` | Se encontrar o valor, retorna 1 |
| `return 0;`                | Se não encontrar, retorna 0     |

---

## 🧪 Exemplo prático de uso:

```c
if (buscarNumero(lista, 10)) {
    printf("Valor 10 encontrado!\n");
}

lista = removerValor(lista, 10);
```

- Primeiro verifica se o número existe.
- Depois remove o número da lista caso exista.

---

## ✅ Conclusão:

Essas funções são usadas para:
- **Procurar valores dentro da lista** (busca)
- **Remover um valor específico** da lista mantendo o encadeamento correto.


```c

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista duplamente encadeada
typedef struct No {
    int valor;
    struct No* ant;
    struct No* prox;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

// Inserir no início
No* inserirInicio(No* inicio, int valor) {
    No* novo = criarNo(valor);
    if (!inicio) return novo;
    novo->prox = inicio;
    inicio->ant = novo;
    return novo;
}

// Inserir no final
No* inserirFim(No* inicio, int valor) {
    No* novo = criarNo(valor);
    if (!inicio) return novo;
    No* atual = inicio;
    while (atual->prox) {
        atual = atual->prox;
    }
    atual->prox = novo;
    novo->ant = atual;
    return inicio;
}

// Inserir ordenado (crescente)
No* inserirOrdenado(No* inicio, int valor) {
    No* novo = criarNo(valor);
    if (!inicio || valor < inicio->valor) {
        novo->prox = inicio;
        if (inicio) inicio->ant = novo;
        return novo;
    }
    No* atual = inicio;
    while (atual->prox && atual->prox->valor < valor) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    if (atual->prox) atual->prox->ant = novo;
    atual->prox = novo;
    novo->ant = atual;
    return inicio;
}

// Remover do início
No* removerInicio(No* inicio) {
    if (!inicio) return NULL;
    No* temp = inicio;
    inicio = inicio->prox;
    if (inicio) inicio->ant = NULL;
    free(temp);
    return inicio;
}

// Remover do final
No* removerFim(No* inicio) {
    if (!inicio) return NULL;
    if (!inicio->prox) {
        free(inicio);
        return NULL;
    }
    No* atual = inicio;
    while (atual->prox) {
        atual = atual->prox;
    }
    atual->ant->prox = NULL;
    free(atual);
    return inicio;
}

// Remover valor específico
No* removerValor(No* inicio, int valor) {
    if (!inicio) return NULL;
    No* atual = inicio;
    while (atual && atual->valor != valor) {
        atual = atual->prox;
    }
    if (!atual) return inicio;
    if (!atual->ant && !atual->prox) {
        free(atual);
        return NULL;
    }
    if (!atual->ant) {
        inicio = atual->prox;
        inicio->ant = NULL;
    } else if (!atual->prox) {
        atual->ant->prox = NULL;
    } else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }
    free(atual);
    return inicio;
}

// Buscar número
int buscarNumero(No* inicio, int valor) {
    No* atual = inicio;
    while (atual) {
        if (atual->valor == valor) return 1;
        atual = atual->prox;
    }
    return 0;
}

// Imprimir lista
void imprimirLista(No* inicio) {
    No* atual = inicio;
    printf("Lista: ");
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// Função main para teste
int main() {
    No* lista = NULL;

    lista = inserirOrdenado(lista, 20);
    lista = inserirOrdenado(lista, 10);
    lista = inserirOrdenado(lista, 30);
    imprimirLista(lista);

    lista = removerInicio(lista);
    imprimirLista(lista);

    lista = removerFim(lista);
    imprimirLista(lista);

    lista = inserirInicio(lista, 5);
    imprimirLista(lista);

    lista = inserirFim(lista, 50);
    imprimirLista(lista);

    if (buscarNumero(lista, 50)) {
        printf("Valor 50 encontrado!\n");
    }

    lista = removerValor(lista, 50);
    imprimirLista(lista);

    return 0;
}

```