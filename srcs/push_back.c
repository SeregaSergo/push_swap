/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:20:06 by bswag             #+#    #+#             */
/*   Updated: 2021/05/01 19:12:23 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_result(int *i_a, int *i_b, t_oper *oper, int min)
{
	if (max_abs(oper->r_b, oper->r_a) == min)
	{
		*i_a = oper->r_a;
		*i_b = oper->r_b;
	}
	else if (max_abs(oper->rr_b, oper->rr_a) == min)
	{
		*i_a = oper->rr_a;
		*i_b = oper->rr_b;
	}
	else
	{
		if (abs(oper->r_a) < abs(oper->rr_a))
			*i_a = oper->r_a;
		else
			*i_a = oper->rr_a;
		if (abs(oper->r_b) < abs(oper->rr_b))
			*i_b = oper->r_b;
		else
			*i_b = oper->rr_b;
	}
}

void	search_a_winner(t_list *a, t_list *b, int *i_a, int *i_b)
{
	int		min;
	int		i;
	t_oper	oper;
	int		res;
	int		len;

	min = INT_MAX;
	i = 0;
	len = ft_lstsize(b);
	while (b)
	{
		oper.r_b = i;
		if (i == 0)
			oper.rr_b = 0;
		else
			oper.rr_b = i - len;
		res = how_many_oper(a, &oper, *(t_p_cntnt)b->content);
		if (res < min)
		{
			min = res;
			fill_result(i_a, i_b, &oper, min);
		}
		b = b->next;
		i++;
	}
}

void	make_double_rot_rev(t_list **a, t_list **b, int	*i_a, int *i_b)
{
	int	min;

	min = min_abs(*i_a, *i_b);
	if (*i_a < 0)
	{
		do_oper_print("rrr", a, b, min);
		*i_a += min;
		*i_b += min;
	}
	else
	{
		do_oper_print("rr", a, b, min);
		*i_a -= min;
		*i_b -= min;
	}
}

void	prepare_push_back(t_list **a, t_list **b)
{
	int	i_a;
	int	i_b;

	i_a = 0;
	i_b = 0;
	search_a_winner(*a, *b, &i_a, &i_b);
	if ((i_a * i_b) > 0)
		make_double_rot_rev(a, b, &i_a, &i_b);
	if (i_a > 0)
		do_oper_print("ra", a, b, i_a);
	else if (i_a != 0)
		do_oper_print("rra", a, b, -i_a);
	if (i_b > 0)
		do_oper_print("rb", a, b, i_b);
	else if (i_b != 0)
		do_oper_print("rrb", a, b, -i_b);
}
