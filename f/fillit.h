#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

// создает список (и это тоже из либы)
typedef struct		s_list
{
	char			*content;
	char			letter;
	struct s_list	*next;
}					t_list;

t_list      *create_tetrimino(char *buf, char letter);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstadd_end(t_list **alst, t_list *new);
char    **map(int size);
int     suchka(t_list *tetrim, char **maps, int x, int y, int size);
void    get_full(t_list *tetrim, char **maps, int x, int y);
int     recurs(char **maps, t_list *tetrim, int size);
void    print_map(char **map, int size);
void	kabel(int size, t_list *tetrim);
t_list   *reader(const int fd);

#endif
