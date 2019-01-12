/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:52 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/12 11:42:30 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_getline(int fd, char *line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = line;
		if (!(line = ft_strjoin(tmp, buf)))
			return (0);
		free(tmp);
	}
	if (ret == -1)
		return (0);
	return (line);
}

int		ft_verifline(char *line)
{
	int i;
	int j;
	int k;
	int len;
	int hash;

	hash = 0;
	len = ft_strlen(line);
	i = 0;
	if (len > 545 || line[i] == '\n' || line[len - 2] == '\n')
		return (1);
	j = 1;
	k = 0;
	while (line[i])
	{
		line[i] == '#' ? hash++ : 0;
		if (line[i] == '\n' && line[i - 1] == '\n' && line[i + 1] == '\n')
			return (1);
		if (line[i] == '\n' && line[i + 1] != '\n')
			j++;
		else if ((line[i] == '\n' && line[i + 1] == '\n') || !line[i + 2])
		{
			if (hash != 4 || j != 4)
				return (1);
			j = 0;
			hash = 0;
		}
		if (line[i] != '\n')
			k++;
		else if ((k != 4 && k != 0) || (k = 0))
			return (1);
		i++;
	}
	return (0);
}

char	**ft_cutline(char *line, char **tab)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	size = 0;
	while (line[++i])
		(line[i] == '\n' && (!line[i + 1] || line[i + 1] == '\n')) ? size++ : 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (line[i] && line[i + 18])
	{
		if (!(tab[j++] = ft_strsub(line, i, 19)))
			return (NULL);
		i += 21;
	}
	tab[j] = NULL;
	return (tab);
}

int		ft_check_neighbours(char *piece)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			if (i + 1 <= 18 && piece[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && piece[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && piece[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && piece[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (0);
	return (1);
}

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
	ft_letters(tab);
	i = 0;
	while (tab[i])
		printf("Piece:\n%s\n\n", tab[i++]);
	while (i >= 0)
		ft_strdel(&tab[i--]);
	free(tab);
	return (0);
}
