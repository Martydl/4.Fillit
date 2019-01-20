/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:28:24 by mde-laga          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/20 13:05:33 by mde-laga         ###   ########.fr       */
=======
/*   Updated: 2019/01/20 13:34:40 by mde-laga         ###   ########.fr       */
>>>>>>> b2ee379bf2ef2fb75fa8258e6b38e02464dc065e
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>

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
int		ft_backtrack(char *square, int **list, int from, int size);
int		ft_smallest_square(int nb_tetri);
char	*ft_create_square(char *square, int size);
int		ft_check(char *square, int *tetri, int letter);
void	ft_upleft(int *tetri, int size);
void	ft_upleft_all(int **list, int size);
int		ft_next(int *tetri, int size);
void	ft_del_tetri(char *square, int letter);
int		ft_convert_coor(int **list, int from, int to);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strdel(char **as);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	ft_putstr(char const *s);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);

#endif
