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
    char    **spltstr;
    t_stack *tmp;
    t_global var;

    spltstr = NULL;
    var.stack_a = NULL;
    var.stack_b = NULL;
    if (ft_check_fullspace(argc,argv))
        return(1);
    parsing(argc, argv, &spltstr,&var);
    if(ft_check_full_number(var.size, spltstr))
        return(1);
    atoi_number(&var, spltstr);
    if(cheack_duplicate(var.tab, var.size))
        return(1);
    i = -1;
    while (++i < var.size)
        lstadd_back(&(var.stack_a),lstnew(var.tab[i]));
    var.tab = bubble_sort(var.tab,var.size);
    fill_index(&var);
    push_to_b(&var,var.size,var.tab);
    tmp = var.stack_b;
    while (tmp)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }
    // tmp = var.stack_a;
    // while (tmp)
    // {
    //     printf("........%d\n", tmp->content);
    //     tmp = tmp->next;
    // }
    ft_dbl_free(spltstr);
    exit_program(var.stack_a, var.stack_b, 0);
    return 0;

}





 









































// void    checkspace(int argc, char **argv)
// {
//     int i;
//     intvar.size;
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
