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

#endif