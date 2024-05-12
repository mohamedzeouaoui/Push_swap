/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:00:08 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/12 02:00:11 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_space(char *arv)
{
	int	i;

	i = 0;
	while (arv[i])
	{
		if (arv[i++] != ' ')
			return (1);
	}
	return (0);
}

int	ft_check_fullspace(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_check_space(argv[i++]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	return (0);
}

int	ft_isdigit_sp(int c)
{
	if ((c >= '0' && c <= '9') || c <= ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_check_full_number(int j, char **splstre)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (ft_check_number(splstre[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	get_index_list(t_stack **a_head_ptr, int *tab, int len)
{
	int		i;
	t_stack	*temp;

	temp = *a_head_ptr;
	while (temp != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (temp->content == tab[i])
			{
				temp->index = i;
			}
			i++;
		}
		temp = temp->next;
	}
	free(tab);
}
