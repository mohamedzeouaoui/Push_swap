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

int main(int argc, char **argv)
{
    int i;
    int j;
    int *tab;
    char    *joinstr;
    char    **spltstr;
    // t_stack *a_head_ptr;
    // t_stack *b_head_ptr;

    i = 1;
    j = 0;
    joinstr = "";

    // if (argc < 2)
    //     return (0);

 

    if (ft_check_fullspace(argc,argv) == 1)
    {
        ft_putstr_fd("Error\n", 2);
        return(0);
    }
    
    while (i < argc)
    {
        joinstr = ft_strjoin(joinstr, argv[i]);
        joinstr = ft_strjoin(joinstr, " ");
        i++;
    }

    
    
    spltstr = ft_split(joinstr, ' ');



    while (spltstr[j])
    {
        // printf("%s \n", spltstr[j]);
        j++;
    }

    if(ft_check_full_number(j, spltstr) == 0)
    {
        ft_putstr_fd("Error\n", 2);
        return(0);
    }

    tab = malloc(sizeof(int) * j);
    j = 0;
    while (spltstr[j])
    {
        tab[j] = ft_atoi_push(spltstr[j]);
        j++;
    }
    i = 0;

    tab = bubble_sort(tab, j);
    
    while (i < j)
    {
        printf("%d \n",tab[i]);
        i++;
    }
    

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
