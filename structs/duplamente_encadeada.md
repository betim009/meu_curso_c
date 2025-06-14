
# Lista Duplamente Encadeada em C – Conceito e Quando Usar

## 📘 O que é uma Lista Duplamente Encadeada?

Uma **Lista Duplamente Encadeada** (Doubly Linked List) é uma estrutura de dados onde **cada nó tem dois ponteiros**:

- Um ponteiro para o **nó anterior**.
- Um ponteiro para o **próximo nó**.

Isso permite **navegar nos dois sentidos da lista**.

### 📦 Estrutura de um nó em C:

```c
typedef struct No {
    int valor;
    struct No* ant;  // Ponteiro para o nó anterior
    struct No* prox; // Ponteiro para o próximo nó
} No;
```

---

## 🔗 Exemplo visual:

Lista com os valores: `10 → 20 → 30`

```
NULL ← [10] ↔ [20] ↔ [30] → NULL
```

- Primeiro nó aponta para NULL no anterior.
- Último nó aponta para NULL no próximo.

---

## 🛠 Operações comuns:

| Operação                 | O que faz                                |
|--------------------------|------------------------------------------|
| Inserir no início        | Adiciona um novo nó no começo            |
| Inserir no final         | Adiciona um novo nó no fim               |
| Remover do início        | Remove o primeiro nó                    |
| Remover do final         | Remove o último nó                      |
| Percorrer para frente    | Do início até o fim                      |
| Percorrer para trás      | Do fim até o início                      |

---

## ✅ Vantagens sobre lista simples:

| Lista Simples                          | Lista Duplamente Encadeada               |
|----------------------------------------|-----------------------------------------|
| Só anda para frente                    | Anda nos dois sentidos                  |
| Difícil remover um nó no meio          | Fácil remover qualquer nó               |
| Menos memória (só 1 ponteiro por nó)   | Mais memória (2 ponteiros por nó)       |

---

## 📌 Quando usar uma Lista Duplamente Encadeada?

| Situação                                              | Ideal usar?      |
|-------------------------------------------------------|------------------|
| Precisa andar para frente e para trás na lista        | ✅ Sim           |
| Muitas remoções/inserções no meio da lista           | ✅ Sim           |
| Precisa economizar memória                            | ❌ Não           |
| Estrutura de navegação (ex: navegador)               | ✅ Sim           |
| Editores de texto com manipulação no meio            | ✅ Sim           |
| Implementação de fila dupla (Deque)                  | ✅ Sim           |
| Leitura simples, só para frente                      | ❌ Melhor lista simples |

---

## 🧱 Exemplo de aplicações reais:

- Navegadores (botão Voltar/Avançar)
- Editores de texto
- Sistemas operacionais (listas de processos)
- Estruturas de Deque

---

## 🎓 Conclusão:

> Use lista duplamente encadeada quando **precisar de flexibilidade de navegação** e **eficiência em remoções/inserções em qualquer parte da lista**.
