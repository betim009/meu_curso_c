# ✅ Gabarito Detalhado dos Exercícios de Fundamentos em C

Aqui estão as soluções comentadas e explicadas passo a passo para cada um dos 5 exercícios propostos.

---

## 🧠 Exercício 1: Imprimir os dígitos de 0 a 9 com separador

```c
#include <unistd.h>

void ft_print_digits(void)
{
    char c = '0';

    while (c <= '9')
    {
        write(1, &c, 1);
        if (c != '9') // evita a vírgula após o último número
            write(1, ", ", 2);
        c++;
    }
}
```

📝 **Explicação:**
- A variável `c` percorre de `'0'` a `'9'`.
- A vírgula e o espaço são impressos somente **se não for o último número**.

---

## 🧪 Exercício 2: Múltiplos de 5 entre 10 e 99

```c
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_put2digits(int n)
{
    ft_putchar(n / 10 + '0');
    ft_putchar(n % 10 + '0');
}

void ft_print_multiples_of_5(void)
{
    int i = 10;

    while (i < 100)
    {
        ft_put2digits(i);
        if (i + 5 < 100) // evita a vírgula após o último número
            write(1, ", ", 2);
        i += 5;
    }
}
```

📝 **Explicação:**
- `ft_put2digits` imprime dois dígitos.
- A vírgula é impressa somente se **não for o último múltiplo**.

---

## 🔄 Exercício 3: Contagem regressiva de 9 até 0

```c
#include <unistd.h>

void ft_print_reverse_digits(void)
{
    char c = '9';

    while (c >= '0')
    {
        write(1, &c, 1);
        if (c != '0')
            write(1, " ", 1);
        c--;
    }
}
```

📝 **Explicação:**
- O loop começa do `'9'` e vai até `'0'`.
- O espaço só é impresso **entre os números**, nunca no final.

---

## 🔢 Exercício 4: Combinação de duas letras

```c
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_letter_pairs(void)
{
    char a = 'a';

    while (a <= 'y')
    {
        char b = a + 1;
        while (b <= 'z')
        {
            ft_putchar(a);
            ft_putchar(b);
            if (!(a == 'y' && b == 'z'))
                write(1, ", ", 2);
            b++;
        }
        a++;
    }
}
```

📝 **Explicação:**
- Duas letras (a, b) são combinadas sem repetição e sem inverter.
- `a` vai até `'y'`, e `b` começa sempre de `a + 1`.
- Evita vírgula após `yz`.

---

## 🧠 Exercício 5: Dígitos de um número de trás para frente

```c
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_digits_reversed(int n)
{
    if (n == 0)
    {
        ft_putchar('0');
        write(1, "\n", 1);
        return;
    }

    while (n > 0)
    {
        int digit = n % 10;
        ft_putchar(digit + '0');
        write(1, "\n", 1);
        n /= 10;
    }
}
```

📝 **Explicação:**
- Extrai o último dígito com `% 10` e imprime.
- Remove o último dígito com `/= 10`.
- Exibe cada dígito **em uma nova linha**.

---

Essas soluções seguem os princípios fundamentais da linguagem C e ajudam a fixar o uso de `write`, loops e manipulação de caracteres.

Bora continuar codando! 🚀