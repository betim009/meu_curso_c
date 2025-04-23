#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// windows dependencia. 
int main() {
    ft_putchar('A'); // Teste da função
    return 0;
}