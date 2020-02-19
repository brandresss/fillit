#include "fillit.h"

int     checker(int save, char *arr)
{
    int i;
    int hash;

    i = 0;
    hash = 0;
    while (i < 20)
    {
        if (i % 5 < 4)
        {
            if (arr[i] != '.' || arr[i] != '#')
                return (0);
            if (arr[i] == '#' && ++hash > 4)
                return (1);
        }
        else if (arr[i] != '\n')
            return (2);
        i++;
    }
    if (save == 21 && arr[20] != '\n')
        return (3);
    if (!(connections(arr)))
        return(4);
    return (5);
}

int     connections(char *arr)
{
    int figure;
    int i;

    figure = 0;
    i = 0;
    while (i < 20)
    {
        if (arr[i] == '#')
        {
            if ((i - 1 >= 0) && (arr[i - 1] == '#'))
                figure++;
            if ((i - 5 >= 0) && (arr[i - 5] == '#'))
                figure++;
            if ((i + 1 < 20) && (arr[i + 1] == '#'))
                figure++;
            if ((i + 5 < 20) && (arr[i + 5] == '#'))
                figure++;
        }
        i++;
    }
    return (figure == 6 || figure == 8);
}

}
