/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rra&rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:27:16 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:27:18 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../push_swap.h"

void    rrr_rra_rrb(t_stack **a_list,t_stack **b_list)
{
    rra_reve_rotat_a(a_list);
    rrb_reve_rotat_b(b_list);
}
