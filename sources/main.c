/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:20:40 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/19 18:21:52 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(-1);
}

void	ft_freetab(t_piece *tab)
{
	int i;

	i = 0;
	while (tab[i].piece)
		i++;
	while (i >= 0)
	{
		ft_memdel((void**)&tab[i].piece);
		ft_memdel((void**)&tab[i].type);
		i--;
	}
	free(tab);
}

char	**ft_getlist(char *line, char **tab, int fd)
{
	if (!line && (!(line = ft_strnew(1))))
		return (NULL);
	line = ft_getline(fd, line);
	if (ft_verifline(line) == -1)
		ft_error();
	tab = ft_cutline(line, tab);
	ft_strdel(&line);
	return (tab);
}

int		**ft_formatlist(int **list, char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		if (ft_check_neighbours(tab[i]) == -1)
			ft_error();
		tab[i] = ft_delret(tab[i]);
	}
	list = ft_create_list(list, tab);
	return(list);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**tab;
	int		**list;
	char	*square;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	line = NULL;
	tab = NULL;
	tab= ft_getlist(line, tab, fd);
	list = NULL;
	list = ft_formatlist(list, tab);

	square = NULL;
	square = ft_create_square(square, 4);
	puts(square);




	int z = -1;
	while (list[++z])
		printf("Pos = %d ; %d ; %d ; %d\n\n", list[z][0], list[z][1], list[z][2], list[z][3]);

/*	square = ft_create_square(list);
	dprintf(1, "\n%s\n\n", square);
	ft_freetab(list);*/

	return (0);
}
