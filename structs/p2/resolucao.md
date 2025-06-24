
# Resolução da Prova 2 – Estruturas de Dados (UFV - SIN211)

## Questão 01 – Deque Estática

Operações:
- InserirInicio(5)
- InserirFinal(18)
- InserirFinal(34)
- InserirFinal(52)
- InserirFinal(12)
- RemoverInicio()
- InserirFinal(15)
- RemoverInicio()
- RemoverInicio()
- InserirInicio(27)

### Resolução passo a passo (vetor de tamanho 5):

| Passo | Operação           | Vetor                  | Início | Fim | Quantidade |
|-------|--------------------|------------------------|--------|-----|------------|
| 1     | InserirInicio(5)   | [5]                    | 0      | 0   | 1          |
| 2     | InserirFinal(18)   | [5, 18]                | 0      | 1   | 2          |
| 3     | InserirFinal(34)   | [5, 18, 34]            | 0      | 2   | 3          |
| 4     | InserirFinal(52)   | [5, 18, 34, 52]        | 0      | 3   | 4          |
| 5     | InserirFinal(12)   | [5, 18, 34, 52, 12]    | 0      | 4   | 5          |
| 6     | RemoverInicio()    | [18, 34, 52, 12]       | 1      | 4   | 4          |
| 7     | InserirFinal(15)   | [18, 34, 52, 12, 15]   | 1      | 0   | 5          |
| 8     | RemoverInicio()    | [34, 52, 12, 15]       | 2      | 0   | 4          |
| 9     | RemoverInicio()    | [52, 12, 15]           | 3      | 0   | 3          |
| 10    | InserirInicio(27)  | [27, 52, 12, 15]       | 0      | 0   | 4          |

---

## Questão 02 – Fila de Transações

### Objetivo
Separar transações em duas filas:
- `filaSaques` para tipo `1` (valores negativos)
- `filaDepositos` para tipo `2` (valores positivos)

### Implementação da função `selecionarOperacoes`

```c
int selecionarOperacoes(Fila *fila, Fila *filaSaques, Fila *filaDepositos) {
    Elem *no = fila->inicio;
    while (no != NULL) {
        if (no->tipo == 1) {
            // saque
            Elem *novo = (Elem*) malloc(sizeof(Elem));
            novo->codigo = no->codigo;
            novo->tipo = no->tipo;
            novo->valor = no->valor;
            novo->prox = NULL;
            if (filaSaques->fim == NULL) filaSaques->inicio = novo;
            else filaSaques->fim->prox = novo;
            filaSaques->fim = novo;
            filaSaques->tamanho++;
        } else if (no->tipo == 2) {
            // depósito
            Elem *novo = (Elem*) malloc(sizeof(Elem));
            novo->codigo = no->codigo;
            novo->tipo = no->tipo;
            novo->valor = no->valor;
            novo->prox = NULL;
            if (filaDepositos->fim == NULL) filaDepositos->inicio = novo;
            else filaDepositos->fim->prox = novo;
            filaDepositos->fim = novo;
            filaDepositos->tamanho++;
        }
        no = no->prox;
    }
    return 1;
}
```

---

## Questão 03 – Carrinho de Compras

### Implementação da função `inserir`

```c
int inserir(Produto item, Carrinho *carrinho) {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    *novo = item;
    novo->prox = NULL;
    if (carrinho->inicio == NULL) {
        carrinho->inicio = novo;
    } else {
        Produto *atual = carrinho->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    carrinho->tamanho++;
    return 1;
}
```

### Implementação da função `retirar`

```c
int retirar(Produto item, Carrinho *carrinho) {
    Produto *atual = carrinho->inicio;
    Produto *anterior = NULL;
    while (atual != NULL && strcmp(atual->nome, item.nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return 0;
    if (anterior == NULL) carrinho->inicio = atual->prox;
    else anterior->prox = atual->prox;
    free(atual);
    carrinho->tamanho--;
    return 1;
}
```

---

## Pseudocódigos

### Pseudocódigo – Questão 01 (Deque Estático)

```
Algoritmo DequeEstatica
  vetor[5]
  inicio ← -1
  fim ← -1
  qtd ← 0

  Para cada operação:
    se operação = InserirInicio(x):
      se qtd = 5, erro
      inicio ← (inicio - 1 + 5) % 5
      vetor[inicio] ← x
      qtd++

    se operação = InserirFinal(x):
      se qtd = 5, erro
      fim ← (fim + 1) % 5
      vetor[fim] ← x
      qtd++

    se operação = RemoverInicio():
      se qtd = 0, erro
      inicio ← (inicio + 1) % 5
      qtd--

    se operação = RemoverFinal():
      se qtd = 0, erro
      fim ← (fim - 1 + 5) % 5
      qtd--

    Mostrar vetor, início, fim, qtd
Fim
```

### Pseudocódigo – Questão 02 (Filtrar Fila de Transações)

```
Algoritmo selecionarOperacoes(fila, filaSaques, filaDepositos)
  ponteiro ← fila.inicio
  Enquanto ponteiro ≠ NULL faça
    Se ponteiro.tipo = 1 então
      enfileirar na filaSaques
    Senão se ponteiro.tipo = 2 então
      enfileirar na filaDepositos
    ponteiro ← ponteiro.prox
  FimEnquanto
Fim
```

### Pseudocódigo – Questão 03 (Carrinho de Compras)

```
Função inserir(produto, carrinho)
  novo ← novo nó com produto
  Se carrinho.inicio = NULL
    carrinho.inicio ← novo
  Senão
    atual ← carrinho.inicio
    Enquanto atual.prox ≠ NULL
      atual ← atual.prox
    atual.prox ← novo
  carrinho.tamanho++

Função retirar(produto, carrinho)
  atual ← carrinho.inicio
  anterior ← NULL
  Enquanto atual ≠ NULL e atual.nome ≠ produto.nome
    anterior ← atual
    atual ← atual.prox
  Se atual = NULL então retorna erro
  Se anterior = NULL então carrinho.inicio ← atual.prox
  Senão anterior.prox ← atual.prox
  deletar atual
  carrinho.tamanho--
```

---

## Dica Final para Provas Futuras

Mesmo que o tema mude (por exemplo, produtos, transações, senhas, tarefas etc.), a **estrutura de dados usada (fila, pilha, lista)** e as **operações básicas (inserir, remover, percorrer)** **sempre serão as mesmas**.

⚠️ **Foque sempre em:**
- A estrutura base que está sendo usada (Fila, Pilha, Lista, Deque).
- As operações que estão sendo pedidas.
- O nome das funções e parâmetros que são obrigatórios.
- Saber adaptar o mesmo código para outro contexto (ex: "carrinho de compras" é uma lista encadeada).

Se você entendeu a estrutura, o tema pode mudar que você consegue resolver.
