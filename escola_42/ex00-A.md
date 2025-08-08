# 42 C 06 — Gabarito comentado (ex00–ex03)

Formato: cada atividade traz o **enunciado resumido** nos comentários no topo,
seguido do **gabarito em C** com **explicações linha a linha**.

---

## EX00 — ft_print_program_name.c

```c
/* ************************************************************************** */
/*                                                                            */
/*  EX00 — ft_print_program_name                                              */
/*                                                                            */
/*  O QUE O ENUNCIADO QUER:                                                   */
/*  - Imprimir o NOME DO PROGRAMA (argv[0]) seguido de uma quebra de linha.   */
/*  - Usar SOMENTE write (sem printf).                                        */
/*                                                                            */
/*  O QUE DEVE RETORNAR/IMPRIMIR:                                             */
/*  - Exemplo: se você executa ./ex00/ex00, a saída será:                     */
/*      ./ex00/ex00                                                           */
/*                                                                            */
/*  COMO FAZER (PASSO A PASSO):                                               */
/*  - argv[0] contém o texto usado para chamar o programa.                    */
/*  - Imprima argv[0] caractere a caractere com write.                        */
/*  - Escreva '\n' ao final.                                                 */
/*                                                                            */
/* ************************************************************************** */

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
```

---

## EX01 — ft_print_params.c

```c
/* ************************************************************************** */
/*                                                                            */
/*  EX01 — ft_print_params                                                    */
/*                                                                            */
/*  O QUE O ENUNCIADO QUER:                                                   */
/*  - Imprimir TODOS os parâmetros da linha de comando, um por linha.         */
/*  - NÃO imprimir argv[0] (nome do programa).                                */
/*  - Usar SOMENTE write.                                                     */
/*                                                                            */
/*  O QUE DEVE RETORNAR/IMPRIMIR:                                             */
/*  - Para './ex01/ex01 a b c', a saída é:                                    */
/*      a                                                                      */
/*      b                                                                      */
/*      c                                                                      */
/*                                                                            */
/*  COMO FAZER (PASSO A PASSO):                                               */
/*  - Comece do índice 1 (primeiro parâmetro real).                           */
/*  - Para cada argv[i], imprima a string e depois '\n'.                      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;                     /* Começamos em 1 para pular argv[0].        */
	while (i < argc)           /* Enquanto houver parâmetros…               */
	{
		ft_putstr(argv[i]);    /* Imprime o parâmetro atual.                */
		write(1, "\n", 1);    /* Quebra de linha após cada parâmetro.      */
		i++;                   /* Avançamos para o próximo.                 */
	}
	return (0);
}
```

---

## EX02 — ft_rev_params.c

```c
/* ************************************************************************** */
/*                                                                            */
/*  EX02 — ft_rev_params                                                      */
/*                                                                            */
/*  O QUE O ENUNCIADO QUER:                                                   */
/*  - Imprimir os parâmetros em ORDEM INVERSA, um por linha.                  */
/*  - Usar SOMENTE write.                                                     */
/*                                                                            */
/*  O QUE DEVE RETORNAR/IMPRIMIR:                                             */
/*  - Para './ex02/ex02 a b c', a saída é:                                    */
/*      c                                                                      */
/*      b                                                                      */
/*      a                                                                      */
/*                                                                            */
/*  COMO FAZER (PASSO A PASSO):                                               */
/*  - Comece do último índice útil: argc - 1.                                  */
/*  - Vá decrementando até 1 (não imprime argv[0]).                           */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;               /* Índice do último argumento real.          */
	while (i > 0)               /* Enquanto não chegar ao argv[1]…          */
	{
		ft_putstr(argv[i]);     /* Imprime o parâmetro atual.                */
		write(1, "\n", 1);     /* Quebra de linha.                          */
		i--;                    /* Vai para o argumento anterior.            */
	}
	return (0);
}
```

---

## EX03 — ft_sort_params.c

```c
/* ************************************************************************** */
/*                                                                            */
/*  EX03 — ft_sort_params                                                     */
/*                                                                            */
/*  O QUE O ENUNCIADO QUER:                                                   */
/*  - Ordenar LEXICOGRAFICAMENTE (ordem ASCII) os parâmetros da linha         */
/*    de comando e imprimi-los, um por linha.                                 */
/*  - Usar SOMENTE write.                                                     */
/*                                                                            */
/*  O QUE DEVE RETORNAR/IMPRIMIR:                                             */
/*  - Para './ex03/ex03 zebra alpha Beta 42', a saída é:                      */
/*      42                                                                     */
/*      Beta                                                                   */
/*      alpha                                                                  */
/*      zebra                                                                  */
/*                                                                            */
/*  COMO FAZER (PASSO A PASSO):                                               */
/*  - Implementar uma função de comparação de strings (ft_strcmp).            */
/*  - Fazer uma ordenação simples (ex.: selection sort) em argv[1..argc-1].   */
/*  - Depois imprimir em ordem.                                               */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* ft_putstr: imprime string com write */
static void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

/* ft_strcmp: compara s1 e s2 como strcmp da libc.                            */
/* Retorna <0 se s1 < s2, 0 se iguais, >0 se s1 > s2 (ordem ASCII).          */
static int	ft_strcmp(char *s1, char *s2)
{
	/* Avança enquanto caracteres forem iguais e não chegarmos em '\0'. */
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	/* Converte para unsigned char para evitar comportamento indefinido     */
	/* com caracteres com bit de sinal em arquiteturas diferentes.          */
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	/* Ordenação por seleção (selection sort) diretamente nos ponteiros.    */
	i = 1;
	while (i < argc - 1)              /* i percorre os elementos não ordenados */
	{
		j = i + 1;
		while (j < argc)              /* comparamos argv[j] com argv[i]        */
		{
			if (ft_strcmp(argv[j], argv[i]) < 0)
			{
				/* Troca simples de ponteiros (sem copiar memória das strings). */
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	/* Após ordenar, imprimimos um por linha. */
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
```
