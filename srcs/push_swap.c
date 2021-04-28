/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:04:59 by bswag             #+#    #+#             */
/*   Updated: 2021/04/28 20:52:18 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	do_oper_print(char *oper, t_list **a, t_list **b)
{
	do_operation(oper, a, b);
	ft_putendl_fd(oper, 1);
}

void	iterate_sorting(t_list **src, t_list **dst, int mode)
{
	int	change;
	
	change = 0;
	if (*src && (*src)->next)
	{
		if (*((long long int *)(*src)->content) > *((long long int *)(*src)->next->content))
			change = mode == 0 ? 1 : 0;
		else
			change = mode == 0 ? 0: 1;
	}
	if (*dst && (*dst)->next)
	{
		if (*((long long int *)(*dst)->content) > *((long long int *)(*dst)->next->content))
			change += (mode == 0) ? 0 : 10;
		else
			change += (mode == 0) ? 10 : 0;
	}
	if (change == 11)
		do_oper_print("ss", src, dst);
	if (change == 10)
		mode == 0 ? do_oper_print("sb", src, dst) : do_oper_print("sa", dst, src);
	if (change == 1)
		mode == 0 ? do_oper_print("sa", src, dst) : do_oper_print("sb", dst, src);
	mode == 0 ? do_oper_print("pb", src, dst) : do_oper_print("pa", dst, src);
}

void	sort_stack_iter(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	while (len-- != 1)
	{
		// print_stacks(*a, *b);
		iterate_sorting(a, b, 0);
	}
	len = ft_lstsize(*b);
	while (len-- != 0)
	{
		// print_stacks(*a, *b);
		iterate_sorting(b, a, 1);
	}
}

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	
	b = NULL;
	if (argc < 2)
		error_msg();
	if (fill_stack_a(&argv[1], &a))
		error_msg();
	while (check_result(a))
		sort_stack_iter(&a, &b);
	return (0);
}