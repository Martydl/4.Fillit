/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:39:45 by algautie          #+#    #+#             */
/*   Updated: 2019/01/19 14:28:48 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_smallest_square(int nb)
{
	int		size;

	if (nb == 1)
		size = 2;
	else if (nb == 2)
		size = 3;
	else if (nb >= 3 && nb <= 4)
		size = 4;
	else if (nb >= 5 && nb <= 6)
		size = 5;
	else if (nb >= 7 && nb <= 9)
		size = 6;
	else if (nb >= 10 && nb <= 12)
		size = 7;
	else if (nb >= 13 && nb <= 16)
		size = 8;
	else if (nb >= 17 && nb <= 20)
		size = 9;
	else
		size = 10;
	return (size);
}

int		ft_check_position(char *square, char *piece, int size, int pos)
{
	int		i;
	int		line;

	line = 0;
	(void)pos;
	while (line != 4)
	{
		i = -1;
		dprintf(1, "\nline value is : %d\n", line);
		while (++i != 4)
			if (/*(line * size - pos < line * 4) || */(piece[line * 5  + i] != '.'
						&& square[line * size + i] != '.'))
				return (0);
		line++;
	}
	return (1);
}

int		ft_fit(char *square, char *piece, int size)
{
	int		pos;

	pos = 0;
	while (!(ft_check_position(square, piece, size, pos)))
	{
		pos++;
		if (square[pos] == '\0')
			return (0);
	}
	return (1);
}

/*char	*ft_create_square(int **list)
{
	int		nb_pieces;
	int		size;
	char	*square;
	int		i;

	nb_pieces = 0;
	while (list[nb_pieces].piece != NULL)
		nb_pieces++;
	size = ft_smallest_square(nb_pieces);
	if (!(square = (char*)malloc(sizeof(char) * size * size + 1)))
		return (NULL);
	square[size * size] = '\0';
	i = -1;
	while (++i != size * size)
		square[i] = '.';
//	dprintf(1, "ft_check_position ret = %d\n", ft_check_position(square, tab[3], size, 1));
	return (square);
}*/

/*int		ft_backtrack(char *square, char **tab, char letter)
{
	return (0);
}*/
