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