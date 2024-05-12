/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:32:55 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/12 01:32:59 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_n(int j)
{
	if (j <= 10)
		return (3);
	if (10 < j && j <= 150)
		return (8);
	if (150 < j)
		return (16);
	return (0);
}

int	chrch_in(int value, int *tab, int start, int end)
{
	while (start <= end)
	{
		if (tab[start] == value)
			return (1);
		start++;
	}
	return (0);
}

int	cheack_in_b(t_global *var, int value)
{
	t_stack	*b_head;

	b_head = var->stack_b;
	while (b_head)
	{
		if (b_head->content == value)
		{
			return (1);
		}
		b_head = b_head->next;
	}
	return (0);
}

int	chrch_index_value(t_stack *stack_b, int max)
{
	int		i;
	t_stack	*b_head;

	i = 0;
	b_head = stack_b;
	while (b_head)
	{
		if (b_head->content == max)
			return (i);
		i++;
		b_head = b_head->next;
	}
	return (-1);
}

int	*bubble_sort(int *tab, int len)
{
	int	i;
	int	j;
	int	swap;

	swap = 1;
	i = 0;
	while (swap)
	{
		swap = 0;
		j = 0;
		while (j < len - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swaping(&tab[j], &tab[j + 1]);
				swap = 1;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
