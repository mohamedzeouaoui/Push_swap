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
        return(3);
    if(10 < j && j <= 150)
        return(8);
    if (150 < j)
        return(16);
    return(0);
}
 int chrch_in(int value, int *tab, int start, int end)
 { 
    while(start <= end)
    {
        if (tab[start] == value)
            return(1);
        start++;
    }
    return (0);
 }
 


void    push_algo(t_global *var, int start, int end, int offset,int middle)
{
    int i;

    i = -1;
    while (++i < var->size)
    {
        while (ft_lstsize_p(var->stack_b) < (end - start + 1))
        {
        if (chrch_in(var->stack_a->content,var->tab,start,end))
        {
            pb_push_b(&var->stack_a, &var->stack_b);
            if (var->stack_b->content < var->tab[middle])
                rb_rotate_b(&var->stack_b);
        }
        else
            ra_rotate_a(&var->stack_a);
        }
        if (start - offset >= 0)
            start -= offset;
        else
            start = 0;
        if (end  + offset < var->size)
            end += offset;
        else
            end = var->size - 1;
    }
}

void    push_to_b(t_global *var)
{
    int n;
    int middle;
    int offset;
    int start;
    int end;

    n = check_n(var->size);
    middle = var->size / 2;
    offset = var->size / n;
    start = middle - offset;
    end = middle + offset;
    push_algo(var, start, end, offset, middle);
   
}

int     cheack_in_b(t_global    *var, int value)
{
    t_stack *b_head;

    b_head = var->stack_b; 

    while (b_head)
    {
        if(b_head->content == value)
        {
            return(1);
        }
        b_head = b_head->next;
    }
    return(0);
}

int	chrch_index_value(t_stack *stack_b, int max)
{
	int	i;
    t_stack *b_head;

	i = 0;
    // int size = 0;
    b_head  = stack_b;
	while (b_head)
	{
		if (b_head->content == max)
			return (i);
		i++;
        b_head = b_head->next;
	}
	return (-1);
}

void    pushb_to_a(t_global *var)
{
    int big;
    t_stack *b_head;

    var->down = 0;
    big = var->size-1;
    b_head = var->stack_b;
    while (big >= 0)
    {
        if(cheack_in_b(var, var->tab[big]))
        {
            if(var->stack_b->content == var->tab[big])
            {
                pa_push_a(&var->stack_a,&var->stack_b);
                big--;
            }
            else
                {
                    if(var->down == 0 || var->stack_b->content > lstlast(var->stack_a)->content)
                    {
                        pa_push_a(&var->stack_a,&var->stack_b);
                        ra_rotate_a(&var->stack_a);
                        var->down++;
                    }
                    else
                    {
                        int index_max = chrch_index_value(var->stack_b,var->tab[big]);
                        if (index_max <= (ft_lstsize_p(var->stack_b)) / 2)
                            rb_rotate_b(&var->stack_b);
                        else
                            rrb_reve_rotat_b(&var->stack_b);
                    
                    }
                }
        }
        else
        {
            rra_reve_rotat_a(&var->stack_a);
            var->down--;
            big--;
        }
    }
}

