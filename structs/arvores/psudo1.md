
# 📚 Pseudocódigo e Dicas – Questões 2 e 3 da Prova UFV (Estruturas de Dados)

## ✅ Questão 02 – Pilha Dupla (Vetor Compartilhado)

### 🎯 Objetivo:
Criar duas pilhas diferentes dentro de um único vetor.

- **Pilha A** cresce do início do vetor para frente.
- **Pilha B** cresce do final do vetor para trás.

### 📌 Variáveis principais:
- `topoA` → controla o topo da Pilha A.
- `topoB` → controla o topo da Pilha B.
- `qtd` → quantidade total de elementos nas duas pilhas juntas.

### ✅ Pseudocódigo:

#### Função `empilhar(elemento, pilha, op)`

```
Se quantidade total == tamanho máximo
    Mostrar "Pilha cheia"
Senão
    Se op == 1 (pilha A)
        Colocar o elemento no vetor[ topoA ]
        Incrementar topoA
    Senão se op == 2 (pilha B)
        Colocar o elemento no vetor[ topoB ]
        Decrementar topoB
    Incrementar quantidade total
```

#### Função `desempilhar(pilha, op)`

```
Se quantidade total == 0
    Mostrar "Pilha vazia"
Senão
    Se op == 1 (pilha A) e topoA > 0
        Decrementar topoA
        Retornar o valor do vetor[ topoA ]
    Senão se op == 2 (pilha B) e topoB < tamanho máximo
        Incrementar topoB
        Retornar o valor do vetor[ topoB ]
    Senão
        Mostrar "Operação inválida"
```

### ✅ Explicação:
- Pilha A cresce da esquerda para a direita.
- Pilha B cresce da direita para a esquerda.
- As duas pilhas não podem se cruzar no meio do vetor.

---

## ✅ Questão 03 – Empilhamento de Carros (Pilha LIFO)

### 🎯 Objetivo:
Simular uma carreta que empilha carros, respeitando a lógica LIFO (**Último a Entrar, Primeiro a Sair**).

### 📌 Variáveis principais:
- `topo` → controla a posição do último carro empilhado.

### ✅ Pseudocódigo:

#### Função `empilhar(elemento, pilha)`

```
Se topo == tamanho máximo - 1
    Mostrar "Carreta cheia"
Senão
    Incrementar topo
    Colocar o elemento no vetor[ topo ]
```

#### Função `desempilhar(pilha)`

```
Se topo == -1
    Mostrar "Carreta vazia"
    Retornar -1
Senão
    Guardar o valor de vetor[ topo ] em uma variável
    Decrementar topo
    Retornar o valor guardado
```

### ✅ Explicação:
- Ao empilhar, o `topo` sobe.
- Ao desempilhar, o `topo` desce.

---

## ✅ 📌 Dica de Ouro para Provas Futuras:

Mesmo que o professor mude o **tema**, o que o aluno precisa focar é:

| O que pode mudar | O que nunca muda |
|---|---|
| Nome das funções | A lógica de empilhar e desempilhar |
| Nome das variáveis | Controle de `topo`, `topoA`, `topoB` |
| Tema (carros, caixas, livros, etc.) | Pilha sempre usa a regra LIFO |
| Nomes de mensagens | Estrutura do vetor e controle de espaço continuam iguais |

### ✅ Resumindo:
O professor pode mudar o **tema**, mas a essência da lógica de **PILHA** e **PILHA DUPLA** sempre vai ser a mesma.

