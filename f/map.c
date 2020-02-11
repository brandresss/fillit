#include "fillit.h"

char **map(int size)
{
    int i;
    i = 0;
    char **maps;
    maps = (char **)malloc(sizeof(char *) * (size + 1));
    while (i < 4)
    {
        maps[i++] = (char *)malloc(sizeof(char) * (size + 1));
        ft_memset(maps[i], ".", size + 1);
    }
    return(maps);
}

int suchka(t_list *tetrim, char **maps, int x, int y) {}
void get_full(t_list *tetrim, char **maps) {}

void recurs(char **maps, t_list *tetrim, int size)
{
    int x;
    int y;
    x = 0;
    while(tetrim)
    {
        if (suchka(tetrim, maps, x, y))
        {
            get_full(tetrim, maps);
            tetrim = tetrim->next;
        }
        if (x < size)
            x++;
        else if (y < size)
        {
            y++;
            x = 0;
        }
        else if (x == size && y == size)

    }
        
    }

}
