/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:06:22 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/16 18:57:45 by mde-laga         ###   ########.fr       */
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

typedef struct	s_piece
{
	char	*piece;
	int		pos;
}				t_piece;

char	*ft_getline(int fd, char *line);
int		ft_verifline(char *line);
t_piece	*ft_cutline(char *line, t_piece *list);
int		ft_check_neighbours(char *piece);
void	ft_upleft(t_piece *list);
void	ft_letters(t_piece *list);
int		ft_smallest_square(int nb);
char	*ft_create_square(char **tab);
int		ft_backtrack(char *square, char **tab, char letter);
void	ft_move_down(char *square, int piece, int size);
void	ft_move_up(char *square, int piece, int size);
void	ft_del_piece(char *square, int piece);
void	ft_delret(char *piece);

#endif
