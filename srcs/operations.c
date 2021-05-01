/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:06:39 by bswag             #+#    #+#             */
/*   Updated: 2021/05/01 14:44:24 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	f_swap(t_list **stack)
{
	void	*tmp;

	if (stack && *stack && (*stack)->next)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
	return (0);
}

int	f_rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
	return (0);
}

int	f_reverse(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		tmp = ft_lst_unlink_last(stack);
		ft_lstadd_front(stack, tmp);
	}
	return (0);
}

int	f_push(t_list **src, t_list **dst)
{
	t_list	*tmpsrc;

	if (*src)
	{
		tmpsrc = *src;
		*src = (*src)->next;
		tmpsrc->next = *dst;
		*dst = tmpsrc;
	}
	return (0);
}

int	do_operation(char *oper, t_list **a, t_list **b)
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
