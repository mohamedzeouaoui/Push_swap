/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_reve-rotat_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:25:38 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:25:44 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../push_swap.h"

void    rra_reve_rotat_a(t_stack **a_list)
{
    t_stack *tmp;
    t_stack *elm;

    if (*a_list == NULL || ft_lstsize_p(*a_list) == 1)
        return ;
    elm = *a_list;
    while (elm->next->next != NULL)
    {
        elm = elm->next;
    }
    tmp = elm->next;
    elm->next = NULL;
    tmp->next = (*a_list);
    (*a_list) = tmp; 
    return ;
}
