/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:24:42 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:24:45 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../push_swap.h"

void    pa_push_a(t_stack **a_list, t_stack **b_list, int flag)
{
    t_stack *tmp;

    if (*b_list == NULL)
        return ;
    tmp = *b_list;
    *b_list = (*b_list)->next;
    tmp->next = *a_list;
    *a_list = tmp;
    if (flag == 1)
        ft_putstr_fd("pa\n", 1);
    return ;
}
