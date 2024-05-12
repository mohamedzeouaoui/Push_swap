/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:51:19 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/01 15:51:24 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_algo(t_global *var, int start, int end, int offset)
{
	int	i;

	i = -1;
	while (++i < var->size)
	{
		while (ft_lstsize_p(var->stack_b) < (end - start + 1))
		{
			if (chrch_in(var->stack_a->content, var->tab, start, end))
			{
				pb_push_b(&var->stack_a, &var->stack_b, 1);
				if (var->stack_b->content < var->tab[var->middle])
					rb_rotate_b(&var->stack_b, 1);
			}
			else
				ra_rotate_a(&var->stack_a, 1);
		}
		if (start - offset >= 0)
			start -= offset;
		else
			start = 0;
		if (end + offset < var->size)
			end += offset;
		else
			end = var->size - 1;
	}
}

void	push_to_b(t_global *var)
{
	int	n;
	int	offset;
	int	start;
	int	end;

	n = check_n(var->size);
	var->middle = var->size / 2;
	offset = var->size / n;
	start = var->middle - offset;
	end = var->middle + offset;
	push_algo(var, start, end, offset);
}

void	push_a_25_line(t_global *var, int *big)
{
	int	index_max;

	if (var->down == 0
		|| var->stack_b->content > lstlast(var->stack_a)->content)
	{
		pa_push_a(&var->stack_a, &var->stack_b, 1);
		ra_rotate_a(&var->stack_a, 1);
		var->down++;
	}
	else
	{
		index_max = chrch_index_value(var->stack_b, var->tab[*big]);
		if (index_max <= (ft_lstsize_p(var->stack_b)) / 2)
			rb_rotate_b(&var->stack_b, 1);
		else
			rrb_reve_rotat_b(&var->stack_b, 1);
	}
}

void	pushb_to_a(t_global *var)
{
	int		big;
	t_stack	*b_head;

	var->down = 0;
	big = var->size - 1;
	b_head = var->stack_b;
	while (big >= 0)
	{
		if (cheack_in_b(var, var->tab[big]))
		{
			if (var->stack_b->content == var->tab[big])
			{
				pa_push_a(&var->stack_a, &var->stack_b, 1);
				big--;
			}
			else
				push_a_25_line(var, &big);
		}
		else
		{
			rra_reve_rotat_a(&var->stack_a, 1);
			var->down--;
			big--;
		}
	}
}

int	ft_check_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit_sp(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
