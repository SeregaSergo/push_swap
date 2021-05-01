/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:03:37 by bswag             #+#    #+#             */
/*   Updated: 2021/05/01 17:31:48 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	min_abs(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a > b)
		return (b);
	else
		return (a);
}

int	max_abs(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a < b)
		return (b);
	else
		return (a);
}

int	do_oper_print(char *oper, t_list **a, t_list **b, int n)
{
	while (n > 0)
	{
		do_operation(oper, a, b);
		ft_putendl_fd(oper, 1);
		n--;
	}
	return (0);
}
