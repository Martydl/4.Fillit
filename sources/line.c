/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:52 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/16 16:39:19 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_getline(int fd, char *line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strdup(line);
		ft_strdel(&line);
		if (!(line = ft_strjoin(tmp, buf)))
			return (0);
		ft_strdel(&tmp);
	}
	if (ret == -1)
		return (0);
	return (line);
}

int		ft_verifstuff(char *line, int j, int k, int hash)
{
	int i;

	i = 0;
	while (line[i])
	{
		line[i] == '#' ? hash++ : 0;
		if (line[i] == '\n' && line[i - 1] == '\n' && line[i + 1] == '\n')
			return (-1);
		if (line[i] == '\n' && line[i + 1] != '\n')
			j++;
		else if ((line[i] == '\n' && line[i + 1] == '\n') || !line[i + 2])
		{
			if (hash != 4 || j != 4)
				return (-1);
			j = 0;
			hash = 0;
		}
		if (line[i] != '\n')
			k++;
		else if ((k != 4 && k != 0) || (k = 0))
			return (-1);
		i++;
	}
	return (0);
}

int		ft_verifline(char *line)
{
	int j;
	int k;
	int len;
	int hash;

	hash = 0;
	len = ft_strlen(line);
	if (len > 545)
		return (-1);
	j = 1;
	k = 0;
	if (ft_verifstuff(line, j, k, hash) != 0)
		return (-1);
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
