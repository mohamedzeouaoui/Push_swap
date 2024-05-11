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
            pb_push_b(&var->stack_a, &var->stack_b, 1);
            if (var->stack_b->content < var->tab[middle])
                rb_rotate_b(&var->stack_b, 1);
        }
        else
            ra_rotate_a(&var->stack_a, 1);
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

void push_a_25_line(t_global *var, int *big)
{
    int index_max;
                
    if(var->down == 0 || var->stack_b->content > lstlast(var->stack_a)->content)
    {
        pa_push_a(&var->stack_a,&var->stack_b, 1);
        ra_rotate_a(&var->stack_a, 1);
        var->down++;
    }
    else
    {
        index_max = chrch_index_value(var->stack_b,var->tab[*big]);
        if (index_max <= (ft_lstsize_p(var->stack_b)) / 2)
            rb_rotate_b(&var->stack_b, 1);
        else
            rrb_reve_rotat_b(&var->stack_b, 1);
    }
                
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
                pa_push_a(&var->stack_a,&var->stack_b, 1);
                big--;
            }
            else
                push_a_25_line(var, &big);
        }
        else
        {
            rra_reve_rotat_a(&var->stack_a, 1);
            var->down--;
            big--;
        }
    }
}

void    tow_number(t_global *var)
{
    if ((var->size == 2 || var->size == 4) && cheack_sorted(var) == 0)
    {
        sa_swap_a(&var->stack_a, 1);
        return;
    }
    else
        return;
}
void    algo_3number(t_global *var)
{
    if ((var->size == 2 || var->size == 4))
    {
        tow_number(var);
        return;
    }
    if (var->stack_a->content < var->stack_a->next->content) 
        {
            rra_reve_rotat_a(&var->stack_a, 1);
            if (cheack_sorted(var))
                return;
        }
    if (var->stack_a->content > var->stack_a->next->next->content)
        {
            ra_rotate_a(&var->stack_a, 1);
            if (cheack_sorted(var))
                return;
        }
    if (cheack_sorted(var) == 0)
    {
        sa_swap_a(&var->stack_a, 1);
        return;
    }
}

void    algo_5number(t_global *var)
{
    int index_max;

    index_max = chrch_index_value(var->stack_a, var->tab[0]);
    while (var->stack_a->index != 0)
    {
        if (index_max <= (ft_lstsize_p(var->stack_a)) / 2)
            ra_rotate_a(&var->stack_a, 1);
        else
            rra_reve_rotat_a(&var->stack_a, 1);
    }
    pb_push_b(&var->stack_a,&var->stack_b, 1);
    index_max = chrch_index_value(var->stack_a, var->tab[1]);
    while (var->stack_a->index != 1)
    { 
        if (index_max <= (ft_lstsize_p(var->stack_a)) / 2)
            ra_rotate_a(&var->stack_a, 1);
        else
            rra_reve_rotat_a(&var->stack_a, 1);
    }
    pb_push_b(&var->stack_a, &var->stack_b, 1);
    algo_3number(var);
    pa_push_a(&var->stack_a, &var->stack_b, 1);
    pa_push_a(&var->stack_a,&var->stack_b, 1);
}

void    algo_less_than5(t_global *var)
{
    // t_stack *tmp;
    if (var->size <= 5 && var->size > 3)
        algo_5number(var);
    else if (var->size <= 3)
        algo_3number(var);
    // 
    exit_program(0);
}
//  tmp = var->stack_b;
    // while (tmp)
    // {
    //     printf("%d\n", tmp->content);
    //     tmp = tmp->next;
    // }
    // tmp = var->stack_a;
    // while (tmp)
    // {
    //     printf("........%d\n", tmp->content);
    //     tmp = tmp->next;
    // }