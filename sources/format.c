/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:41:03 by algautie          #+#    #+#             */
/*   Updated: 2019/01/12 14:41:52 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_letters(char **tab)
{
	int i;
	int j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == '#')
				tab[j][i] = 'A' + j;
			i++;
		}
		j++;
	}
}

int		ft_up_or_left(char *l, int sp, int dec)
{
	int i;

	i = 0;
	if (l[0] == '#' || l[sp] == '#' || l[2 * sp]  == '#' || l[3 * sp] == '#')
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

void	ft_upleft(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		while (ft_up_or_left(tab[i], 1, 5))
			;
		while (ft_up_or_left(tab[i], 5, 1))
			;
		i++;
	}
}
