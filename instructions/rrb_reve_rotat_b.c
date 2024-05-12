/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_reve-rotat_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:26:09 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:26:12 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb_reve_rotat_b(t_stack **b_list, int flag)
{
	t_stack	*tmp;
	t_stack	*elm;

	if (*b_list == NULL || ft_lstsize_p(*b_list) == 1)
		return ;
	elm = *b_list;
	while (elm->next->next != NULL)
	{
		elm = elm->next;
	}
	tmp = elm->next;
	elm->next = NULL;
	tmp->next = (*b_list);
	(*b_list) = tmp;
	if (flag == 1)
		ft_putstr_fd("rrb\n", 1);
	return ;
}
