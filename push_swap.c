/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:51:19 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 03:51:23 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_global	get_var(void)
{
	static t_global	var;

	return (var);
}

int	main(int argc, char **argv)
{
	int			i;
	char		**spltstr;
	t_global	var;

	var = get_var();
	spltstr = NULL;
	var.stack_a = NULL;
	var.stack_b = NULL;
	if (argc < 2)
		return (0);
	i = parsing_global(argc, argv, &var, &spltstr);
	if (i == 1)
		exit_program(1);
	fill_stack(&var);
	if (cheack_sorted(&var))
		exit_program(0);
	if (var.size < 6)
		algo_less_than5(&var);
	push_to_b(&var);
	pushb_to_a(&var);
	exit_program(0);
	return (0);
}

// t_stack *tmp;

// tmp = var.stack_b;
// while (tmp)
// {
// 	printf("%d\n", tmp->content);
// 	tmp = tmp->next;
// }
// tmp = var.stack_a;
// while (tmp)
// {
// 	printf("........%d\n", tmp->content);
// 	tmp = tmp->next;
// }
