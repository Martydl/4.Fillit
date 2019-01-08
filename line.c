/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:52 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/08 17:58:35 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

/*char	**ft_cutline(char *str)
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
  while (str[j])
  {
  if (str[j] == '\n' && (str[j + 1] == '\n' || !str[j + 1]))
  size++;
  j++;
  }
  dprintf(1, "2");
  if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
  return (NULL);
  j = 0;
  while (str[j])
  {
  while (str[k] != '\n' && str[k + 1] != '\n' && str[k])
  k++;
  printf("k=%d\n", k);
  tab[i] = ft_strsub(str, j, k + 1);
  j = k;
  printf("j=%d\n", j);
  k++;
  i++;
  }
  return (tab);
  }*/

#include <stdio.h>

/*int		ft_check_neighbours(char *str)
{
	int i;
	int count;
	int check;

	i = 0;
	count = 0;
	while (str[i])
	{
		if  (str[i] == '#')
		{
			if (str[i + 1] == '#')
				count++;
			if (str[i - 1] == '#')
				count++;
			if (str[i + 5] == '#')
				count++;
			if (str[i - 5] == '#')
				count++;
			check++;
		}
		i++;
	}
	printf("%d\n", count);
	if (check % 4 != 0)
		return (1);
	//	if (count == 6 || count == 8)
	return (0);
	return (1);
}*/

int		ft_verifline(char *str)
{
	int i;
	int j;
	int k;
	int len;

	i = 0;
	j = 1;
	k = 0;
	len = ft_strlen(str);
	if (len > 545 || str[i] == '\n' || str[len - 2] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\n')
			j++;
		else if ((str[i] == '\n' && str[i + 1] == '\n') || !str[i + 2])
			if (j != 4 || (j = 0))
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

#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*str;

	(void)ac;
	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (!str && (!(str = ft_strnew(1))))
		return (0);
	str = ft_getline(fd, str);
	if (ft_verifline(str) == 0)
		puts(str);
	else
		puts("error");
	free(str);
	return (0);
}
