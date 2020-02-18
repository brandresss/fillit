/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 22:11:09 by brandres          #+#    #+#             */
/*   Updated: 2020/02/18 22:28:32 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_error(void)
{
    ft_putstr("error\n");
    exit(EXIT_FAILURE);
}

char    max_x(char *koord)
{
    int     i;
    char     tmp;

    i = 0;
    while(i <= 6)
    {
        if(tmp < koord[i])
            tmp = koord[i];
        i += 2;
    }
    return(tmp);
}

char    max_y(char *koord)
{
    int     j;
    char     tmp;

    j = 1;
    while(j <= 7)
    {
        if(tmp < koord[j])
            tmp = koord[j];
        j += 2;
    }
    return(tmp);
}

char    *koordin(char *buf)
{
    int i;
    int j;
    char *koord;

    koord = (char *)malloc(sizeof(char) * 9);
    koord[8] = '\0';
    i = 0;
    j = 0;
    //printf("buff:%s\n", buf);
    while(i <= 19)
    {
        if(buf[i] == '#')
        {
            koord[j] = i / 5 + '0';

            koord[j + 1] = i % 5 + '0';
            j += 2;
        }
        i++;
    }
    //printf("%s\n", koord);
    return(koord);
}

char *null_pos(char *koord)
{
    int     i;
    int     c;
    int     j;
    int     tmp;
    i = 0;
    j = 1;
    c = 3;
    while(i <= 6)
    {
        if(c > koord[i] - '0')
            c = koord[i] - '0';
        i += 2;
    }
    tmp = 3;
    while(j <= 7)
    {
        if(tmp > koord[j] - '0')
            tmp = koord[j] - '0';
        j += 2;
    }
    //printf("c tmp:%d %d\n", c, tmp);
    j = 1;
    while(j <= 7)
    {
        koord[j] =  koord[j] - tmp;
        j += 2;
    }
    i = 0;
    while(i <= 6)
    {
        koord[i] =  koord[i] - c;
        i += 2;
    }
    //printf("koord:%s\n", koord);
    return(koord);
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
    while ((save = read(fd, buf, 21)))
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
        //char *ttt = koord(buf);
        //printf("%s\n", koordin(buf));
        if (list == NULL)
            list = create_tetrimino(null_pos(koordin(buf)), \
            max_x(null_pos(koordin(buf))), max_y(null_pos(koordin(buf))), letter++);
        // если уже есть, то добавляем элемент в конец
        else
            ft_lstadd_end(&list, create_tetrimino(null_pos(koordin(buf)), \
            max_x(null_pos(koordin(buf))), max_y(null_pos(koordin(buf))), letter++));

    }
    //printf("list->content%s\n", list->content);
    return(list);
}

void    kabel(int size, t_list *tetrim)
{
    char **maps;

    maps = map(size);
    printf("4\n");
    printf("!str:%s!\n", tetrim->content);
    while (recurs(maps, tetrim, size) == 2)
    {
        size++;
        free(*maps);
        free(maps);
        maps = map(size);
    }
    printf("\n");
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
    printf("1\n");
    list = reader(fd);
    close(fd);




    printf("2\n");
    printf("%s\n", list->content);
    printf("3\n");
    kabel(4, list);

    return (0);
}
