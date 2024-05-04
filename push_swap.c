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


int main(int argc, char **argv)
{
    int i;
    int j;
    int m;
    int *tab;
    int *tab_nsort;
    // char    *joinstr;
    char    **spltstr;
    // char    *temporary;
    t_stack *a_head_ptr;
    t_stack *b_head_ptr;
    t_stack *tmp;
    t_global var;

    spltstr = NULL;
    a_head_ptr = NULL;
    b_head_ptr = NULL;
    i = 1;
    j = 0;

    // joinstr = malloc(1);
    // joinstr[0] = '\0';
    // if (argc < 2)
    //     return (0);

    if (ft_check_fullspace(argc,argv) == 1)
    {
        ft_putstr_fd("Error\n", 2);
        return(1);
    }
    // while (i < argc)
    // {
    //     temporary = joinstr;
    //     joinstr = ft_strjoin(joinstr, argv[i]);
    //     free(temporary);
    //     temporary = joinstr;
    //     joinstr = ft_strjoin(joinstr, " ");
    //     free(temporary);
    //     i++;
    // }
    
    // spltstr = ft_split(joinstr, ' ');
    // free(joinstr);
    parsing(argc, argv, &spltstr);

    while (spltstr[j])
        j++;
    // printf("%d \n", j);
    var.size = j;
    if(ft_check_full_number(j, spltstr) == 0)
    {
        ft_putstr_fd("Error\n", 2);
        return(1);
    }

    tab = malloc(sizeof(int) * j);
    j = 0;
    while (spltstr[j])
    {
        tab[j] = ft_atoi_push(spltstr[j]);
        j++;
    }

    if(cheack_duplicate(tab, j) == 1)
    {
        ft_putstr_fd("Error\n", 2);
        return(1);
    }
    i = 0;
    tab_nsort = malloc(sizeof(int) * j);
    while (i < j)
    {
        tab_nsort[i] = tab[i];
        i++;
    }
    i = 0;
    tab = bubble_sort(tab, j);
    while (i < j)
    {
        lstadd_back(&a_head_ptr,lstnew(tab_nsort[i]));
        i++;
    }
    i = 0;
    tmp = a_head_ptr;
    while (i < j)
    {
        m = 0;
        while (m < j)
        {
            if(tmp->content == tab[m])
                tmp->index = m;
            m++;
        }
        tmp = tmp->next;
        i++;
    }
    // tmp = a_head_ptr;
    
    // while (tmp)
    // {
    //     printf("........%d\n", tmp->index);
    //     tmp = tmp->next;
    // }

    // lstadd_back(&b_head_ptr,lstnew(888));
    // pa_push_a(&a_head_ptr, &b_head_ptr);
    // pb_push_b(&a_head_ptr, &b_head_ptr);
    // pb_push_b(&a_head_ptr, &b_head_ptr);

    // rb_rotate_b(&a_head_ptr);
    // rra_reve_rotat_a(&a_head_ptr);
    // rrb_reve_rotat_b(&a_head_ptr);
    var.stack_a = a_head_ptr;
    var.stack_b = b_head_ptr;
    var.tab = tab;
    push_to_b(&var,j,tab);

    tmp = b_head_ptr;

    while (tmp)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }

    tmp = a_head_ptr;

    while (tmp)
    {
        printf("........%d\n", tmp->content);
        tmp = tmp->next;
    }
    
    // get_index_list(&a_head_ptr, tab, j);
    free(tab_nsort);
    ft_dbl_free(spltstr);
    exit_program(a_head_ptr, b_head_ptr, 0);
    // i = 0;
    // while (i < j)
    // {
    //     printf("%d , index : %d\n",tab[i],i);
    //     i++;
    // }
    

	// printf("%d\n", ft_atoi_push("-2147483649"));


    return 0;



}















































// void    checkspace(int argc, char **argv)
// {
//     int i;
//     int j;
//     int n;
    
    
//     j = 0;
//     i = 1;
//     while (i < argc)
//     {
//         n = 0;
//         while (argv[i][j])
//         {

//             if (argv[i][j] == ' ')
//                 n++;
//             j++;
//         }
  
//         if (n != 0)
//         {
//             printf("error");
//         }
   
//       i++;
//     }
    
//     // printf("%i", argc);
// }
