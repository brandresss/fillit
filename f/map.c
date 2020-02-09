#include "fillit.h"

char **map(int size)
{
    int i;
    i = 0;
    char **maps;
    maps = (char **)malloc(sizeof(char *) * (size + 1));
    while (i < 4)
        maps[i++] = (char *)malloc(sizeof(char) * (size + 1));
    return(maps);
}

void algo(char **maps, t_list *element)
{

}


int exist()