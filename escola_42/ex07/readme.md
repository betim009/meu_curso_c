# 📚 Exercício 07: ft\_putnbr (Completo)

## 📌 Requisitos

- Função: ft_putnbr

- Arquivo: ft_putnbr.c

- Diretório: ex07/

- Protótipo: void ft_putnbr(int nb);

- Funções permitidas: write
----

## 🔎 Entendimento do Exercício

Você precisa criar uma função que:

* Receba um número inteiro.
* Exiba esse número corretamente no terminal.
* Consiga exibir tanto valores positivos quanto negativos.
* Considere todos os limites de um `int`.

---

## ⚙️ Estratégia de Solução

A solução pode ser dividida em etapas:

1. **Verificar se o número é negativo:**

   * Caso seja negativo, imprima o caractere `'-'` e transforme o número em positivo.

2. **Separar o número em dígitos individuais:**

   * Para isso, divida o número por 10 repetidamente até obter todos os dígitos.

3. **Imprimir cada dígito:**

   * Use a função `write` para exibir cada caractere individualmente.

---


## 🔍 Por que dividimos por 10 e usamos o módulo % 10?
Quando você tem um número inteiro qualquer, por exemplo 1234, você precisa exibir cada dígito separadamente, um por um, pois a função write só pode exibir um caractere por vez.

### 🧩 Imagine assim:
O número 1234 é formado por dígitos individuais:

`1 | 2 | 3 | 4`

***O computador vê esse número como um valor inteiro único, não como caracteres separados. Você precisa separar cada dígito individualmente para exibi-los.***



## 📖 Explicação Detalhada (Contextualização)

O exercício `ft_putnbr` pede que você crie uma função que recebe um número inteiro (`int`) e exiba exatamente este número no terminal. Você **não** pode usar funções prontas como `printf`. Em vez disso, você vai usar apenas a função básica `write`, que consegue exibir somente **um caractere por vez**.

Por isso, precisamos ter uma estratégia especial:

* **Dividir** o número por `10` para remover o último dígito e exibir os dígitos em ordem correta.
* Usar o operador **módulo `% 10`** para obter o último dígito do número.

Essas duas operações (`/ 10` e `% 10`) são essenciais porque a função `write` só imprime caracteres isoladamente. Não existe uma maneira direta para imprimir números inteiros inteiros com `write`. Por isso, precisamos decompor os números em dígitos individuais e exibi-los separadamente.

---


## 📝 Enunciado Bem Detalhado

Crie uma função chamada `ft_putnbr` que:

* Recebe um único valor inteiro (`int`) como parâmetro.
* Exibe exatamente esse número no terminal usando a função `write`.
* Deve ser capaz de exibir números positivos, negativos, o zero, e todos os valores extremos (`-2147483648` até `2147483647`).

**Exemplos:**

```c
ft_putnbr(42);           // Exibe: 42
ft_putnbr(-2147483648);  // Exibe: -2147483648
ft_putnbr(0);            // Exibe: 0
```

---

## ⚙️ Explicação Passo a Passo do Exercício

### 1. Tratamento especial do valor mínimo

* O número `-2147483648` não pode ser convertido diretamente para positivo, pois ultrapassa o limite máximo positivo de um `int`. Por isso, é necessário exibi-lo diretamente usando o `write`.

### 2. Tratamento de números negativos

* Se o número for negativo, primeiro exibimos o caractere `'-'` com `write`.
* Em seguida, tornamos o número positivo multiplicando-o por `-1`.

### 3. Dividir o número por 10 (`/ 10`)

* Divide o número por `10` para "remover" o último dígito e preparar a exibição dos dígitos anteriores.
* Fazemos isso recursivamente até sobrar um único dígito.

### 4. Módulo por 10 (`% 10`)

* Usa-se o módulo por `10` para obter exatamente o último dígito que deve ser exibido.

### Exemplo prático com número 1234:

| Operação    | Resultado | Explicação                |
| ----------- | --------- | ------------------------- |
| `1234 / 10` | 123       | Remove último dígito (4)  |
| `123 / 10`  | 12        | Remove último dígito (3)  |
| `12 / 10`   | 1         | Remove último dígito (2)  |
| `1 / 10`    | 0         | Chegou ao fim dos dígitos |
|             |           |                           |
| `1234 % 10` | 4         | Último dígito             |
| `123 % 10`  | 3         | Próximo dígito            |
| `12 % 10`   | 2         | Próximo dígito            |
| `1 % 10`    | 1         | Primeiro dígito           |

Usando recursão, o número é exibido na ordem correta: `1 2 3 4`.

---

## 🚩 Gabarito Completo (Código para testar)

Segue o código completo que resolve o exercício corretamente:

```c
#include <unistd.h>

// Função auxiliar para exibir um caractere
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Função principal
void ft_putnbr(int nb)
{
    // Tratamento do menor inteiro possível
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }

    // Tratamento de números negativos
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }

    // Recursão para números com mais de um dígito
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
    }

    // Exibe o último dígito
    ft_putchar(nb % 10 + '0');
}

// Código para testar a função
int main(void)
{
    ft_putnbr(42);
    write(1, "\n", 1);

    ft_putnbr(-2147483648);
    write(1, "\n", 1);

    ft_putnbr(2147483647);
    write(1, "\n", 1);

    ft_putnbr(0);
    write(1, "\n", 1);

    ft_putnbr(-12345);
    write(1, "\n", 1);

    return 0;
}
```

### Saída esperada:

```
42
-2147483648
2147483647
0
-12345
```

---

## ⚠️ Atenção às boas práticas:

* Não esqueça de tratar o número mínimo `-2147483648` de forma especial.
* Sempre use recursão para manter os dígitos na ordem correta.
* Não use espaços extras ou caracteres adicionais além do sinal negativo (`-`) para números negativos.

---

Agora você tem tudo detalhado e explicado para dominar esse exercício!

Bons estudos, meu rei! 🚀😉
