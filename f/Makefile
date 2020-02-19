# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandres <brandres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 16:24:29 by brandres          #+#    #+#              #
#    Updated: 2020/02/19 23:08:06 by brandres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = lst.c map.c main.c validation.c

OBJ = lst.o map.o main.o validation.o


LBFT = libft/
all: $(NAME)

$(NAME):
	make -C $(LBFT)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I includes/fillit.h -L. libft/libft.a
clean:
	    /bin/rm -f *.o

fclean: clean
	    /bin/rm -f $(NAME)

re: fclean all
