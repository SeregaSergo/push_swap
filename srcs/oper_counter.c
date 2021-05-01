/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:09:05 by bswag             #+#    #+#             */
/*   Updated: 2021/05/01 19:12:59 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	max_min_elem_list(t_list *a, t_mml *mml)
{
	int		i;
	t_cntnt	val;

	i = 0;
	mml->max_val = LLONG_MIN;
	mml->min_val = LLONG_MAX;
	while (a)
	{
		val = *((t_p_cntnt)a->content);
		if (val > mml->max_val)
		{
			mml->max_val = val;
			mml->max_pos = i;
		}
		if (val < mml->min_val)
		{
			mml->min_val = val;
			mml->min_pos = i;
		}
		i++;
		a = a->next;
	}
}

int	check_min_max_condidate(t_list *a, t_oper *oper, t_cntnt x)
{
	t_mml	mml;

	max_min_elem_list(a, &mml);
	if (x < mml.min_val || x > mml.max_val)
	{
		oper->r_a = mml.min_pos;
		if (mml.min_pos == 0)
			oper->rr_a = 0;
		else
			oper->rr_a = mml.min_pos - ft_lstsize(a);
		return (0);
	}
	return (1);
}

void	fill_oper_struct(t_list *a, t_oper *oper, t_cntnt x)
{
	t_cntnt	prev;
	t_cntnt	cur;
	int		i;
	int		len;

	i = 0;
	len = ft_lstsize(a);
	if (check_min_max_condidate(a, oper, x))
	{
		prev = *((t_p_cntnt)ft_lstlast(a)->content);
		cur = *((t_p_cntnt)a->content);
		while (!(x < cur && x > prev))
		{
			prev = cur;
			i++;
			a = a->next;
			cur = *((t_p_cntnt)a->content);
		}
		oper->r_a = i;
		if (i == 0)
			oper->rr_a = 0;
		else
			oper->rr_a = i - len;
	}
}

int	how_many_oper(t_list *a, t_oper *oper, t_cntnt x)
{
	int	min;
	int	res;

	min = INT_MAX;
	fill_oper_struct(a, oper, x);
	res = min_abs(oper->r_a, oper->rr_a) + min_abs(oper->r_b, oper->rr_b);
	if (res < min)
		min = res;
	res = max_abs(oper->r_a, oper->r_b);
	if (res < min)
		min = res;
	res = max_abs(oper->rr_a, oper->rr_b);
	if (res < min)
		min = res;
	return (min);
}
