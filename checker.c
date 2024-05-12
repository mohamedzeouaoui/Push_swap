/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:42:52 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/10 18:43:01 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_global	get_var(void)
{
	static t_global	var;

	return (var);
}

int	main(int argc, char **argv)
{
	int			i;
	char		**spltstr;
	char		**instra;
	t_global	var;

	var = get_var();
	spltstr = NULL;
	var.stack_a = NULL;
	var.stack_b = NULL;
	if (argc < 2)
		return (0);
	i = parsing_global(argc, argv, &var, &spltstr);
	if (i == 1)
		return (exit_program(1), 1);
	fill_stack(&var);
	instra = read_instructions();
	i = 0;
	apply_instructions(instra, &var, i);
	if (cheack_sorted(&var) == 1 && check_stack_vide(&var) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (ft_dbl_free(instra), exit_program(0), 0);
}
