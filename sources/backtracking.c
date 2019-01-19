/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:39:45 by algautie          #+#    #+#             */
/*   Updated: 2019/01/19 18:23:09 by mde-laga         ###   ########.fr       */
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

void	ft_del_tetri(char *square, int letter)
{
	int i;

	i = -1;
	while (square[++i])
		if (square[i] == 'A' + letter)
			square[i] = '.';
}

int		ft_check(char *square, int *tetri, int size)
{
	int i;

	i = -1;
	while (tetri[++i] != -1)
		if (square[tetri[i]] != '.')
		{
			if (ft_next(tetri, size) == -1)
				return (-1);
			if (ft_check(square, tetri, size) == -1)
				return (-1);
		}
	return (0);
}


int		ft_backtrack(char *square, char **tab)
{
	return (0);
}
