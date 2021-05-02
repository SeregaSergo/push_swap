/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:07:35 by bswag             #+#    #+#             */
/*   Updated: 2021/05/02 15:37:48 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_dimention(long long int number)
{
	int	result;

	result = 1;
	if (number < 0)
		number = number * (-1);
	while (number > 9)
	{
		number /= 10;
		result++;
	}
	return (result);
}

void	print_line_stack(long long int a_elem, long long int b_elem)
{
	int	i;

	if (a_elem < 0)
		ft_putstr_fd(" ", 1);
	else
		ft_putstr_fd("  ", 1);
	if (a_elem <= INT_MAX)
		ft_putnbr_fd((int)a_elem, 1);
	else
		ft_putstr_fd(" ", 1);
	if (a_elem <= INT_MAX)
		i = 12 - ft_get_dimention(a_elem);
	else
		i = 11;
	if (b_elem < 0)
		i--;
	while (i-- > 0)
		ft_putstr_fd(" ", 1);
	if (b_elem <= INT_MAX)
		ft_putnbr_fd((int)b_elem, 1);
	ft_putstr_fd("\n", 1);
}

void	print_stacks(t_list *a, t_list *b)
{
	long long int	a_elem;
	long long int	b_elem;
	int				i;

	i = max_abs(ft_lstsize(a), ft_lstsize(b));
	a_elem = LLONG_MAX;
	b_elem = LLONG_MAX;
	while (i > 0)
	{
		if (i <= ft_lstsize(a))
		{
			a_elem = *((long long int *)a->content);
			a = a->next;
		}
		if (i <= ft_lstsize(b))
		{
			b_elem = *((long long int *)b->content);
			b = b->next;
		}
		print_line_stack(a_elem, b_elem);
		i--;
	}
	ft_putstr_fd("-----------------\n  a           b\n\n", 1);
}

int	reading_operations(t_list **a, t_list **b, int mode)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (do_operation(line, a, b))
			return (1);
		if (mode == 1)
		{
			ft_putstr_fd("\x1b[35m", 1);
			ft_putendl_fd(line, 1);
			ft_putstr_fd("\x1b[0m", 1);
		}
		free(line);
		if (mode == 1)
			print_stacks(*a, *b);
	}
	free(line);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		mode;

	b = NULL;
	mode = !ft_strncmp(argv[1], "-v", 3);
	if (argc < 2 && (mode && argc < 3))
		exit(0);
	if (mode)
	{
		if (fill_stack_a(&argv[2], &a))
			error_msg();
		print_stacks(a, b);
	}
	else if (fill_stack_a(&argv[1], &a))
		error_msg();
	if (reading_operations(&a, &b, mode))
		error_msg();
	if (check_result(a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
