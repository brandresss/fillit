# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandres <brandres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 16:24:29 by brandres          #+#    #+#              #
#    Updated: 2020/02/22 18:42:44 by brandres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = lst.c map.c main.c validation.c frre.c

OBJ = lst.o map.o main.o validation.o frre.o


LBFT = libft/
all: $(NAME)

$(NAME):
	make -C $(LBFT)
	gcc -Wall -Wextra -Werror -o $(NAME) src/lst.c src/map.c src/main.c \
	src/validation.c src/frre.c -I includes/fillit.h -L. libft/libft.a
clean:
	    /bin/rm -f *.o
		make -C $(LBFT) clean

fclean: clean
	    /bin/rm -f $(NAME)
		make -C $(LBFT) fclean
re: fclean all
