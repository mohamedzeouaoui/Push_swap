/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:24:56 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:24:59 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../push_swap.h"

void    pb_push_b(t_stack **a_list, t_stack **b_list, int flag)
{
    t_stack *tmp;

    if (*a_list == NULL)
        return ;
    tmp = *a_list;
    *a_list = (*a_list)->next;
    tmp->next = *b_list;
    *b_list = tmp;
    if(flag == 1)
        ft_putstr_fd("pb\n", 1);

    return ;
}
