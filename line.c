/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:52 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/09 19:40:43 by mde-laga         ###   ########.fr       */
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

int		ft_verifline(char *ver)
{
	int i;
	int j;
	int k;
	int len;
	int hash;

	hash = 0;
	len = ft_strlen(ver);
	i = 0;
	if (len > 545 || ver[i] == '\n' || ver[len - 2] == '\n')
		return (1);
	j = 1;
	k = 0;
	while (ver[i])
	{
		ver[i] == '#' ? hash++ : 0;
		if (ver[i] == '\n' && ver[i - 1] == '\n' && ver[i + 1] == '\n')
			return (1);
		if (ver[i] == '\n' && ver[i + 1] != '\n')
			j++;
		else if ((ver[i] == '\n' && ver[i + 1] == '\n') || !ver[i + 2])
		{
			if (hash != 4 || j != 4)
				return (1);
			j = 0;
			hash = 0;
		}
		if (ver[i] != '\n')
			k++;
		else if ((k != 4 && k != 0) || (k = 0))
			return (1);
		i++;
	}
	return (0);
}

char	**ft_cutline(char *cut, char **tab)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	size = 0;
	while (cut[++i])
		(cut[i] == '\n' && (cut[i + 1] == '\n' || !cut[i + 1])) ? size++ : 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (cut[i] && cut[i + 18])
	{
		if (!(tab[j++] = ft_strsub(cut, i, 19)))
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
	printf("str =\n%s\n", piece);
	printf("wtf = %c\n", piece[23]);
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			if (piece[i + 1] == '#')
				count++;
			if (piece[i - 1] == '#')
				count++;
			if (piece[i + 5] == '#')
				count++;
			if (piece[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*str;
	char	**tabe;
	int		i;

	(void)ac;
	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (!str && (!(str = ft_strnew(1))))
		return (0);
	str = ft_getline(fd, str);
	if (ft_verifline(str) != 0)
	{
		ft_putstr("error");
		return (0);
	}
	tabe = NULL;
	tabe = ft_cutline(str, tabe);
	free(str);
	i = 0;
	while (tabe[i])
	{
		if (ft_check_neighbours(tabe[i]) == 0)
			printf("Piece:\n%s\n\n", tabe[i++]);
		else
		{
			ft_putstr("error");
			break ;
		}
	}
	while (i >= 0)
		ft_strdel(&tabe[i--]);
	free(tabe);
	return (0);
}
