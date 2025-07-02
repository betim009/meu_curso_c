#include <unistd.h>

// Função auxiliar para escrever um único caractere
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Função para imprimir a combinação atual
void print_comb(int comb[], int n, int is_last)
{
    for (int i = 0; i < n; i++)
        ft_putchar(comb[i] + '0');
    if (!is_last)
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
}

// Função recursiva para gerar as combinações
void generate_combn(int comb[], int n, int pos, int start)
{
    if (pos == n)
    {
        // Verifica se é a última combinação
        int is_last = 1;
        for (int i = 0; i < n; i++)
        {
            if (comb[i] != (10 - n + i))
            {
                is_last = 0;
                break;
            }
        }
        print_comb(comb, n, is_last);
        return;
    }
    for (int i = start; i <= 9; i++)
    {
        comb[pos] = i;
        generate_combn(comb, n, pos + 1, i + 1);
    }
}

// Função principal conforme o enunciado
void ft_print_combn(int n)
{
    int comb[9]; // n <= 9
    if (n < 1 || n > 9)
        return;
    generate_combn(comb, n, 0, 0);
}

// Ponto de entrada
int main() {
    ft_print_combn(3); // Testa com n = 3
    return 0;
}
