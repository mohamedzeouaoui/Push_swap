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

int    ft_check_space(char *arv)
{
    int i;

    i = 0;
    while (arv[i])
    {
        if (arv[i++]!= ' ')
            return (1);
    }
    return(0);
}

int    ft_check_fullspace(int argc,char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_check_space(argv[i++]) == 0)
            return(1);
    }
    return(0);
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

int ft_check_number(char *str)
{
    int i;

    i = 0;
    if (str[0] == '-' || str [0] == '+')
        i++;
    while (str[i])
    {
        if (ft_isdigit_sp(str[i]) == 0)
            return (0);
        i++;
    }
    return(1);

}

int ft_check_full_number(int j, char **splstre)
{
    int i;
    
    i = 0;
    while (i < j)
    {

        if (ft_check_number(splstre[i]) == 0)
            return (0);
        i++;
    }
    return(1);
}

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
