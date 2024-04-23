/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:30:32 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/03/20 00:30:36 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"


int	ft_atoi_push(const char *str);
int    ft_check_fullspace(int argc,char **argv);
int ft_check_full_number(int j, char **splstre);
int *bubble_sort(int *tab, int len);

typedef struct s_stack
{
	int	content;
	int	index;
	struct s_list	*next;
}					t_stack;

// typedef struct st_stack
// {
//     p_node *haut;
//     p_node *bas;

// }   p_stack;


#endif