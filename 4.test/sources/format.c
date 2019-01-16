/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:41:03 by algautie          #+#    #+#             */
/*   Updated: 2019/01/16 19:48:33 by mde-laga         ###   ########.fr       */
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

#include <stdio.h>
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
	dprintf(1, "1");
}

void	ft_delret(char *piece)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(piece);
	ft_strdel(&piece);
	if (!(piece = (char*)malloc(sizeof(char) * 17)))
		return ;
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
}




/*char	**ft_tab_new(char **tab_new, int nb_piece)
  {
  int		i;

  if (!(tab_new = (char**)malloc(sizeof(char*) * (nb_piece + 1))))
  return (NULL);
  i = 0;
  while (i < nb_piece)
  {
  if (!(tab_new[i++] = (char*)malloc(sizeof(char) * 17)))
  return (NULL);
  }
  tab_new[nb_piece] = NULL;
  return (tab_new);
  }

  char	**ft_delret(char **tab, int nb_piece)
  {
  char	**tab_new;
  int		i;
  int		j;
  int		k;

  tab_new = NULL;
  tab_new = ft_tab_new(tab_new, nb_piece);
  i = 0;
  while (tab[i])
  {
  j = 0;
  k = 0;
  while (tab[i][j])
  {
  if (tab[i][j] != '\n')
  tab_new[i][k++] = tab[i][j];
  j++;
  }
  tab_new[i][k++] = '\0';
  i++;
  }
  while (i >= 0)
  ft_strdel(&tab[i--]);
  free(tab);
  return (tab_new);
  }*/
