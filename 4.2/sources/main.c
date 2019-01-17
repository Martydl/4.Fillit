/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:51:10 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/17 13:39:19 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
void	ft_error()
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

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_piece	*list;
	int		i;
//	char	*square;

	(void)ac;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (!line && (!(line = ft_strnew(1))))
		return (0);
	line = ft_getline(fd, line);
	if (ft_verifline(line) == -1)
	{
		ft_putstr("error");
		return (0);
	}
	list = NULL;
	list = ft_cutline(line, list);
	ft_strdel(&line);
	i = 0;
	while (list[i].piece != NULL)
	{
		if (ft_check_neighbours(list[i].piece) == -1)
			ft_error();
		ft_upleft(list[i]);
		ft_letters(list[i], i);
		list[i].piece = ft_delret(list[i].piece);
		i++;
	}
//	ft_move_down(tab[1], 1, 4);
//	ft_del_piece(tab[2], 2);
	i = -1;
	while (list[++i].piece != NULL)
		printf("type: %c\n%s\n\n", *list[i].type, list[i].piece);
	ft_freetab(list);
/*	if (!(square = ft_create_square(tab)))
	{
		ft_putstr("error");
		return (0);
	}
	printf("square len = %ld\n", ft_strlen(square));
	free(square);*/
	return (0);
}
