/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:36:58 by brandres          #+#    #+#             */
/*   Updated: 2020/02/22 18:48:30 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**map(int size)
{
	int		i;
	char	**maps;

	i = 0;
	maps = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		maps[i] = (char *)malloc(sizeof(char) * (size + 1));
		ft_memset(maps[i], 46, size);
		maps[i][size] = '\0';
		i++;
	}
	maps[i] = NULL;
	return (maps);
}

int		possib(t_list *tetrim, char **maps, int xy[3], int size)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if ((tetrim->max_y + xy[1]) > size - 1 + '0')
		return (2);
	if ((tetrim->max_x + xy[0]) > size - 1 + '0')
		return (0);
	while (i <= 6 && j <= 7)
	{
		if (maps[tetrim->content[i] - '0' + xy[1]]\
		[tetrim->content[j] - '0' + xy[0]] != '.')
			return (0);
		i += 2;
		j += 2;
	}
	return (1);
}

void	get_full(t_list *tetrim, char **maps, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i <= 6 && j <= 7)
	{
		maps[tetrim->content[i] - '0' + y][tetrim->content[j] - '0' + x] = \
		tetrim->letter;
		i += 2;
		j += 2;
	}
}

int		recurs(char **maps, t_list *tetrim, int size)
{
	int		xy[3];
	int		save;

	xy[0] = 0;
	xy[1] = 0;
	save = 0;
	while (save != 2)
	{
		if ((save = possib(tetrim, maps, xy, size)) == 1)
		{
			get_full(tetrim, maps, xy[0], xy[1]);
			if (tetrim->next)
			{
				if (recurs(maps, tetrim->next, size) == 9)
					return (9);
				else
					del_let(maps, tetrim->letter);
			}
			else
				return (9);
		}
		newxy(size, xy);
	}
	return (2);
}

void	print_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
