/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:51:10 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/12 14:56:44 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**tab;
	int		i;

	(void)ac;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (!line && (!(line = ft_strnew(1))))
		return (0);
	line = ft_getline(fd, line);
	if (ft_verifline(line) != 0)
	{
		ft_putstr("error");
		return (0);
	}
	tab = NULL;
	tab = ft_cutline(line, tab);
	free(line);
	i = 0;
	while (tab[i])
	{
		if (ft_check_neighbours(tab[i]) == 0)
			printf("Piece:\n%s\n\n", tab[i++]);
		else
		{
			ft_putstr("error");
			break ;
		}
	}
	ft_upleft(tab);
	ft_letters(tab);
	i = 0;
	while (tab[i])
		printf("Piece:\n%s\n\n", tab[i++]);
	while (i >= 0)
		ft_strdel(&tab[i--]);
	free(tab);
	return (0);
}
