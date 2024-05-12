/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:25:30 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:25:33 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb_rotate_b(t_stack **b_list, int flag)
{
	t_stack	*tmp;
	t_stack	*elm;

	if (*b_list == NULL || ft_lstsize_p(*b_list) == 1)
		return ;
	tmp = *b_list;
	*b_list = (*b_list)->next;
	elm = *b_list;
	while (elm->next != NULL)
	{
		elm = elm->next;
	}
	elm->next = tmp;
	tmp->next = NULL;
	if (flag == 1)
		ft_putstr_fd("rb\n", 1);
	return ;
}
