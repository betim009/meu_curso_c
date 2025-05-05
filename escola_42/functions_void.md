# 📚 Guia Completo sobre Funções `void` em C

---

## 🎯 O que é uma função `void`?

Em linguagem C, uma função `void` é uma função que **não retorna nenhum valor** após ser executada. Ela é usada sempre que você precisa realizar uma ação sem precisar devolver nenhum resultado diretamente para quem chamou a função.

---

## 📌 Entendendo melhor com exemplos:

### Exemplo de função que retorna valor:

```c
int somar(int a, int b)
{
    return a + b;
}
```

* Essa função retorna um valor inteiro (`a + b`).

### Exemplo de função `void`:

```c
void imprimirMensagem(void)
{
    write(1, "Olá, mundo!", 12);
}
```

* Essa função apenas exibe uma mensagem na tela e não devolve nenhum valor para quem a chamou.

---

## 🔍 Como criar uma função `void`

A sintaxe básica de uma função `void` é:

```c
void nome_da_funcao(parâmetros)
{
    // comandos
}
```

* **void** indica que não retorna valor.
* Pode ter parâmetros (ou não).

Exemplo prático:

```c
#include <unistd.h>

void mostrarLetraA(void)
{
    char letra = 'A';
    write(1, &letra, 1);
}

int main(void)
{
    mostrarLetraA();
    return 0;
}
```

Saída:

```
A
```

---

## ⚙️ Quando usar funções `void`?

* Sempre que precisar executar algo **sem retornar um resultado** específico.
* Exemplos:

  * Exibir mensagens
  * Modificar valores externos (por meio de ponteiros)
  * Executar ações específicas como limpeza de tela ou inicialização

---

## 🚧 Pontos importantes sobre funções `void`

* Você **não pode usar** a palavra-chave `return` com um valor específico.
* Porém, você pode usar o `return;` sozinho, sem nenhum valor, se quiser finalizar a função antes do seu fim natural.

Exemplo válido:

```c
void mostrarLetraB(void)
{
    write(1, "B", 1);
    return; // válido, pois não retorna valor específico
}
```

Exemplo inválido:

```c
void mostrarLetraB(void)
{
    return 1; // inválido, funções void não retornam valores
}
```

---

## 🔑 Por que usar funções `void`?

* Organização do código: Dividir seu código em ações específicas e organizadas.
* Clareza: Deixar claro que uma função existe apenas para realizar uma tarefa específica e não produzir um valor.

---

## ✅ Resumo final sobre funções `void`

* **Não retornam valores**.
* Servem para executar tarefas ou ações específicas.
* Podem receber parâmetros.
* Tornam o código mais organizado e claro.

---

Agora você já sabe tudo sobre funções `void` em C e como utilizá-las no seu código!

Bons estudos, meu rei! 🚀😉
