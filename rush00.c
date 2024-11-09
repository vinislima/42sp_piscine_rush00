/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:53:02 by vinda-si          #+#    #+#             */
/*   Updated: 2024/08/18 10:08:10 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_printcircletrace(int i, int x);
void	ft_dashblank(int i, int x);
void	rush00(int x, int y);

void	ft_printcircletrace(int i, int x)
{
	if (i == 0 || i == x - 1)
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	ft_dashblank(int i, int x)
{
	if (i == 0 || i == x - 1)
		ft_putchar ('|');
	else
		ft_putchar (' ');
}

void	rush00(int x, int y)
{
	int	j;
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (j == 0 || j == y - 1)
				ft_printcircletrace(i, x);
			else
				ft_dashblank(i, x);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
