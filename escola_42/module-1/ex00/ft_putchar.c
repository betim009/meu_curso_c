#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 2);
}

int main()
{
    ft_putchar('A'); // Executa a funcao
    return 0;
}

// #include <unistd.h>

// void ft_putchar(char c)
// {
//     write(1, &c, 1);
// }

// // Nova função para exibir uma string
// void ft_putstr(char *str)
// {
//     int i = 0;
//     while (str[i])
//         i++;
//     write(1, str, i);
// }

// int main()
// {
//     ft_putchar('A'); // Executa a funcao
//     ft_putstr("BCDE"); // Exibe vários caracteres
//     return 0;
// }