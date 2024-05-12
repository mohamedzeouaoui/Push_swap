/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:43:21 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/12 01:43:24 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheack_duplicate(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 1;
		while (j + i < len)
		{
			if (tab[i] == tab[j + i])
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	exit_program(int exit_flag)
{
	t_global	var;
	t_stack		*temp;

	var = get_var();
	if (var.stack_a != NULL)
	{
		while (var.stack_a)
		{
			temp = var.stack_a;
			var.stack_a = var.stack_a->next;
			free(temp);
		}
	}
	if (var.stack_b != NULL)
	{
		while (var.stack_b)
		{
			temp = var.stack_b;
			var.stack_b = var.stack_b->next;
			free(temp);
		}
	}
	free(var.tab);
	garbage_collector();
	exit(exit_flag);
}

int	cheack_sorted(t_global *var)
{
	t_stack	*a_head;

	a_head = var->stack_a;
	while (a_head->next)
	{
		if (a_head->content > a_head->next->content)
			return (0);
		a_head = a_head->next;
	}
	return (1);
}

void	fill_stack(t_global *var)
{
	int	i;

	i = -1;
	while (++i < var->size)
		lstadd_back(&(var->stack_a), lstnew(var->tab[i]));
	var->tab = bubble_sort(var->tab, var->size);
	fill_index(var);
}

void	ft_dbl_free(char **dbl_ptr)
{
	int	i;

	i = 0;
	while (dbl_ptr[i])
		free(dbl_ptr[i++]);
	free(dbl_ptr);
}
