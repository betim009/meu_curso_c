#include <unistd.h>

// Função para imprimir um caractere
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Função para imprimir dois dígitos
void ft_putnbr2(int n)
{
    ft_putchar(n / 10 + '0');
    ft_putchar(n % 10 + '0');
}

// Função principal que gera as combinações
void ft_print_comb2(void)
{
    int a;
    int b;

    a = 0;
    while (a <= 98)
    {
        b = a + 1;
        while (b <= 99)
        {
            ft_putnbr2(a);
            ft_putchar(' ');
            ft_putnbr2(b);
            if (!(a == 98 && b == 99))
                write(1, ", ", 2);
            b++;
        }
        a++;
    }
}

void ft_print_comb2(void);

int main(void)
{
    ft_print_comb2();
    write(1, "\n", 1);
    return (0);
}