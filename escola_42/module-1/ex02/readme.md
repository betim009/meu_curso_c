## Exercício 02: ft_print_reverse_alphabet

### Requisitos

- **Função**: `ft_print_reverse_alphabet`
- **Arquivo**: `ft_print_reverse_alphabet.c`
- **Diretório**: `ex02/`
- **Protótipo**: `void ft_print_reverse_alphabet(void);`
- **Funções permitidas**: `write`
- **Descrição**: Criar uma função que exibe o alfabeto em minúsculas, em ordem decrescente, começando da letra 'z', em uma única linha.

### Conceitos Teóricos

Este exercício é similar ao anterior, mas com a direção invertida:
- Começamos com 'z' (valor ASCII 122)
- Terminamos com 'a' (valor ASCII 97)
- Decrementamos em vez de incrementar

### Implementação Comentada

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:30:00 by student           #+#    #+#             */
/*   Updated: 2025/04/27 10:30:00 by student           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = 'z';
	while (letter >= 'a')
	{
		write(1, &letter, 1);
		letter--;
	}
}
```

### Explicação do Código

1. **Definição da variável**:
   - `char letter = 'z';` - Inicializamos a variável com 'z'.

2. **Loop while**:
   - `while (letter >= 'a')` - Continuamos o loop enquanto o caractere for maior ou igual a 'a'.

3. **Exibição do caractere**:
   - `write(1, &letter, 1)` - Escrevemos o caractere atual no terminal.

4. **Decremento**:
   - `letter--` - Recuamos para o caractere anterior na tabela ASCII.

### Como Testar

```c
#include <unistd.h>

void	ft_print_reverse_alphabet(void);

int	main(void)
{
	ft_print_reverse_alphabet();
	write(1, "\n", 1);  // Adiciona uma quebra de linha no final
	return (0);
}
```

Saída esperada:
```
zyxwvutsrqponmlkjihgfedcba
```

### Dicas e Reflexões

- Este exercício reforça o entendimento de loops e caracteres em C.
- A principal diferença em relação ao exercício anterior é a direção do loop.
- É uma boa oportunidade para entender o operador de decremento (`--`).

---

