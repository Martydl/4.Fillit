/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:41:03 by algautie          #+#    #+#             */
/*   Updated: 2019/01/17 13:17:05 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_up_or_left(char *l, int sp, int dec)
{
	int i;

	i = 0;
	if (l[0] == '#' || l[sp] == '#' || l[2 * sp] == '#' || l[3 * sp] == '#')
		return (0);
	while (l[i] != '\0')
	{
		if (l[i] == '#')
		{
			l[i - dec] = '#';
			l[i] = '.';
		}
		i++;
	}
	return (1);
}

void	ft_upleft(t_piece tetri)
{
	while (ft_up_or_left(tetri.piece, 1, 5))
		;
	while (ft_up_or_left(tetri.piece, 5, 1))
		;
}

void	ft_letters(t_piece tetri, int pos)
{
	int i;

	i = 0;
	while (tetri.piece[i])
	{
		if (tetri.piece[i] == '#')
			tetri.piece[i] = 'A' + pos;
		i++;
	}
	*tetri.type = 'A' + pos;
}

char	*ft_delret(char *piece)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(piece);
	ft_strdel(&piece);
	if (!(piece = (char*)malloc(sizeof(char) * 17)))
		return (NULL);
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] != '\n')
			piece[j++] = tmp[i];
		i++;
	}
	piece[j] = '\0';
	ft_strdel(&tmp);
	return (piece);
}
