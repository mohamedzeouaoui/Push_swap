/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:25:17 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:25:21 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_rotate_a(t_stack **a_list, int flag)
{
	t_stack	*tmp;
	t_stack	*elm;

	if (*a_list == NULL || ft_lstsize_p(*a_list) == 1)
		return ;
	tmp = *a_list;
	*a_list = (*a_list)->next;
	elm = *a_list;
	while (elm->next != NULL)
	{
		elm = elm->next;
	}
	elm->next = tmp;
	tmp->next = NULL;
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
	return ;
}
