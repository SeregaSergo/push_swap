/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:20:06 by bswag             #+#    #+#             */
/*   Updated: 2021/04/30 20:29:31 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int		abs(int x)
{
	return (x < 0 ? -x : x);
}

int		min_abs(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a > b)
		return (b);
	else
		return (a);
}

int		max_abs(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a < b)
		return (b);
	else
		return (a);
}

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
		*i_a = abs(oper->r_a) < abs(oper->rr_a) ? oper->r_a : oper->rr_a;
		*i_b = abs(oper->r_b) < abs(oper->rr_b) ? oper->r_b : oper->rr_b;
	}
}

void	max_min_elem_list(t_list *a, t_mml *mml)
{
	int				i;
	long long int	val;
	
	i = 0;
	mml->max_val = LLONG_MIN;
	mml->min_val = LLONG_MAX;
	while (a)
	{
		val = *((long long int *)a->content);
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

void	fill_oper_struct(t_list *a, t_oper *oper, long long int x)
{
	long long int	prev;
	long long int	cur;
	t_mml			mml;
	int				i;
	int				len;
	
	i = 0;
	max_min_elem_list(a, &mml);
	len = ft_lstsize(a);
	if (x < mml.min_val || x > mml.max_val)
	{
		oper->r_a = mml.min_pos;
		oper->rr_a = mml.min_pos == 0 ? 0 : mml.min_pos - len;
	}
	else
	{
		prev = *((long long int *)ft_lstlast(a)->content);
		cur = *((long long int *)a->content);
		while (!(x < cur && x > prev))
		{
			prev = cur;
			i++;
			a = a->next;
			cur = *((long long int *)a->content);
		}
		oper->r_a = i;
		oper->rr_a = i == 0 ? 0 : i - len;
	}
}

int		how_many_oper(t_list *a, t_oper *oper, long long int x)
{
	int	min;
	int	res;
	
	min = INT_MAX;
	fill_oper_struct(a, oper, x);
	if ((res = min_abs(oper->r_a, oper->rr_a) + min_abs(oper->r_b, oper->rr_b)) < min)
		min = res;
	if ((res = max_abs(oper->r_a, oper->r_b)) < min)
		min = res;
	if ((res = max_abs(oper->rr_a, oper->rr_b)) < min)
		min = res;
	return (min);
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
		oper.rr_b = i == 0 ? 0 : i - len;
		if ((res = how_many_oper(a, &oper, (*(long long int *)b->content))) < min)
		{
			min = res;
			fill_result(i_a, i_b, &oper, min);
			// printf("oper: r_a = %i, r_b = %i, rr_a = %i, rr_b = %i\n", oper.r_a, oper.r_b, oper.rr_a, oper.rr_b);
			// printf("choose elem with pos = %i\ni_a = %i, i_b = %i, min = %i\n", i, *i_a, *i_b, min);
		}
		b = b->next;
		i++;
	}
}

void		prepare_push_back(t_list **a, t_list **b)
{
	int	i_a;
	int	i_b;
	int	min;
	
	i_a = 0;
	i_b = 0;
	search_a_winner(*a, *b, &i_a, &i_b);
	if ((i_a * i_b) > 0)
	{
		min = min_abs(i_a, i_b);
		if (i_a < 0)
		{
			do_oper_print("rrr", a, b, min);
			i_a += min;
			i_b += min;
		}
		else
		{
			do_oper_print("rr", a, b, min);
			i_a -= min;
			i_b -= min;
		}
	}
	if (i_a > 0)
		do_oper_print("ra", a, b, i_a);
	else if (i_a != 0)
		do_oper_print("rra", a, b, -i_a);
	if (i_b > 0)
		do_oper_print("rb", a, b, i_b);
	else if (i_b != 0)
		do_oper_print("rrb", a, b, -i_b);
}