/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:30:00 by student           #+#    #+#             */
/*   Updated: 2025/04/27 11:30:00 by student           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_is_negative(int n)
{
    if (n < 0)
        write(1, "N", 1);
    else
        write(1, "P", 1);
}

void ft_is_negative(int n);

int main(void)
{
    ft_is_negative(-42); // Deve exibir 'N'
    ft_is_negative(0);   // Deve exibir 'P'
    ft_is_negative(42);  // Deve exibir 'P'
    write(1, "\n", 1);   // Adiciona uma quebra de linha no final
    return (0);
}