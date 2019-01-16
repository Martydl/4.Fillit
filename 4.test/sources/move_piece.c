/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:24:34 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/16 15:41:20 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void	ft_move_down(char *square, int piece, int size)
{
	int i;

	i = size * size;
	while (square[--i])
	{
		if (square[i] == 'A' + piece && square[i + size])
		{
			square[i + size] = square[i];
			square[i] = '.';
		}
		else
			break ;
	}
}

void	ft_move_up(char *square, int piece, int size)
{
	int i;

	i = 0;
	while (square[++i])
	{
		if (square[i] == 'A' + piece && square[i - size])
		{
			square[i - size] = square[i];
			square[i] = '.';
		}
		else
			break ;
	}
}

void	ft_del_piece(char *square, int piece)
{
	int i;

	i = -1;
	while (square[++i])
		if (square[i] == 'A' + piece)
			square[i] = '.';
}
