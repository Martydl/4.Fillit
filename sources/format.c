/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:41:03 by algautie          #+#    #+#             */
/*   Updated: 2019/01/19 15:32:44 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int		ft_up_or_left(char *l, int sp, int dec)
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

void	ft_upleft(int *tetri)
{
	while (ft_up_or_left(tetri.piece, 1, 5))
		;
	while (ft_up_or_left(tetri.piece, 5, 1))
		;
}*/

/*void	ft_letters(t_piece tetri, int pos)
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
}*/

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

int		*ft_convert_tetri(int *tetri, char *piece)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (piece[++i])
		if (piece[i] == '#')
			tetri[j++] = i;
	tetri[j] = -1;
	ft_strdel(&piece);
	return (tetri);
}

int		**ft_create_list(int **list, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (!(list = (int**)malloc(sizeof(int*) * (i + 1))))
		return (NULL);
	list[i] = NULL;
	while (--i >= 0)
	{
		if (!(list[i] = (int*)malloc(sizeof(int) * 5)))
			return (NULL);
	}
	while (tab[++i])
		list[i] = ft_convert_tetri(list[i], tab[i]);
	free(tab);
	return (list);
}
