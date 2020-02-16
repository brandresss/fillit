/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:36:58 by brandres          #+#    #+#             */
/*   Updated: 2020/02/16 22:33:21 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    **map(int size)
{
    int i;
    i = 0;
    char **maps;
    maps = (char **)malloc(sizeof(char *) * (size + 1));
    while (i < size)
    {
        maps[i] = (char *)malloc(sizeof(char) * (size + 1));
        ft_memset(maps[i], 46, size + 1);
        i++;
    }
    maps[i] = NULL;
    return(maps);
}

int     suchka(t_list *tetrim, char **maps, int x, int y, int size)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i <= 6 && j <= 7)
    {
        if ((tetrim->content[i] - '0' + x) >= size ||
        (tetrim->content[j] - '0' + y) >= size)
            return (2);
         if (maps[tetrim->content[i] - '0' + x][tetrim->content[j] - '0' + y] != '.')
            return(0);
        i = i + 2;
        j = j + 2;

    }
    return(1);
}
void    get_full(t_list *tetrim, char **maps, int x, int y)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i <= 6 && j <= 7)
    {
        maps[tetrim->content[i] - '0' + x][tetrim->content[j] - '0' + y] = tetrim->letter;
        i += 2;
        j += 2;
    }

}

int     recurs(char **maps, t_list *tetrim, int size)
{
    int x;
    int y;
    int save;
    x = 0;
    y = 0;
    save = 0;

    while(x <= size && y <= size)
    {
        if (suchka(tetrim, maps, x, y, size) == 1)
        {
            get_full(tetrim, maps, x, y);
            tetrim = tetrim->next;
            if (tetrim)
            {
                if((save = recurs(maps, tetrim, size)) == 9)
                    return (9);
                return(2);
            }
            else
                return(9);
        }
        if (save == 2)
        {
            if (suchka(tetrim, maps, x, y, size) == 2)
                return(2);
            if (x < size)
                x++;
            else if (y < size)
            {
                y++;
                x = 0;
            }
        }
    }
    //else if (x == size && y == size)
    return (0);

}

void    print_map(char **map, int size)
{
    int i;
    i = 0;

    //printf(":%s:\n", map[0]);
    while(i < size)
    {
        ft_putstr(map[i]);
        ft_putchar('\n');
        i++;
    }
}
