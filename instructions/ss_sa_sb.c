/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_sa-sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:28:08 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:28:11 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss_sa_b(t_stack **a_list, t_stack **b_list, int flag)
{
	if (flag == 1)
	{
		sa_swap_a(a_list, 1);
		sb_swap_b(b_list, 1);
		ft_putstr_fd("ss\n", 1);
	}
	else
	{
		sa_swap_a(a_list, 0);
		sb_swap_b(b_list, 0);
	}
}
