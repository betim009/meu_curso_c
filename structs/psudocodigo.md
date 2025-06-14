
# Pseudocódigo e Fluxo Visual – Inserção em Listas Encadeadas

---

## 📍 Lista Circular Simples

### ✅ Inserir no Início (Circular)

**Pseudocódigo:**
```
Se lista estiver vazia:
    Cria um novo nó
    Faz o próximo dele apontar para ele mesmo
    Retorna o novo início

Senão:
    Cria um novo nó
    Faz o novo nó apontar para o início
    Percorre até o último nó
    Faz o último nó apontar para o novo
    Retorna o novo início
```

**Fluxo Visual:**
```
ANTES:
[5] → [10] → [15] → (volta ao 5)

APÓS INSERIR 2 NO INÍCIO:
[2] → [5] → [10] → [15] → (volta ao 2)
```

---

### ✅ Inserir no Fim (Circular)

**Pseudocódigo:**
```
Se lista estiver vazia:
    Cria um novo nó
    Faz o próximo dele apontar para ele mesmo
    Retorna o novo início

Senão:
    Cria um novo nó
    Percorre até o último nó
    Faz o último apontar para o novo
    Faz o novo apontar para o início
    Retorna o início (não muda)
```

**Fluxo Visual:**
```
ANTES:
[5] → [10] → [15] → (volta ao 5)

APÓS INSERIR 20 NO FIM:
[5] → [10] → [15] → [20] → (volta ao 5)
```

---

### ✅ Inserir Ordenado (Circular)

**Pseudocódigo:**
```
Se lista estiver vazia:
    Cria novo nó
    Faz o próximo dele apontar para ele mesmo
    Retorna o novo início

Se valor for menor que o primeiro:
    Usa a função de inserir no início
    Retorna o novo início

Senão:
    Percorre até achar o local correto
    Insere o novo nó entre dois nós
    Retorna o início
```

**Fluxo Visual:**
```
ANTES:
[5] → [10] → [15] → (volta ao 5)

APÓS INSERIR 8:
[5] → [8] → [10] → [15] → (volta ao 5)
```

---

## 📍 Lista Duplamente Encadeada Linear

### ✅ Inserir no Início (Dupla)

**Pseudocódigo:**
```
Cria novo nó

Se lista estiver vazia:
    Retorna o novo início

Senão:
    Faz o novo apontar para o antigo início
    Faz o antigo início apontar de volta para o novo
    Retorna o novo início
```

**Fluxo Visual:**
```
ANTES:
[5] ⇄ [10] ⇄ [15]

APÓS INSERIR 2 NO INÍCIO:
[2] ⇄ [5] ⇄ [10] ⇄ [15]
```

---

### ✅ Inserir no Fim (Dupla)

**Pseudocódigo:**
```
Cria novo nó

Se lista estiver vazia:
    Retorna o novo início

Senão:
    Percorre até o último nó
    Faz o último apontar para o novo
    Faz o novo apontar de volta para o último
    Retorna o início
```

**Fluxo Visual:**
```
ANTES:
[5] ⇄ [10] ⇄ [15]

APÓS INSERIR 20 NO FIM:
[5] ⇄ [10] ⇄ [15] ⇄ [20]
```

---

### ✅ Inserir Ordenado (Dupla)

**Pseudocódigo:**
```
Cria novo nó

Se lista estiver vazia:
    Retorna o novo início

Se valor for menor que o primeiro:
    Usa a função de inserir no início
    Retorna o novo início

Senão:
    Percorre até encontrar a posição correta
    Se for no meio:
        Ajusta os ponteiros entre anterior e próximo
    Se for no final:
        Insere no fim
    Retorna o início
```

**Fluxo Visual:**
```
ANTES:
[5] ⇄ [10] ⇄ [15]

APÓS INSERIR 8:
[5] ⇄ [8] ⇄ [10] ⇄ [15]
```

---

## ✅ Conclusão:

Esses são os **passos lógicos e visuais** para ajudar o aluno a entender a inserção nas duas estruturas:  
**Lista Circular Simples** e **Lista Duplamente Encadeada Linear**.

---


