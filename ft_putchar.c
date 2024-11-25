/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:42:24 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/24 22:14:02 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// adicionar a biblioteca unistd.h para usar a função write
#include <unistd.h>
// a função ft_putchar recebe um char e imprime na tela
void	ft_putchar(char c);

void	ft_putchar(char c)
{
	// a função write recebe 3 argumentos, o primeiro é o descritor
	// de arquivo, o segundo é o endereço da variável que contém o
	// caractere a ser impresso e o terceiro é o tamanho do caractere
	write(1, &c, 1);
}
