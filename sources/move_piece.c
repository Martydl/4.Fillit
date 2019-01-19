/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:50:52 by algautie          #+#    #+#             */
/*   Updated: 2019/01/19 16:29:46 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_convert_coor(int **list, int from, int to)
{
	int i;
	int j;

	i = -1;
	while (list[++i] != NULL)
	{
		j = -1;
		while (++j != 4)
			list[i][j] = list[i][j] + ((list[i][j] / from) * (to - from));
	}
}

int		ft_up_or_left(int *p, int sp, int dec)
{
	int i;
	int tmp;

	i = 0;
	while (i < sp || i < dec)
	{
		tmp = i * sp;
		if (tmp == p[0] || tmp == p[1] || tmp == p[2] || tmp == p[3])
			return (0);
		i++;
	}
	i = -1;
	while (++i != 4)
		p[i] = p[i] - dec;
	return (1);
}

void	ft_upleft(int **list, int size)
{
	int i;

	i = -1;
	while (list[++i] != NULL)
	{
		while (ft_up_or_left(list[i], 1, size))
			;
		while (ft_up_or_left(list[i], size, 1))
			;
	}
}

int		ft_down1left(int *tetri, int size)
{
	int i;

	i = -1;
	while (tetri[++i])
		if(i + size > 15)
			return (-1);
	while (--i >= 0)
		tetri[i] += size;
	while (ft_up_or_left(tetri, size, 1))
		;
	return (0);
}

int		ft_right1(int *tetri, int size)
{
	int i;

	i = -1;
	while (tetri[++i] >= 0)
	{
		if (i + 1 > 15)
			return (-1);
		if (tetri[i] + 1 % size == 0)
		{
			if (ft_down1left(tetri, size) == 0)
				return (0);
			else
				return (-1);
		}
	}
	while (--i >= 0)
		tetri[i] += 1;
	return (0);
}
