/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:41:35 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/04/22 19:41:40 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int cheack_duplicate(int *tab,int len)
{
    int i;
    int j;

    i = 0;
    while (i < len)
    {
        j = 1;
        while (j+i < len)
        {
            if (tab[i] == tab[j+i])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void    exit_program(t_stack *a_head, t_stack *b_head, int exit_flag)
{
    t_stack *temp;

    if (a_head != NULL)
    {
        while (a_head)
        {
            temp = a_head;
            a_head = a_head->next;
            free(temp);
        }
    }
    if (b_head != NULL)
    {
        while (b_head)
        {
            temp = b_head;
            b_head = b_head->next;
            free(temp);
        }
    }
    exit(exit_flag);
}

void    ft_dbl_free(char **dbl_ptr)
{
    int i;

    i = 0;
    while (dbl_ptr[i])
        free(dbl_ptr[i++]);
    free(dbl_ptr);
}

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

void    ft_swaping(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int *bubble_sort(int *tab, int len)
{
    int i;
    int j;
    int swap;

    swap = 1;
    i = 0;
    while (swap)
    {
        swap = 0;
        j = 0;
        while (j < len - i - 1)
        {
            if (tab[j] > tab[j+1])
            {
                ft_swaping(&tab[j], &tab[j + 1]);
                swap = 1;
            }
            j++;
        }
        i++;
    }
    return (tab);
}

void    get_index_list(t_stack **a_head_ptr, int *tab, int len)
{
    int i;
    t_stack *temp;

    temp = *a_head_ptr;
    while (temp != NULL)
    {
        i = 0;
        while (i < len)
        {
            if (temp->content == tab[i])
            {
                temp->index = i ;
            }
            i++;
        }
        temp = temp->next;
    }
    free(tab);
}

void parsing (int argc, char **argv , char ***spltstr)
{
    int i;
    char    *joinstr;
    char    *temporary;

    i = 1;
    joinstr = malloc(1);
    joinstr[0] = '\0';

    while (i < argc)
    {
        temporary = joinstr;
        joinstr = ft_strjoin(joinstr, argv[i]);
        free(temporary);
        temporary = joinstr;
        joinstr = ft_strjoin(joinstr, " ");
        free(temporary);
        i++;
    }
    
    (*spltstr) = ft_split(joinstr, ' ');
    free(joinstr);
}