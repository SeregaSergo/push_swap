/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:07:35 by bswag             #+#    #+#             */
/*   Updated: 2021/04/28 21:50:35 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     reading_operations(t_list **a, t_list **b)
{
	char    *line;

	while (get_next_line(0, &line))
	{
		if (do_operation(line, a, b))
			return (1);
		free(line);
		// print_stacks(*a, *b);				// DEBUG LINE
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
		exit(0);
	if (fill_stack_a(&argv[1], &a))
		error_msg();
	// print_stacks(a, b);				// DEBUG LINE
	if (reading_operations(&a, &b))
		error_msg();
	if (check_result(a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	return (0);
}