# Algoritmos e Fluxogramas – Inserção em Listas Encadeadas

---

## ✅ Inserir no Início – Lista Circular

**Algoritmo:**
```
Algoritmo Inserir_Inicio_Circular
Início
    Se (Lista está vazia) Então
        Criar novo nó
        Fazer novo nó apontar para ele mesmo
        Retornar novo início
    Senão
        Criar novo nó
        Fazer o novo nó apontar para o início
        Percorrer até o último nó
        Fazer o último nó apontar para o novo
        Retornar novo início
    FimSe
Fim
```

**Fluxograma:**
```
[Início]
    ↓
[Lista está vazia?] -- Sim --> [Criar novo nó → Aponta para ele mesmo → Retorna novo início]
        |
       Não
        ↓
[Novo aponta para início → Percorre até último → Último aponta para novo → Retorna novo início]
```

---

## ✅ Inserir no Início – Lista Duplamente Encadeada

**Algoritmo:**
```
Algoritmo Inserir_Inicio_Dupla
Início
    Criar novo nó
    Se (Lista está vazia) Então
        Retornar novo início
    Senão
        Novo aponta para antigo início
        Antigo início aponta de volta para novo
        Retornar novo início
    FimSe
Fim
```

**Fluxograma:**
```
[Início]
    ↓
[Criar novo nó]
    ↓
[Lista está vazia?] -- Sim --> [Retorna novo início]
        |
       Não
        ↓
[Novo aponta para início → Início aponta para novo → Retorna novo início]
```

---

## ✅ Inserir no Fim – Lista Circular

**Algoritmo:**
```
Algoritmo Inserir_Fim_Circular
Início
    Se (Lista está vazia) Então
        Criar novo nó
        Faz novo apontar para ele mesmo
        Retornar novo início
    Senão
        Criar novo nó
        Percorrer até último nó
        Último aponta para novo
        Novo aponta para início
        Retornar início
    FimSe
Fim
```

**Fluxograma:**
```
[Início]
    ↓
[Lista está vazia?] -- Sim --> [Criar novo nó → Aponta para ele mesmo → Retorna novo início]
        |
       Não
        ↓
[Criar novo nó → Percorre até último → Último aponta para novo → Novo aponta para início → Retorna início]
```

---

## ✅ Inserir no Fim – Lista Dupla

**Algoritmo:**
```
Algoritmo Inserir_Fim_Dupla
Início
    Criar novo nó
    Se (Lista está vazia) Então
        Retornar novo início
    Senão
        Percorrer até último nó
        Último aponta para novo
        Novo aponta para último
        Retornar início
    FimSe
Fim
```

**Fluxograma:**
```
[Início]
    ↓
[Criar novo nó]
    ↓
[Lista está vazia?] -- Sim --> [Retorna novo início]
        |
       Não
        ↓
[Percorre até último → Último aponta para novo → Novo aponta para último → Retorna início]
```

---

## ✅ Inserir Ordenado – Lista Circular

**Algoritmo:**
```
Algoritmo Inserir_Ordenado_Circular
Início
    Se (Lista está vazia) Então
        Criar novo nó
        Faz novo apontar para ele mesmo
        Retornar novo início
    FimSe

    Se (Valor < início.valor) Então
        Inserir no início
        Retornar novo início
    FimSe

    Percorrer até encontrar nó correto
    Inserir o novo entre os dois nós
    Retornar início
Fim
```

---

## ✅ Inserir Ordenado – Lista Dupla

**Algoritmo:**
```
Algoritmo Inserir_Ordenado_Dupla
Início
    Criar novo nó
    Se (Lista está vazia) Então
        Retornar novo início
    FimSe

    Se (Valor < início.valor) Então
        Inserir no início
        Retornar novo início
    FimSe

    Percorrer até achar posição correta
    Se (No meio) Então
        Ajustar ponteiros anterior e próximo
    SenãoSe (No final) Então
        Inserir no fim
    FimSe

    Retornar início
Fim
```

---

## ✅ Conclusão

Esses algoritmos ajudam o aluno a enxergar o **passo a passo lógico antes de programar em C**, facilitando o entendimento da estrutura das listas encadeadas.
