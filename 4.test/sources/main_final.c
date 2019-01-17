/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:20:40 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/17 13:40:47 by mde-laga         ###   ########.fr       */
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

t_piece	*ft_getlist(char *line, t_piece *list, int fd)
{
	if (!line && (!(line = ft_strnew(1))))
		return (NULL);
	line = ft_getline(fd, line);
	if (ft_verifline(line) == -1)
		ft_error();
	list = ft_cutline(line, list);
	ft_strdel(&line);
	return (list);
}

void	ft_formatlist(t_piece *list)
{
	int i;

	i = -1;
	while (list[++i].piece)
	{
		if (ft_check_neighbours(list[i].piece) == -1)
			ft_error();
		ft_upleft(list[i]);
		ft_letters(list[i], i);
		list[i].piece = ft_delret(list[i].piece);
	}
}

#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_piece	*list;

	fd = open(av[1], O_RDONLY);
	line = NULL;
	list = NULL;
	list = ft_getlist(line, list, fd);

	ft_formatlist(list);

	int z = -1;
	while (list[++z].piece)
		printf("type: %c\n%s\n\n", *list[z].type, list[z].piece);

	ft_freetab(list);

	return (0);
}
