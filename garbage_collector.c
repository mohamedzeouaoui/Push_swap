#include "push_swap.h"

t_list    **return_head(void)
{
    static t_list    *garbage;

    return (&garbage);
}

void    *safe_alloc(size_t size)
{
    void    *ptr;

    ptr = malloc(size);
    if (ptr == NULL)
        return (NULL);
    ft_lstadd_back(return_head(), ft_lstnew(ptr));
    return (ptr);
}

void    garbage_collector(void)
{
    t_list    *temp;
    t_list    *garbage;

    garbage = *(return_head());
    while (garbage)
    {
        temp = garbage;
        garbage = garbage->next;
        free(temp->content);
        free(temp);
    }
}
