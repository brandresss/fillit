/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:48:01 by brandres          #+#    #+#             */
/*   Updated: 2020/02/22 17:02:28 by brandres         ###   ########.fr       */
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
	int		save[2];
	char	letter;
	t_list	*list;

	save[1] = 0;
	buf = ft_strnew(21);
	letter = 'A';
	list = NULL;
	while ((save[0] = read(fd, buf, 21)))
	{
		for_err(buf, save[0]);
		if (list == NULL)
			list = create_tetrimino(null_pos(koordin(buf)), \
			max_y(null_pos(koordin(buf))), max_x(null_pos(koordin(buf))), \
			letter++);
		else
			ft_lstadd_end(&list, create_tetrimino(null_pos(koordin(buf)), \
			max_y(null_pos(koordin(buf))), max_x(null_pos(koordin(buf))), \
			letter++));
		save[1] = save[0];
	}
	if ((save[0] == 0 && save[1] == 21) || (save[1] == 0 && save[0] == 0))
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
