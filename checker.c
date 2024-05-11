/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeouaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:42:52 by mzeouaou          #+#    #+#             */
/*   Updated: 2024/05/10 18:43:01 by mzeouaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_global    get_var()
{
    static t_global var;

    return (var);
}

int check_stack_vide(t_global *var)
{
    t_stack *a_head;

    a_head = var->stack_b;

    if (a_head == NULL)
        return(1);
    return(0); 
}

char   *join (char    **ptr, char **line)
{
    char    *temporary;
    
    temporary = (*ptr);
    (*ptr) = ft_strjoin((*ptr), *line);
    free(temporary);
    free(*line);
    return((*ptr));
}

int    check_line(char *line)
{
    if (ft_strncmp(line,"ra\n",3) == 0)
        return (1);
    else if (ft_strncmp(line,"rb\n",3) == 0)
        return (1);
    else if (ft_strncmp(line,"rr\n",3) == 0)
        return (1);
    else if (ft_strncmp(line,"pa\n",3) == 0)
        return (1);
    else if (ft_strncmp(line,"pb\n",3) == 0)
        return (1);
    else if (ft_strncmp(line,"rra\n",4) == 0)
        return (1);
    else if (ft_strncmp(line,"rrb\n",4) == 0)
        return (1);
    else if (ft_strncmp(line,"rrr\n",4) == 0)
        return (1);
    else if (ft_strncmp(line,"sa\n",3) == 0)
        return (1);
    else if (ft_strncmp(line,"sb\n",3) == 0)
        return (1);
    else if (ft_strncmp(line,"ss\n",3) == 0)
        return (1);
    ft_putstr_fd("Error\n", 2);
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    char    **spltstr;
    char    **instra;
    char    *line;
    char    *ptr;

    t_global var;

    var = get_var();
    spltstr = NULL;
    var.stack_a = NULL;
    var.stack_b = NULL;
    if (argc < 2)
        return(0);
    i = parsing_global(argc, argv, &var,&spltstr);
    if (i == 1)
    {
        ft_dbl_free(spltstr);
        exit_program(1);
    }
    fill_stack(&var);
    ptr = malloc(1);
    ptr[0] = '\0';
    while (1)
    {
        line = get_next_line(0);
        if (line == NULL )
            break;
        if (line[ft_strlen(line) - 1] != '\n' || line[0] == '\n' || 0 == check_line(line))
        {
            ft_putstr_fd("Error\n", 2);
            free(line);
            free(ptr);
            exit_program(1);
        }
        ptr = join(&ptr, &line);
    }
    instra = ft_split(ptr, '\n');
    i = 0;
    while (instra[i])
    {
        if (ft_strncmp(instra[i],"ra",3) == 0)
            ra_rotate_a(&var.stack_a, 0);
        if (ft_strncmp(instra[i],"rb",3) == 0)
            rb_rotate_b(&var.stack_a, 0);
        if (ft_strncmp(instra[i],"rr",3) == 0)
            rr_ra_rb(&var.stack_a,&var.stack_b, 0);
        if (ft_strncmp(instra[i],"pa",3) == 0)
            pa_push_a(&var.stack_a, &var.stack_b, 0);
        if (ft_strncmp(instra[i],"pb",3) == 0)
            pb_push_b(&var.stack_a, &var.stack_b, 0);
        if (ft_strncmp(instra[i],"rra",4) == 0)
            rra_reve_rotat_a(&var.stack_a, 0);
        if (ft_strncmp(instra[i],"rrb",4) == 0)
            rrb_reve_rotat_b(&var.stack_b, 0);
        if (ft_strncmp(instra[i],"rrr",4) == 0)
            rrr_rra_rrb(&var.stack_a, &var.stack_b, 0);
        if (ft_strncmp(instra[i],"sa",3) == 0)
            sa_swap_a(&var.stack_a, 0);
        if (ft_strncmp(instra[i],"sb",3) == 0)
            sb_swap_b(&var.stack_b, 0);
        if (ft_strncmp(instra[i],"ss",3) == 0)
            ss_sa_b(&var.stack_a,&var.stack_b, 0);
        i++;
    }
    if (cheack_sorted(&var) == 1 && check_stack_vide(&var) == 1)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
    ft_dbl_free(instra);
    free(ptr);
    exit_program(0);
    return 0;
}
