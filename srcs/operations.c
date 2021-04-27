/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:06:39 by bswag             #+#    #+#             */
/*   Updated: 2021/04/27 22:40:55 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		f_swap(t_list **stack)
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

int		f_rotate(t_list **stack)
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

int		f_reverse(t_list **stack)
{
	t_list	*tmp;
	
	if (*stack)
	{
		tmp = ft_lst_unlink_last(stack);
		ft_lstadd_front(stack, tmp);
	}
	return (0);
}

int		f_push(t_list **src, t_list **dst)
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
