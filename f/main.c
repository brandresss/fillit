#include "fillit.h"

void    ft_error(void)
{
    ft_putstr("error\n");
    exit(EXIT_FAILURE);
}

t_list   *reader(const int fd)
{
    char    *buf;
    int     save;
    char    letter;
    t_list  *list;

    save = 0;
    buf = ft_strnew(21);
    letter = 'A';
    list = NULL;
    while (save == read(fd, buf, 21))
    {
        /* если прочитано не 20 и не 21 символ, то ошибка (наверно?)
        if (save != 20 && save != 21)
            ft_error();
        if ((checker(save, buf)) != 5)
        {
            ft_strdel(&buf);
            ft_error();
        }
        */
        // если списка не было, создаем его
        if (list == NULL)
            ft_lstadd(&list, create_tetrimino(buf, letter++));
        // если уже есть, то добавляем элемент в конец
        else
            ft_lstadd_end(&list, create_tetrimino(buf, letter++));

    }
    return(list);
}

void    kabel(int size, t_list *tetrim)
{
    char **maps;

    maps = map(size);
    printf("4\n");
   while (recurs(maps, tetrim, size) == 2)
    {
        size++;
        free(*maps);
        free(maps);
        maps = map(size);
    }
    print_map(maps, size);
    printf("5\n");
}


int     main (int argc, char **argv)
{
     printf("0\n");
    // ft_putchar('!');
    int fd;
    t_list *list;


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
    reader(fd);
    close(fd);

    printf("1\n");


    list = reader(fd);

    printf("2\n");

    kabel(4, list);
    printf("3\n");
    return (0);
}
