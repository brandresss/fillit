/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofya_stepanova <sofya_stepanova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 22:17:01 by brandres          #+#    #+#             */
/*   Updated: 2020/02/22 01:35:58 by sofya_stepa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_list
{
	char			*content;
	char			letter;
	struct s_list	*next;
	int				max_x;
	int				max_y;
}					t_list;

t_list	*create_tetrimino(char *buf, char max_x, char max_y, char letter);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstadd_end(t_list **alst, t_list *new);
char	**map(int size);
int		suchka(t_list *tetrim, char **maps, int x, int y, int size);
void	get_full(t_list *tetrim, char **maps, int x, int y);
int		recurs(char **maps, t_list *tetrim, int size);
void	print_map(char **map, int size);
void	kabel(t_list *tetrim);
t_list	*reader(const int fd);
int		checker(int save, char *arr);
int		connections(char *arr);
char	*null_pos(char *koord);
char	*koordin(char *buf);
char	max_y(char *koord);
char	max_x(char *koord);
void	del_let(char **maps, char let);
char	*right_pos(char *koord, int tmp, int c);

#endif
