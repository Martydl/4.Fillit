/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:06:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/17 16:20:42 by mde-laga         ###   ########.fr       */
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

char	*ft_getline(int fd, char *line);
int		ft_verifline(char *line);
char	**ft_cutline(char *line, char **tab);
int		ft_check_neighbours(char *tetri);
void	ft_upleft(int *tetri);
//void	ft_letters(t_piece tetri, int pos);
int		ft_smallest_square(int nb);
char	*ft_create_square(t_piece *list);
int		ft_backtrack(char *square, char **tab, char letter);
int		ft_move_down(char *square, int piece, int size);
void	ft_move_up(char *square, int piece, int size);
void	ft_del_piece(char *square, int letter);
char	*ft_delret(char *piece);
int		**ft_create_list(int **list, char **tab);

#endif
