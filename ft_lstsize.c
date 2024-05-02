/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:04:29 by mzeouaou          #+#    #+#             */
/*   Updated: 2023/11/20 16:04:32 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_p(t_stack *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
