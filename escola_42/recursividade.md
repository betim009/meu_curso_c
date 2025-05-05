# 📚 Guia Completo sobre Recursividade em C (Didático)

---

## 🎯 O que é Recursividade?

Recursividade é um conceito na programação onde uma função **chama a si mesma** durante sua execução. Parece estranho no começo, mas é apenas uma maneira diferente e inteligente de resolver certos tipos de problemas que envolvem repetição ou divisão do problema em partes menores.

---

## 📌 Por que usar Recursividade?

Alguns problemas são mais fáceis de resolver usando recursão, especialmente aqueles que podem ser divididos em partes menores e idênticas. A recursão facilita:

* Códigos mais claros e menores (às vezes).
* Resolver problemas que naturalmente se dividem em etapas menores iguais.

---

## 🔍 Exemplo Didático (Simples e Claro)

Imagine que você quer exibir os números de 1 até 3 no terminal.

### Sem recursividade (com loop):

```c
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void contar(void)
{
    int i = 1;
    while (i <= 3)
    {
        ft_putchar(i + '0');
        i++;
    }
}

int main(void)
{
    contar();
    return 0;
}
```

Saída:

```
123
```

### Com recursividade:

```c
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void contar(int n)
{
    if (n > 3)          // Condição de parada
        return;

    ft_putchar(n + '0'); // Exibe o número atual
    contar(n + 1);      // Chama a função novamente com o próximo número
}

int main(void)
{
    contar(1);
    return 0;
}
```

Saída:

```
123
```

---

## ⚙️ Entendendo passo a passo o exemplo recursivo:

* Primeiro a função é chamada com `n = 1`.

  * Exibe o número `1`.
  * Chama a si mesma com `n = 2`.
* Agora a função está com `n = 2`.

  * Exibe o número `2`.
  * Chama a si mesma com `n = 3`.
* Agora a função está com `n = 3`.

  * Exibe o número `3`.
  * Chama a si mesma com `n = 4`.
* Agora a função está com `n = 4`.

  * Como `n` é maior que 3, a função retorna e para de chamar a si mesma.

Dessa forma, usando recursão, você exibiu os números sem usar diretamente um loop tradicional (`while` ou `for`).

---

## 🚧 Cuidados Importantes com Recursividade

* **Condição de parada:**

  * Sempre coloque uma condição que faça a recursão parar em algum momento.
  * Sem essa condição, seu programa entrará num loop infinito e vai travar!

Exemplo ruim (sem condição de parada):

```c
void contar(int n)
{
    ft_putchar(n + '0');
    contar(n + 1); // nunca para!
}
```

Isso gera um loop infinito. Sempre tenha uma condição clara que pare a recursão!

---

## 🔑 Quando usar recursão?

* Quando um problema pode ser claramente dividido em partes menores iguais.
* Quando loops tradicionais tornam o problema complexo demais.

**Exemplos clássicos:**

* Fatorial de um número
* Sequência Fibonacci
* Navegação em estruturas de dados (árvores, por exemplo)

---

## ✅ Resumo final sobre Recursividade

* Uma função recursiva chama a si mesma.
* Deve ter sempre uma condição clara para encerrar.
* Útil para problemas naturalmente divisíveis.
* Cuidado para evitar loops infinitos.

Agora você entende melhor o que é recursão, quando usar e os cuidados necessários para não errar na hora de implementar!

Bons estudos, meu rei! 🚀😉
