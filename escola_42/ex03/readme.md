## Exercício 03: ft_print_numbers

### Requisitos

- **Função**: `ft_print_numbers`
- **Arquivo**: `ft_print_numbers.c`
- **Diretório**: `ex03/`
- **Protótipo**: `void ft_print_numbers(void);`
- **Funções permitidas**: `write`
- **Descrição**: Criar uma função que exibe todos os dígitos, em ordem crescente, em uma única linha.

### Conceitos Teóricos

Assim como caracteres alfabéticos, dígitos também têm representação ASCII:
- '0' tem o valor decimal 48
- '9' tem o valor decimal 57

Os dígitos são consecutivos na tabela ASCII, assim como as letras.

### Implementação Comentada

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:00:00 by student           #+#    #+#             */
/*   Updated: 2025/04/27 11:00:00 by student           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	digit;

	digit = '0';
	while (digit <= '9')
	{
		write(1, &digit, 1);
		digit++;
	}
}
```

### Explicação do Código

1. **Definição da variável**:
   - `char digit = '0';` - Inicializamos com o caractere '0', não com o valor numérico 0.

2. **Loop while**:
   - `while (digit <= '9')` - Continuamos o loop até chegar ao caractere '9'.

3. **Exibição do dígito**:
   - `write(1, &digit, 1)` - Escrevemos o dígito atual no terminal.

4. **Incremento**:
   - `digit++` - Avançamos para o próximo caractere na tabela ASCII.

### Como Testar

```c
#include <unistd.h>

void	ft_print_numbers(void);

int	main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);  // Adiciona uma quebra de linha no final
	return (0);
}
```

Saída esperada:
```
0123456789
```

### Dicas e Reflexões

- Este exercício ajuda a entender que caracteres numéricos são diferentes de números reais em C.
- Note que usamos `'0'` (caractere) e não `0` (número inteiro).
- A lógica é similar aos exercícios anteriores, apenas mudando o intervalo de caracteres.

---