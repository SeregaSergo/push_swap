/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:46:15 by bswag             #+#    #+#             */
/*   Updated: 2021/04/28 20:51:23 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_get_dimention(long long int number)
{
	int result;

	result = 1;
	number = number < 0 ? number * (-1): number;
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
	i = a_elem <= INT_MAX ? 12 - ft_get_dimention(a_elem) : 11;
	i = b_elem < 0 ? i - 1: i;
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
	int				len_a;
	int				len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	i = len_b >= len_a ? len_b : len_a;
	a_elem = LLONG_MAX;
	b_elem = LLONG_MAX;
	while (i > 0)
	{
		if (i <= len_a)
		{
			a_elem = *((long long int *)a->content);
			a = a->next;
		}
		if (i <= len_b)
		{
			b_elem = *((long long int *)b->content);
			b = b->next;
		}
		print_line_stack(a_elem, b_elem);
		i--;
	}
	ft_putstr_fd("-----------------\n  a           b\n", 1);
}