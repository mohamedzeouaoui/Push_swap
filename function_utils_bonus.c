/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:09:28 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/12 14:09:33 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_size(t_global *var, char **spltstr)
{
	var->size = 0;
	while (spltstr[var->size])
		var->size++;
	if (var->size == 1)
	{
		ft_dbl_free(spltstr);
		exit_program(0);
	}
}

void	parsing(int argc, char **argv, char ***spltstr, t_global *var)
{
	int		i;
	char	*joinstr;
	char	*temporary;

	i = 1;
	(void)var;
	joinstr = malloc(1);
	joinstr[0] = '\0';
	while (i < argc)
	{
		temporary = joinstr;
		joinstr = ft_strjoin(joinstr, argv[i]);
		free(temporary);
		temporary = joinstr;
		joinstr = ft_strjoin(joinstr, " ");
		free(temporary);
		i++;
	}
	*spltstr = ft_split(joinstr, ' ');
	free(joinstr);
	return ;
}

void	atoi_number(t_global *var, char **spltstr)
{
	int	j;

	var->tab = safe_alloc(sizeof(int) * var->size);
	j = 0;
	while (spltstr[j])
	{
		var->tab[j] = ft_atoi_push(spltstr[j]);
		j++;
	}
}

void	fill_index(t_global *var)
{
	int		i;
	int		m;
	t_stack	*tmp;

	i = 0;
	tmp = var->stack_a;
	while (i < var->size)
	{
		m = 0;
		while (m < var->size)
		{
			if (tmp->content == var->tab[m])
				tmp->index = m;
			m++;
		}
		tmp = tmp->next;
		i++;
	}
}

int	parsing_global(int argc, char **argv, t_global *var, char ***spltstr)
{
	if (ft_check_fullspace(argc, argv))
		return (1);
	parsing(argc, argv, spltstr, var);
	var->size = 0;
	while ((*spltstr)[var->size])
		var->size++;
	if (ft_check_full_number(var->size, *spltstr))
		return (1);
	atoi_number(var, *spltstr);
	if (cheack_duplicate(var->tab, var->size))
		return (1);
	ft_dbl_free(*spltstr);
	return (0);
}
