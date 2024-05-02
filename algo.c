/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:51:19 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/01 15:51:24 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_n(int j)
{
    if (j <= 10)
        return(5);
    if(10 < j && j <= 150)
        return(8);
    if (150 < j)
        return(18);
    return(0);
}



void    push_algo(t_stack **a_stack, t_stack **b_stack, int start, int end, int *tab)
{
    t_stack *a_head;
    int i;

    a_head = *a_stack;
    while (a_head)
    {
        i = start;
        while (i < end)
        {
            if((a_head->content == tab[i]) && ((float)(i - start) >= (float)((end - start) / 2)))
                pb_push_b(a_stack, b_stack);
            else if (a_head->content == tab[i])
            {
                pb_push_b(a_stack, b_stack);
                rb_rotate_b(b_stack);
            }
            else
                ra_rotate_a(a_stack);
            i++;
        }
        a_head = a_head->next;
    }
}

void    push_to_b(t_stack **a_stack, t_stack **b_stack, int taill, int *tab)
{
    int n;
    int midel;
    int offset;
    int start;
    int end;

    n = check_n(taill);
    midel = taill / 2;
    offset = taill / n;
    start = midel - offset;
    end = midel + offset;

    while ((end <= taill) && (0 <= start))
    {
        push_algo(a_stack, b_stack, start, end, tab);
        end = end + offset;
        start = start - offset;
    }
    if (end < (taill-1) || 0 < start)
        push_algo(a_stack, b_stack, 0, (taill-1), tab);
}
