#include <unistd.h>   /* fornece write() */

/* ft_putstr: imprime uma string usando write, 1 char por vez */
static void	ft_putstr(char *s)
{
	/* Enquanto não chegarmos no caractere nulo ('\0'), seguimos imprimindo. */
	while (*s)
		write(1, s++, 1);  /* 1 = stdout */
}

int	main(int argc, char **argv)
{
	(void)argc;              /* Evita warning de parâmetro não usado.        */
	ft_putstr(argv[0]);      /* Imprime o nome do executável (argv[0]).      */
	write(1, "\n", 1);      /* Imprime a quebra de linha ao final.          */
	return (0);              /* Sinaliza término bem-sucedido do programa.  */
}