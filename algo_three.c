/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:38:29 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/12 01:38:32 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swaping(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	tow_number(t_global *var)
{
	if ((var->size == 2 || var->size == 4) && cheack_sorted(var) == 0)
	{
		sa_swap_a(&var->stack_a, 1);
		return ;
	}
	else
		return ;
}

void	algo_3number(t_global *var)
{
	if ((var->size == 2 || var->size == 4))
	{
		tow_number(var);
		return ;
	}
	if (var->stack_a->content < var->stack_a->next->content)
	{
		rra_reve_rotat_a(&var->stack_a, 1);
		if (cheack_sorted(var))
			return ;
	}
	if (var->stack_a->content > var->stack_a->next->next->content)
	{
		ra_rotate_a(&var->stack_a, 1);
		if (cheack_sorted(var))
			return ;
	}
	if (cheack_sorted(var) == 0)
	{
		sa_swap_a(&var->stack_a, 1);
		return ;
	}
}

void	algo_5number(t_global *var)
{
	int	index_max;

	index_max = chrch_index_value(var->stack_a, var->tab[0]);
	while (var->stack_a->index != 0)
	{
		if (index_max <= (ft_lstsize_p(var->stack_a)) / 2)
			ra_rotate_a(&var->stack_a, 1);
		else
			rra_reve_rotat_a(&var->stack_a, 1);
	}
	pb_push_b(&var->stack_a, &var->stack_b, 1);
	index_max = chrch_index_value(var->stack_a, var->tab[1]);
	while (var->stack_a->index != 1)
	{
		if (index_max <= (ft_lstsize_p(var->stack_a)) / 2)
			ra_rotate_a(&var->stack_a, 1);
		else
			rra_reve_rotat_a(&var->stack_a, 1);
	}
	pb_push_b(&var->stack_a, &var->stack_b, 1);
	algo_3number(var);
	pa_push_a(&var->stack_a, &var->stack_b, 1);
	pa_push_a(&var->stack_a, &var->stack_b, 1);
}

void	algo_less_than5(t_global *var)
{
	if (var->size <= 5 && var->size > 3)
		algo_5number(var);
	else if (var->size <= 3)
		algo_3number(var);
	exit_program(0);
}
