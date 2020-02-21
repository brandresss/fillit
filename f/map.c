/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofya_stepanova <sofya_stepanova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:36:58 by brandres          #+#    #+#             */
/*   Updated: 2020/02/21 23:36:23 by sofya_stepa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

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
        maps[i][size] =  '\0';
        i++;
    }
    maps[i] = NULL;
    return (maps);
}

int		suchka(t_list *tetrim, char **maps, int x, int y, int  size)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if ((tetrim->max_y + y) > size - 1 + '0')
		return (2);
	if ((tetrim->max_x + x) > size - 1 + '0')
		return (0);
	while (i <= 6 && j <= 7)
	{
		if (maps[tetrim->content[i] - '0' + y][tetrim->content[j] - '0' + x] != '.')
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
		maps[tetrim->content[i] - '0' + y][tetrim->content[j] - '0' + x] = tetrim->letter;
		i += 2;
		j += 2;
	}

}

int		recurs(char **maps, t_list *tetrim, int size)
{
	int		x;
	int		y;
	int		save;

	x = 0;
	y = 0;
	save = 0;
	while (x <= size && y <= size)
	{
		if ((save = suchka(tetrim, maps, x, y, size)) == 1)
		{
			get_full(tetrim, maps, x, y);
			if (tetrim->next)
			{
				if (recurs(maps, tetrim->next, size) == 9)
					return (9);
				else
				{
					del_let(maps, tetrim->letter);
					save = 0;
				}
			}
			else
				return (9);
		}
		if (save != 1)
		{
			if (save == 2)
			{
				return (2);
			}
			if (x < size)
				x++;
			else if (y < size)
			{
				y++;
				x = 0;
			}
		}
	}
	return (0);
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
