
# Guia de Sobrevivência – Como Decorar Listas Encadeadas para a Prova

---

## ✅ Primeira Verdade: Ele vai ter que decorar!

Aprender de verdade leva semanas.  
Agora o foco é: **memorizar os códigos mais prováveis de cair na prova.**

---

## ✅ Ordem de prioridade: O que decorar primeiro

| Ordem | Conteúdo | Por quê? |
|---|---|---|
| 1 | Estrutura do nó (`struct No`) | Se errar isso, já trava tudo |
| 2 | Função de criar nó (`criarNo()`) | Toda lista começa criando nós |
| 3 | Inserir no início | Tipo de inserção mais simples |
| 4 | Inserir no fim | Segundo mais cobrado |
| 5 | Inserir ordenado | Se der tempo, aprende essa |
| 6 | Imprimir a lista | Pra testar e mostrar resultado na prova |
| 7 | Remover do início | Fácil e geralmente cobrado |
| 8 | Remover do fim | Segundo mais fácil |
| 9 | Buscar número | Sempre cai alguma busca |
| 10 | Remover valor específico | Última prioridade se sobrar tempo |

---

## ✅ Técnicas de memorização rápida

### 🎯 Técnica 1: Copiar no caderno
- Reescrever **pelo menos 2 vezes cada função**.
- Ajuda a fixar os padrões de ponteiros e IFs.

### 🎯 Técnica 2: Criar "blocos padrão"

Exemplo: Percorrer lista:
```c
No* atual = inicio;
while (atual) {
    atual = atual->prox;
}
```

Criar nó:
```c
No* novo = (No*) malloc(sizeof(No));
```

### 🎯 Técnica 3: Grifar frases-chave nos códigos
Exemplos:
- **"Se a lista estiver vazia"**
- **"Percorrer até o último nó"**
- **"Atualizar ponteiros anterior e próximo"**

### 🎯 Técnica 4: Mini-resumo de cabeçalhos de funções

```
Função criarNo
Função inserirInicio
Função inserirFim
Função inserirOrdenado
Função removerInicio
Função removerFim
Função removerValor
Função buscarNumero
Função imprimirLista
```

---

## ✅ Dicas extras

| Dica | Por quê |
|---|---|
| Escrever o código no papel | Pra treinar agilidade manual |
| Fazer uma lista de palavras que sempre esquece | Ex: malloc, NULL, free, sizeof |
| Decorar o formato de cada if | Muitas questões cobram condições |
| Repetir os nomes dos ponteiros ant e prox em voz alta | Pra não errar direção dos ponteiros |
| Se puder, leve uma folha com os protótipos das funções | Se a prova permitir consulta |

---

## ✅ Conclusão

👉 O aluno deve focar em:
- **Estrutura do nó**
- **Criar nó**
- **Inserir início e fim**
- **Percorrer e imprimir**
- **Se der tempo, aprender as demais**

Se ele conseguir decorar isso, já aumenta muito a chance de passar!

