/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:10:33 by bswag             #+#    #+#             */
/*   Updated: 2021/04/30 18:10:15 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "libft.h"
#include <limits.h>

typedef struct	s_dbg
{
	int         oper;
    int         dbl_oper;
    int         oper_first;
}				t_dbg;

t_dbg			debug;

typedef struct	    s_oper
{
	int             r_b;
    int             rr_b;
    int             r_a;
    int             rr_a;
}				    t_oper;

typedef struct	    s_mml
{
	long long int   max_val;
    long long int   min_val;
    int             max_pos;
    int             min_pos;
}				    t_mml;

int		fill_stack_a(char **argv, t_list **a);
int		f_dbl_reverse(t_list **a, t_list **b);
int		f_dbl_rotate(t_list **a, t_list **b);
int		f_dbl_swap(t_list **a, t_list **b);
int		f_push(t_list **src, t_list **dst);
int		f_reverse(t_list **stack);
int		f_rotate(t_list **stack);
int		f_swap(t_list **stack);
void	print_stacks(t_list *a, t_list *b);
void    error_msg(void);
int		check_result(t_list *a);
int		do_operation(char *oper, t_list **a, t_list **b);
int	    do_oper_print(char *oper, t_list **a, t_list **b, int n);
void	prepare_push_back(t_list **a, t_list **b);
void	max_min_elem_list(t_list *a, t_mml *mml);

#endif
