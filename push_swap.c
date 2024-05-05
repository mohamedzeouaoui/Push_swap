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
    i = parsing_global(argc, argv, &var,&spltstr);
    if (i == 1)
        return(1);
    fill_stack(&var);
    push_to_b(&var);

    tmp = var.stack_b;
    while (tmp)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }
    tmp = var.stack_a;
    while (tmp)
    {
        printf("........%d\n", tmp->content);
        tmp = tmp->next;
    }

 
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
