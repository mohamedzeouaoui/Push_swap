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

char				**ft_split(char const *s, char c);

typedef struct st_node
{
    int data;
    struct st_node *next;
    struct st_node *prev;
    int index;

}   p_node;

// typedef struct st_stack
// {
//     p_node *haut;
//     p_node *bas;

// }   p_stack;


#endif