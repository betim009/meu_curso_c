#include <unistd.h>

void ft_print_alphabet(void)
{
	char letter;

	letter = 'a';
	while (letter <= 'z')
	{
		write(1, &letter, 1);
        write(1, " ", 1);
		letter++;
	}
}

int main() {

    ft_print_alphabet();
    write(1, "\n", 1);
    return 1;
}