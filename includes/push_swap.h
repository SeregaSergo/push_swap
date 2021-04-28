/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:10:33 by bswag             #+#    #+#             */
/*   Updated: 2021/04/28 18:40:28 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "libft.h"
#include <limits.h>

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

#endif
