/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:39:45 by algautie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/23 16:19:39 by mde-laga         ###   ########.fr       */
=======
/*   Updated: 2019/01/21 18:36:56 by mde-laga         ###   ########.fr       */
>>>>>>> 0b8815b524640a030b156c744cce3bbd245f4d29
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_smallest_square(int nb_piece)
{
	int		size;

	if (nb_piece == 1)
		size = 2;
	else if (nb_piece== 2)
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

int		ft_del_tetri(char *square, int letter)
{
	int i;
	int ret;

	i = -1;
	ret = -1;
	while (square[++i])
		if (square[i] == 'A' + letter && (square[i] = '.'))
			ret = 0;
	return (ret);
}

int		ft_check(char *square, int *tetri, int letter)
{
	int i;

	i = -1;
	while (++i < 4)
		if (square[tetri[i]] != '.')
			return (-1);
	while (--i >= 0)
		square[tetri[i]] = 'A' + letter;
	return (1);
}

int		ft_backtrack(char **square, int **list, int size, int nb)
{
	static int	z = 0;

	if (z == nb)
		return (1);

	/*while (1)
	  {
	  if (placement == 1)
	  if(backtrack(piece next)== 1)
	  return (1);
	  if (decale != 1)
	  clear piece;
	  break;
	  }
	  if (z == 0)
	  free
	  aggrandir carre
	  if(backtrac(piece now)k == 1)
	  return (1);
*/
	if (ft_del_tetri(*square, z) == -1 || ft_next(list[z], size) == 1)
	{
		while (1)
		{
			if (ft_check(*square, list[z], z) == 1)
			{
				z++;
				if (ft_backtrack(square, list, size, nb) == 1)
					return (1);
			}
			if (ft_next(list[z], size) != 1)
				break ;
		}
<<<<<<< HEAD
=======
		else if (z == 0)
		{
			ft_upleft_all(list, size);
			ft_convert_coor(list, size, size + 1);
			*square = ft_create_square(*square, ++size);
			if (ft_backtrack(square, list, size, nb))
				return (1);
		}
		else
			break ;
>>>>>>> 0b8815b524640a030b156c744cce3bbd245f4d29
	}
	if (z == 0)
	{
		ft_upleft_all(list, size);
		ft_convert_coor(list, size, size + 1);
		*square = ft_create_square(*square, ++size);
	}
	else
		ft_upleft(list[z--], size);
	if (ft_backtrack(square, list, size, nb))
		return (1);
	return (0);
}
