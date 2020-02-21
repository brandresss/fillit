/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofya_stepanova <sofya_stepanova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 22:11:09 by brandres          #+#    #+#             */
/*   Updated: 2020/02/22 01:15:52 by sofya_stepa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

t_list	*reader(const int fd)
{
	char	*buf;
	int		save;
	char	letter;
	t_list	*list;
	int		save1;

	save1 = 0;
	buf = ft_strnew(21);
	letter = 'A';
	list = NULL;
	while ((save = read(fd, buf, 21)))
	{
		if (save != 20 && save != 21)
			ft_error();
		if ((checker(save, buf)) != 5)
		{
			ft_strdel(&buf);
			ft_error();
		}
		if (list == NULL)
			list = create_tetrimino(null_pos(koordin(buf)), \
			max_y(null_pos(koordin(buf))), max_x(null_pos(koordin(buf))), \
			letter++);
		else
			ft_lstadd_end(&list, create_tetrimino(null_pos(koordin(buf)), \
			max_y(null_pos(koordin(buf))), max_x(null_pos(koordin(buf))), \
			letter++));
		save1 = save;
	}
	if ((save == 0 && save1 == 21) || (save1 == 0 && save == 0))
		ft_error();
	return (list);
}

void	kabel(t_list *tetrim)
{
	char	**maps;
	int		size;

	size = 2;
	maps = map(size);
	while (recurs(maps, tetrim, size) == 2)
	{
		free(maps);
		size++;
		maps = map(size);
	}
	print_map(maps, size);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error();
	}
	list = reader(fd);
	close(fd);
	kabel(list);
	return (0);
}

void	del_let(char **maps, char let)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (maps[j] != NULL)
	{
		i = 0;
		while (maps[j][i] != '\0')
		{
			if (maps[j][i] == let)
				maps[j][i] = '.';
			i++;
		}
		j++;
	}
}
