#include "fillit.h"

char **map(int size)
{
    int i;
    i = 0;
    char **maps;
    maps = (char **)malloc(sizeof(char *) * (size + 1));
    while (i < size)
    {
        maps[i++] = (char *)malloc(sizeof(char) * (size + 1));
        ft_memset(maps[i], ".", size + 1);
    }
    return(maps);
}

int suchka(t_list *tetrim, char **maps, int x, int y) 
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i <= 6 && j <= 7)
    {
        if (maps[tetrim->content[0] - '0' + x][tetrim->content[1] - '0' + y] != '.')
            return(0);  
        i = i + 2;
        j = j + 2;

    }
    return(1);
}
void get_full(t_list *tetrim, char **maps) 
{

}

char **recurs(char **maps, t_list *tetrim, int size)
{
    int x;
    int y;
    x = 0;
    y = 0;
   
    while(x < size && y < size)
    {
        if (suchka(tetrim, maps, x, y))
        {
            get_full(tetrim, maps);
            tetrim = tetrim->next;
            if (tetrim)
                recurs(maps, tetrim, size);
        }
        else
        {
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
    return (maps);

}
