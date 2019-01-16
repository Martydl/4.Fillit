/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:51:10 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/16 16:43:33 by mde-laga         ###   ########.fr       */
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
	char	*square;

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
	tab = NULL;
	tab = ft_cutline(line, tab);
	free(line);
	i = 0;
	while (tab[i])
	{
		if (ft_check_neighbours(tab[i]) == 0)
			//printf("Piece:\n%s\n\n", tab[i++]);
			i++;
		else
		{
			ft_putstr("error");
			break ;
		}
	}
	ft_upleft(tab);
	ft_letters(tab);
	ft_move_down(tab[1], 1, 4);
	tab = ft_delret(tab, 3);
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
	free(square);
	return (0);
}
