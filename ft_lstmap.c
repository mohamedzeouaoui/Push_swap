/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:08:15 by mzeouaou          #+#    #+#             */
/*   Updated: 2023/11/29 15:18:57 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*new_lst;
	t_stack	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}

// int	main(void)
// {	
//     int arr[3] = {1,2,3};
// 	// Create a linked list with some integer values
// 	t_list *lst = ft_lstnew(&arr[0]);
// 	ft_lstadd_back(&lst, ft_lstnew(&arr[1]));
// 	ft_lstadd_back(&lst, ft_lstnew(&arr[2]));

// 	// Apply ft_lstmap to multiply each integer value by two
// 	t_list *new_lst = ft_lstmap(lst, multiply_by_two, free);

// 	while (new_lst)
// 	{
// 		printf("->>> %d\n", *(int *)(new_lst->content));
//         new_lst = new_lst->next;
// 	}

// 	return (0);
// }
