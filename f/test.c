#include "fillit.h"

int main()
{
    t_list *a;
    t_list *bq;
    char b = 'a';
    char c = 'b';
    char *buff = "asdfghk";
    char *buff1 = "qwertyui";
    a = create_tetrimino(buff, b);
    bq = create_tetrimino(buff1, c);
    ft_lstadd_end(&a, bq);
    printf("%s\n", a->content);
    printf("%s\n",a->next->content);
    printf("%c",a->letter);
    return 0;
}