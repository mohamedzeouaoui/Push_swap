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

typedef struct s_stack
{
	int	content;
	int	index;
	struct s_stack	*next;
}					t_stack;
typedef struct global
{
	int start;
	int end;
	int offset;
	int size;
	int	down;
	int size_a;
	int size_b;
	t_stack *stack_a;
	t_stack *stack_b;
	int *tab;
} t_global;

void    get_index_list(t_stack **a_head_ptr, int *tab, int len);
int	ft_atoi_push(const char *str);
int    ft_check_fullspace(int argc,char **argv);
int ft_check_full_number(int j, char **splstre);
int *bubble_sort(int *tab, int len);
void	lstadd_back(t_stack **lst, t_stack *new);
int	ft_lstsize_p(t_stack *lst);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstnew(int content);
void    pa_push_a(t_stack **a_list, t_stack **b_list);
void    pb_push_b(t_stack **a_list, t_stack **b_list);
void    ra_rotate_a(t_stack **a_list);
void    rb_rotate_b(t_stack **b_list);
void    rr_ra_rb(t_stack **a_list,t_stack **b_list);
void    rra_reve_rotat_a(t_stack **a_list);
void    rrb_reve_rotat_b(t_stack **b_list);
void    rrr_rra_rrb(t_stack **a_list,t_stack **b_list);
void    sa_swap_a(t_stack **a_list);
void    sb_swap_b(t_stack **b_list);
void    ss_sa_b(t_stack **a_list, t_stack **b_list);
void    push_to_b(t_global *var);
void    ft_dbl_free(char **dbl_ptr);
void    exit_program(t_stack *a_head, t_stack *b_head, int exit_flag);
int cheack_duplicate(int *tab,int len);
void parsing (int argc, char **argv , char    ***spltstr, t_global *var);
void    atoi_number(t_global *var,char **spltstr);
void    fill_index(t_global *var);
int parsing_global(int argc, char **argv,t_global *var,char ***spltstr);
void fill_stack(t_global *var);

void    pushb_to_a(t_global *var);



#endif