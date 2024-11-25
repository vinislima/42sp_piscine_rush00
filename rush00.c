/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:53:02 by vinda-si          #+#    #+#             */
/*   Updated: 2024/11/24 22:33:44 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// aqui prototipamos as funções que vamos usar
// a função ft_putchar escreve um caractere na saída padrão
// a função ft_printcircletrace escreve um caractere de acordo com a posição
// a função ft_dashblank escreve um caractere de acordo com a posição
// a função rush00 escreve um retângulo com bordas de cantos arredondados
void	ft_putchar(char c);
void	ft_printcircletrace(int i, int x);
void	ft_dashblank(int i, int x);
void	rush00(int x, int y);
// a função ft_printcircletrace escreve um caractere de acordo com a posição
// recebe dois inteiros i e x, que são a posição atual e o tamanho da linha
void	ft_printcircletrace(int i, int x)
{
	// se a posição atual for 0 ou a última posição
	// escreve o caractere 'o', pois é um canto
	if (i == 0 || i == x - 1)
		ft_putchar('o');
	// senão escreve o caractere '-', pois é o topo ou a base
	else
		ft_putchar('-');
}
// a função ft_dashblank escreve um caractere de acordo com a posição
// recebe dois inteiros i e x, que são a posição atual e o tamanho da linha
void	ft_dashblank(int i, int x)
{
	// se a posição atual for 0 ou a última posição
	// escreve o caractere '|', pois é uma lateral
	if (i == 0 || i == x - 1)
		ft_putchar ('|');
	// senão escreve um espaço em branco
	// pois é o interior do retângulo
	else
		ft_putchar (' ');
}

// função que escreve um retângulo com bordas de cantos arredondados
// com o caractere 'o' e bordas laterais e superiores com o caractere '-'
// e bordas inferiores com o caractere '|'
void	rush00(int x, int y)
{
	// declaramos as variáveis j e i
	// j é a linha atual e i é a coluna atual
	int	j;
	int	i;
	// se x ou y forem menores ou iguais a 0
	// não faz nada, apenas retorna o controle
	// para o chamador
	if (x <= 0 || y <= 0)
		return ;
	// atribuímos 0 a j
	j = 0;
	// enquanto j for menor que y
	// o laço se repete
	while (j < y)
	{
		// atribuímos 0 a i para cada linha
		// sendo que i é a coluna atual
		i = 0;
		// enquanto i for menor que x
		// o laço se repete
		while (i < x)
		{
			// se estivermos na primeira ou última linha
			// chamamos a função ft_printcircletrace
			if (j == 0 || j == y - 1)
				// passando i e x como argumentos
				// i é a posição atual e x é o tamanho da linha
				// a função escreve o simbolo '-' ou 'o' de acordo com a posição
				ft_printcircletrace(i, x);
			else
				// senão chamamos a função ft_dashblank
				// passando i e x como argumentos
				// i é a posição atual e x é o tamanho da linha
				// a função escreve o simbolo '|' ou ' ' de acordo com a posição
				ft_dashblank(i, x);
			// após escrever o caractere da posição atual
			// incrementamos i para passar para a próxima posição
			i++;
		}
		// após escrever a linha atual inteira com seus caracteres
		// chamamos a função ft_putchar para escrever uma quebra de linha
		ft_putchar('\n');
		// incrementamos j para passar para a próxima linha
		j++;
	}
}
