# RUSH 00

Rush 00 is a collaborative project from the 42's Piscine C programme. Participants must implement functions to generate rectangular patterns of varying dimensions, adhering to strict coding standards.

**Files**:

- `main.c`: Entry point for testing the `rush` function.
- `ft_putchar.c`: A helper function for character output.
- `rush0X.c`: Contains the implementation of a specific rush function, where `0X` represents the designated rush number.
- **Functionality**:
    
    The `rush(x, y)` function must produce a rectangle using specific characters (`o`, `-`, `|`, `/`, `\`, etc.) based on the given dimensions `x` (width) and `y` (height). Examples include rectangles, single lines, and corner cases like 1x1 squares.
    
- **Rules and Guidelines**:
    - The program must compile with `Wall -Wextra -Werror` using `cc`.
    - Adherence to the 42 coding norm is mandatory.
    - Errors should be handled gracefully without crashes or infinite loops.
    - Peer evaluations assess code functionality and team members' understanding.

Rush 00 was my first "big” project at 42, and despite being challenging, my team successfully completed it. However, as with most things at 42, the details are critical—we overlooked placing the project in the correct folder. 

Participants enhance their ability to work collaboratively, adhere to coding standards, and develop a deeper understanding of output functions and error management.

**Functions:**

- `ft_putchar` : This helper function outputs a single character to the standard output using the `write` system call. It’s used throughout the program to display the rectangle's structure.
- `ft_printcircletrace` : This function determines what character to print for the top and bottom borders of the rectangle. It prints `'o'` for the corners (`i == 0` or `i == x - 1`) and `'-'` for the edges between the corners.
- `ft_dashblank` : This function determines what character to print for the sides and interior of the rectangle. It prints `'|'` for the vertical sides (`i == 0` or `i == x - 1`) and spaces (`' '`) for the inner part of the rectangle.
- `rush00` :
    - This is the main function responsible for generating the rectangle.
    - It takes the dimensions `x` (width) and `y` (height) as input.
    - It uses nested loops:
        - The outer loop (`j`) iterates through each row.
        - The inner loop (`i`) handles each column within the current row.
    - Depending on the row (`j`) and column (`i`) indices:
        - For the first and last rows (`j == 0` or `j == y - 1`), it calls `ft_printcircletrace` to draw the top/bottom borders.
        - For intermediate rows, it calls `ft_dashblank` to create vertical borders and spaces.
- `main`: This is the entry point of the program. It calls `rush00` with the parameters, in the example, `x = 5` and `y = 3` to generate a rectangle of width 5 and height 3.
    
    ```c
    o---o
    |   |
    o---o
    ```
    

## Usage

Uncomment the main and use the command below.

```c
cc -Wall -Wextra -Werror {files}

```

---
<details>
        <summary>Codes:</summary>

- [ft_putchar:](https://github.com/vinislima/42sp_piscine_rush00/blob/main/ft_putchar.c)
    
    ```c
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
    
    ```
    
- [rush00:](https://github.com/vinislima/42sp_piscine_rush00/blob/main/rush00.c)
    
    ```c
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
    
    ```
    
- [main:](https://github.com/vinislima/42sp_piscine_rush00/blob/main/main.c)
    
    ```c
    /* ************************************************************************** */
    /*                                                                            */
    /*                                                        :::      ::::::::   */
    /*   main.c                                             :+:      :+:    :+:   */
    /*                                                    +:+ +:+         +:+     */
    /*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
    /*                                                +#+#+#+#+#+   +#+           */
    /*   Created: 2024/08/18 08:56:34 by vinda-si          #+#    #+#             */
    /*   Updated: 2024/11/24 22:14:34 by vinda-si         ###   ########.fr       */
    /*                                                                            */
    /* ************************************************************************** */
    
    // a função rush00 é um protótipo de função que recebe dois inteiros
    void	rush00(int x, int y);
    
    int	main(void)
    {
    	// chamando a função rush00 com os valores 5 e 3
    	rush00(5, 3);
    	// retornando 0 que é o valor padrão de sucesso
    	return (0);
    }
    
    ```
</details>
