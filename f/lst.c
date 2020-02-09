#include "fillit.h"
// добавляет элемент в конец (из моей либы)
void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && new)
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// добавляет элемент в начало списка (тоже из моей либы)
void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

// будет возвращать созданный элемент списка
t_list      *create_tetrimino(char *buf, char letter)
{
    int i;
    t_list  *element;
    int save;
    save = 8;
    i = 0;
    element = (t_list *)malloc(sizeof(t_list));
    element->content = (char *)malloc(sizeof(char) * (save  + 1));
    element->content[save] = '\0';
    while (save > 0)
    {
        element->content[i] = buf[i];
        i++;
        save--;
    }
    element->letter = letter;
    element->next = NULL;
    return(element);
}