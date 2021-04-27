/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:07:35 by bswag             #+#    #+#             */
/*   Updated: 2021/04/27 22:47:03 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    error_msg(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int     check_result(t_list *a)
{
	int prev;
	
	prev = INT_MIN;
	while (a)
	{
		if (*((long long int *)a->content) < prev)
			return (1);
		prev = *((long long int *)a->content);
		a = a->next;
	}
	return (0);
}

int     do_operation(char *oper, t_list **a, t_list **b)
{
	if (!ft_strncmp(oper, "sa", 3))
		return (f_swap(a));
	if (!ft_strncmp(oper, "sb", 3))
		return (f_swap(b));
	if (!ft_strncmp(oper, "ss", 3))
		return (f_dbl_swap(a, b));
	if (!ft_strncmp(oper, "pa", 3))
		return (f_push(b, a));
	if (!ft_strncmp(oper, "pb", 3))
		return (f_push(a, b));
	if (!ft_strncmp(oper, "ra", 3))
		return (f_rotate(a));
	if (!ft_strncmp(oper, "rb", 3))
		return (f_rotate(b));
	if (!ft_strncmp(oper, "rr", 3))
		return (f_dbl_rotate(a, b));
	if (!ft_strncmp(oper, "rra", 4))
		return (f_reverse(a));
	if (!ft_strncmp(oper, "rrb", 4))
		return (f_reverse(b));
	if (!ft_strncmp(oper, "rrr", 4))
		return (f_dbl_reverse(a, b));
	return (1);
}

int     reading_operations(t_list **a, t_list **b)
{
	char    *line;

	while (get_next_line(0, &line))
	{
		if (do_operation(line, a, b))
			return (1);
		free(line);
		print_stacks(*a, *b);				// DEBUG LINE
	}
	free(line);
	return (0);
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
	print_stacks(a, b);				// DEBUG LINE
	if (reading_operations(&a, &b))
		error_msg();
	if (check_result(a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	return (0);
}