/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:52 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/09 18:13:02 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_getline(int fd, char *str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(tmp, buf)))
			return (0);
		free(tmp);
	}
	if (ret == -1)
		return (0);
	return (str);
}

int		ft_verifline(char *str)
{
	int i;
	int j;
	int k;
	int len;
	int hash;

	i = 0;
	j = 1;
	k = 0;
	hash = 0;
	len = ft_strlen(str);
	if (len > 545 || str[i] == '\n' || str[len - 2] == '\n')
		return (1);
	while (str[i])
	{
		str[i] == '#' ? hash++ : hash;
		if (str[i] == '\n' && str[i + 1] != '\n')
			j++;
		else if ((str[i] == '\n' && str[i + 1] == '\n') || !str[i + 2])
			if (hash != 4 || j != 4 || (j = 0) || (hash = 0))
				return (1);
		if (str[i] == '\n' && str[i - 1] == '\n' && str[i + 1] == '\n')
			return (1);
		if (str[i] != '\n')
			k++;
		else if ((k != 4 && k != 0) || (k = 0))
			return (1);
		i++;
	}
	return (0);
}

char	**ft_cutline(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;
	int		size;

	i = 0;
	j = 0;
	k = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || !str[i + 1]))
			size++;
		i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i + 18])
	{
		tab[k++] = ft_strsub(str, i, 19);
		i += 21;
	}
	tab[k] = NULL;
	return (tab);
}

int		ft_check_neighbours(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				count++;
			if (str[i - 1] == '#')
				count++;
			if (str[i + 5] == '#')
				count++;
			if (str[i - 5] == '#')
				count++;
		}
		i++;
	}
	printf("%d\n", count);
	if (count == 6 || count == 8)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*str;
	char	**tab;
	int		i;

	(void)ac;
	i = 0;
	str = NULL;
	tab = NULL;
	fd = open(av[1], O_RDONLY);
	if (!str && (!(str = ft_strnew(1))))
		return (0);
	str = ft_getline(fd, str);
	if (ft_verifline(str) != 0)
	{
		ft_putstr("error");
		return (0);
	}
	tab = ft_cutline(str);
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
	free(str);
	while (i <= 0)
		free(tab[i--]);
	free(tab);
	return (0);
}
