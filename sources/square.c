/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:23:20 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/25 15:30:05 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_smallest_square(int nb_piece)
{
	int		size;

	if (nb_piece == 1)
		size = 2;
	else if (nb_piece == 2)
		size = 3;
	else if (nb_piece >= 3 && nb_piece <= 4)
		size = 4;
	else if (nb_piece >= 5 && nb_piece <= 6)
		size = 5;
	else if (nb_piece >= 7 && nb_piece <= 9)
		size = 6;
	else if (nb_piece >= 10 && nb_piece <= 12)
		size = 7;
	else if (nb_piece >= 13 && nb_piece <= 16)
		size = 8;
	else if (nb_piece >= 17 && nb_piece <= 20)
		size = 9;
	else
		size = 10;
	return (size);
}

char	*ft_create_square(char *square, int size)
{
	int i;

	ft_strdel(&square);
	if (!(square = (char*)malloc(sizeof(char) * (size * size + 1))))
		return (NULL);
	i = -1;
	while (++i != size * size)
		square[i] = '.';
	square[i] = '\0';
	return (square);
}

int		ft_convert_coor(int **list, int from, int to)
{
	int i;
	int j;

	i = -1;
	while (list[++i] != NULL)
	{
		j = -1;
		while (++j != 4)
			if (list[i][j] % from >= to || list[i][j] / from >= to)
				return (-1);
	}
	i = -1;
	while (list[++i] != NULL)
	{
		j = -1;
		while (++j != 4)
			list[i][j] = list[i][j] + ((list[i][j] / from) * (to - from));
	}
	return (1);
}
