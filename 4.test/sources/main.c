/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:51:10 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/16 19:47:44 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
void	ft_error()
{
	ft_putstr("error\n");
	exit(-1);
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
		ft_delret(list[i].piece);
		i++;
	}

	int z = -1;
	while (list[++z].piece != NULL)
		printf("type: %c\n%s\n\n", *list[z].type, list[z].piece);

/*	ft_move_down(tab[1], 1, 4);
	ft_del_piece(tab[2], 2);
	i = 0;
	while (tab[i])
		printf("Piece:\n%s\n\n", tab[i++]);
	if (!(square = ft_create_square(tab)))
	{
		ft_putstr("error");
		return (0);
	}
	printf("square len = %ld\n", ft_strlen(square));
	while (i >= 0)
		ft_strdel(&tab[i--]);
	free(tab);
	free(square);*/
	return (0);
}
