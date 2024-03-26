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

#include <stdio.h>
#include "push_swap.h"

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

int    ft_check_null(int argc,char **argv)
{
    int i;

    i = 1;

    while (i < argc)
    {
        if (argv[i++][0] == '\0')
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
            return(0);
    }
    return(1);
}

// int	ft_isdigit(int c)
// {
// 	if ((c >= '0' && c <= '9') || c <= ' ')
// 	{
// 		return (1);
// 	}
// 	else
// 	{
// 		return (0);
// 	}
// }

// int ft_check_number(char *argv)
// {
//     int i;

//     i = 0;
//     while (argv[i])
//     {
//         if (ft_isdigit(argv[i]) == 0)
//             return (0);
//         i++;
//     }
//     return(1);

// }

// int ft_check_full_number(int argc, char **argv)
// {
//     int i;
    
//     i = 1;
//     while (i < argc)
//     {

//         if (ft_check_number(argv[i]) == 0)
//             return (0);
        
//     }
    

// }

int main(int argc, char **argv)
{

    if (argc < 2)
        return(0);
    // else if(ft_check_fullspace(argc, argv) == 0)
    //     return (printf("Error"));
    ft_split()


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
