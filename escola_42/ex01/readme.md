# Guia de Estudo: Piscine C00 (Exercícios 01-05)

Este guia aborda os exercícios 01 módulo C00 da Piscine da Escola 42.

## Exercício 01: ft_print_alphabet

### Requisitos

- **Função**: `ft_print_alphabet`
- **Arquivo**: `ft_print_alphabet.c`
- **Diretório**: `ex01/`
- **Protótipo**: `void ft_print_alphabet(void);`
- **Funções permitidas**: `write`
- **Descrição**: Criar uma função que exibe o alfabeto em minúsculas, em ordem crescente, começando da letra 'a', em uma única linha.

### Conceitos Teóricos

#### O Alfabeto na Tabela ASCII

Em programação C, caracteres são representados usando a tabela ASCII:
- 'a' tem o valor decimal 97
- 'z' tem o valor decimal 122
- Caracteres consecutivos têm valores consecutivos na tabela ASCII

#### Loops em C

Para este exercício, precisamos de um loop que:
- Comece em 'a'
- Termine em 'z'
- Imprima cada caractere

### Implementação Comentada

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:00:00 by student           #+#    #+#             */
/*   Updated: 2025/04/27 10:00:00 by student           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	letter;

	letter = 'a';
	while (letter <= 'z')
	{
		write(1, &letter, 1);
		letter++;
	}
}
```

### Explicação do Código

1. **Definição da variável**:
   - `char letter = 'a';` - Inicializamos uma variável para armazenar o caractere atual, começando com 'a'.

2. **Loop while**:
   - `while (letter <= 'z')` - Continuamos o loop enquanto o caractere for menor ou igual a 'z'.

3. **Exibição do caractere**:
   - `write(1, &letter, 1)` - Escrevemos o caractere atual no terminal (saída padrão).

4. **Incremento**:
   - `letter++` - Avançamos para o próximo caractere na tabela ASCII.

### Como Testar

```c
#include <unistd.h>

void	ft_print_alphabet(void);

int	main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);  // Adiciona uma quebra de linha no final
	return (0);
}
```

Saída esperada:
```
abcdefghijklmnopqrstuvwxyz
```

### Dicas e Reflexões

- Este exercício ensina sobre loops e a relação entre caracteres e seus valores numéricos na tabela ASCII.
- É um exercício simples, mas fundamental para entender como manipular caracteres em C.
- Observe que não usamos `printf()` ou outras funções de alto nível, mas sim `write()` diretamente.

---