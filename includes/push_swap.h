/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:10:33 by bswag             #+#    #+#             */
/*   Updated: 2021/05/05 15:12:08 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef long long int	t_cntnt;

typedef long long int*	t_p_cntnt;

typedef struct s_oper
{
	int	r_b;
	int	rr_b;
	int	r_a;
	int	rr_a;
}		t_oper;

typedef struct s_mml
{
	t_cntnt	max_val;
	t_cntnt	min_val;
	int		max_pos;
	int		min_pos;
}			t_mml;

int		fill_stack_a(char **argv, t_list **a);
int		f_dbl_reverse(t_list **a, t_list **b);
int		f_dbl_rotate(t_list **a, t_list **b);
int		f_dbl_swap(t_list **a, t_list **b);
int		f_push(t_list **src, t_list **dst);
int		f_reverse(t_list **stack);
int		f_rotate(t_list **stack);
int		f_swap(t_list **stack);
void	error_msg(void);
int		check_result(t_list *a);
int		do_operation(char *oper, t_list **a, t_list **b);
int		do_oper_print(char *oper, t_list **a, t_list **b, int n);
void	prepare_push_back(t_list **a, t_list **b);
void	max_min_elem_list(t_list *a, t_mml *mml);
int		max_abs(int a, int b);
int		abs(int x);
int		min_abs(int a, int b);
int		what_to_reverse(t_list *a, t_list *b, t_cntnt mod_a, t_cntnt mod_b);
int		what_to_rotate(t_list *a, t_list *b, t_cntnt mod_a, t_cntnt mod_b);
void	part(t_p_cntnt ar, int start_pos, int end_pos);
int		how_many_oper(t_list *a, t_oper *oper, t_cntnt x);
int		get_mode(int argc, char **argv);

#endif
