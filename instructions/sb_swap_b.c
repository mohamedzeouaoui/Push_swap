/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:27:51 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:27:53 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb_swap_b(t_stack **b_list, int flag)
{
	t_stack	*tmp;
	t_stack	*elm;

	if (*b_list == NULL || ft_lstsize_p(*b_list) == 1)
		return ;
	tmp = *b_list;
	*b_list = (*b_list)->next;
	elm = (*b_list)->next;
	tmp->next = elm;
	(*b_list)->next = tmp;
	if (flag == 1)
		ft_putstr_fd("sb\n", 1);
	return ;
}
