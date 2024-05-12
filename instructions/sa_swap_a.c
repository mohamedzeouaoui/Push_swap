/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:27:39 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:27:41 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_swap_a(t_stack **a_list, int flag)
{
	t_stack	*tmp;
	t_stack	*elm;

	if (*a_list == NULL || ft_lstsize_p(*a_list) == 1)
		return ;
	tmp = *a_list;
	*a_list = (*a_list)->next;
	elm = (*a_list)->next;
	tmp->next = elm;
	(*a_list)->next = tmp;
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	return ;
}
