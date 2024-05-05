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
#include <stdio.h>
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



void    push_algo(t_global *var, int start, int end)
{
    t_stack *a_head;
    int i;
    float m;

    a_head = var->stack_a;
    i =0;
    while (i < var->size)
    {
        if ((var->tab[start] <= var->stack_a->content) && (var->stack_a->content < var->tab[end]))
        {
            pb_push_b(&var->stack_a, &var->stack_b);
            m = (float)(((end - start) / 2) + start);
            if ((float)((var->stack_b)->index) < m)
                rb_rotate_b(&var->stack_b);
        }
        else
            ra_rotate_a(&var->stack_a);
        a_head = var->stack_a;
        a_head = a_head->next;
        i++;
    }
}

void    push_to_b(t_global *var)
{
    int n;
    int midel;
    int offset;
    int start;
    int end;

    n = check_n(var->size);
    midel = var->size / 2;
    offset = var->size / n;
    start = midel - offset;
    end = midel + offset;
    while ((end <= var->size) && (0 <= start))
    {
        push_algo(var, start, end);
        end = end + offset;
        start = start - offset;
        
    }
    if((start < 0) || (end > var->size))
    {
        start = 0;
        end = var->size - 1;
        push_algo(var, start, end);
    }
}
// void    pushb_to_a(t_global *var)
// {

// }