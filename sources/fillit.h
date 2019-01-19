/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:06:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/19 14:15:08 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct	s_piece
{
	char	*piece;
	int		*type;
}				t_piece;

void	ft_error(void);
char	*ft_getline(int fd, char *line);
int		ft_verifline(char *line);
char	**ft_cutline(char *line, char **tab);
int		ft_check_neighbours(char *tetri);
char	*ft_delret(char *piece);
int		**ft_create_list(int **list, char **tab);
int		ft_backtrack(char *square, char **tab, char letter);
int		ft_smallest_square(int nb);
char	*ft_create_square(int **list);
void	ft_upleft(int *tetri);
void	ft_del_piece(char *square, int letter);

#endif
