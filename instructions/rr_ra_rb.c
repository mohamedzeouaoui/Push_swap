/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ra&rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:27:01 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:27:04 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr_ra_rb(t_stack **a_list, t_stack **b_list, int flag)
{
	if (flag == 1)
	{
		ra_rotate_a(a_list, 1);
		rb_rotate_b(b_list, 1);
		ft_putstr_fd("rr\n", 1);
	}
	else
	{
		ra_rotate_a(a_list, 0);
		rb_rotate_b(b_list, 0);
	}
}
