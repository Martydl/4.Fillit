/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:06:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/12 14:56:16 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_getline(int fd, char *line);
int		ft_verifline(char *line);
char	**ft_cutline(char *line, char **tab);
int		ft_check_neighbours(char *piece);
void	ft_upleft(char **tab);
void	ft_letters(char **tab);

#endif
