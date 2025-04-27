## Exercício 05: ft_print_comb

### Requisitos

- **Função**: `ft_print_comb`
- **Arquivo**: `ft_print_comb.c`
- **Diretório**: `ex05/`
- **Protótipo**: `void ft_print_comb(void);`
- **Funções permitidas**: `write`
- **Descrição**: Criar uma função que exibe todas as diferentes combinações de três dígitos diferentes em ordem crescente.

### Conceitos Teóricos

Este exercício é mais complexo e introduz:
- Loops aninhados
- Condições mais elaboradas
- Formação de combinações

Características importantes:
- Os dígitos devem ser diferentes (012 é válido, 011 não é)
- A ordem é crescente (012 é válido, 021 não é)
- As combinações devem ser exibidas em ordem crescente (012, 013, 014...)
- O output deve ser como mostrado no exemplo: "012, 013, 014, ..., 789"

### Implementação Comentada

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:00:00 by student           #+#    #+#             */
/*   Updated: 2025/04/27 12:00:00 by student           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (!(a == '7' && b == '8' && c == '9'))
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}
```

### Explicação do Código

1. **Definição das variáveis**:
   - Criamos três variáveis do tipo `char`: `a`, `b` e `c` para representar cada dígito.

2. **Loops aninhados**:
   - Três loops aninhados, um para cada dígito.
   - `a` vai de '0' a '7' (se `a` fosse '8' ou '9', não haveria dígitos suficientes para `b` e `c`).
   - `b` começa em `a + 1` e vai até '8'.
   - `c` começa em `b + 1` e vai até '9'.

3. **Exibição da combinação**:
   - `write(1, &a, 1); write(1, &b, 1); write(1, &c, 1);` - Exibimos os três dígitos.

4. **Separador**:
   - `if (!(a == '7' && b == '8' && c == '9')) write(1, ", ", 2);` - Adicionamos ", " após cada combinação, exceto a última (789).

### Como Testar

```c
#include <unistd.h>

void	ft_print_comb(void);

int	main(void)
{
	ft_print_comb();
	write(1, "\n", 1);  // Adiciona uma quebra de linha no final
	return (0);
}
```

Saída esperada (parcial):
```
012, 013, 014, ..., 789
```

### Dicas e Reflexões

- Este exercício é significativamente mais complexo que os anteriores.
- Requer um bom entendimento de loops aninhados.
- O desafio está em garantir que:
  - Todos os dígitos sejam diferentes
  - As combinações estejam em ordem crescente
  - A formatação da saída esteja correta (com vírgulas e espaços)
- É normal encontrar dificuldades neste exercício; não desanime!

---

## Conclusão

Estes cinco exercícios representam uma progressão gradual de complexidade, desde operações simples com caracteres até manipulações mais elaboradas de combinações numéricas. Cada um reforça conceitos fundamentais de programação em C, incluindo:

- Loops e iterações
- Condicionais
- Manipulação de caracteres
- Uso da função `write()`
- Lógica de programação

Ao dominar estes exercícios, você estará construindo uma base sólida para desafios mais complexos na Piscine C da Escola 42.