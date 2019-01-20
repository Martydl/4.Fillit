/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:25:50 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/20 15:53:18 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(-1);
}

/*void	ft_freetab(t_piece *tab)
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
}*/

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

void	ft_print_sq(char *square)
{
	int		i;
	int		len;
	int		size;

	i = 0;
	size = 2;
	len = ft_strlen(square);
	while (size * size != len)
		size++;
	while (square[i] != '\0')
	{
		if (i % size == 0 && i != 0)
			ft_putstr("\n");
		write(1, &square[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**tab;
	int		**list;
	char	*square;
	int		nb;
	int		size;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	line = NULL;
	tab = NULL;
	tab = ft_getlist(line, tab, fd);
	list = NULL;
	list = ft_formatlist(list, tab);

	nb = 0;
	while (list[nb])
		nb++;
	size = ft_smallest_square(nb);
	square = NULL;
	square = ft_create_square(square, size);
	ft_upleft_all(list, 4);
	ft_convert_coor(list, 4, size);

	int z = -1;
	while (list[++z])
		printf("Pos = %d ; %d ; %d ; %d\n\n", list[z][0], list[z][1], list[z][2], list[z][3]);

	dprintf(1, "%s\n\n", square);
	ft_backtrack(square, list, size, nb);
	ft_print_sq(square);
	return (0);
}
