/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:04:59 by bswag             #+#    #+#             */
/*   Updated: 2021/05/01 18:38:46 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <fcntl.h>

void	check_swaps(t_list **a, t_list **b)
{
	int	change;

	change = 0;
	if (*a && (*a)->next)
	{
		if (*(t_p_cntnt)(*a)->content > *(t_p_cntnt)(*a)->next->content)
			change = 1;
	}
	if (*b && (*b)->next)
	{
		if (*(t_p_cntnt)(*b)->content < *(t_p_cntnt)(*b)->next->content)
			change += 10;
	}
	if (change == 11)
		do_oper_print("ss", a, b, 1);
	if (change == 10)
		do_oper_print("sb", a, b, 1);
	if (change == 1)
		do_oper_print("sa", a, b, 1);
}

t_cntnt	find_middle_int(t_list *stack)
{
	int			len;
	t_p_cntnt	ar;
	int			i;
	t_cntnt		res;

	i = 0;
	len = ft_lstsize(stack);
	ar = (t_p_cntnt)malloc(sizeof(t_cntnt) * len);
	if (!ar)
		error_msg();
	while (stack)
	{
		ar[i] = *(t_p_cntnt)stack->content;
		stack = stack->next;
		i++;
	}
	part(ar, 0, len - 1);
	res = ar[len / 2];
	free(ar);
	return (res);
}

int	check_reverse_rotate(t_list **a, t_list **b)
{
	t_cntnt	mod_a;
	t_cntnt	mod_b;
	int		rotate;
	int		reverse;

	mod_a = find_middle_int(*a);
	mod_b = find_middle_int(*b);
	rotate = what_to_rotate(*a, *b, mod_a, mod_b);
	reverse = what_to_reverse(*a, *b, mod_a, mod_b);
	if (reverse == 11)
		return (do_oper_print("rrr", a, b, 1));
	if (rotate == 11)
		return (do_oper_print("rr", a, b, 1));
	if (rotate == 10)
		return (do_oper_print("rb", a, b, 1));
	if (rotate == 1)
		return (do_oper_print("ra", a, b, 1));
	if (reverse == 10)
		return (do_oper_print("rrb", a, b, 1));
	if (reverse == 1)
		return (do_oper_print("rra", a, b, 1));
	return (0);
}

void	sort_stack(t_list **a, t_list **b)
{
	int		len;
	t_cntnt	mid;
	t_mml	mml;

	mid = find_middle_int(*a);
	len = ft_lstsize(*a);
	while (len-- != 1 && check_result(*a))
	{
		check_reverse_rotate(a, b);
		check_swaps(a, b);
		if (check_result(*a))
			do_oper_print("pb", a, b, 1);
	}
	len = ft_lstsize(*b);
	while (len-- != 0)
	{
		prepare_push_back(a, b);
		do_oper_print("pa", a, b, 1);
	}
	max_min_elem_list(*a, &mml);
	if (mml.min_pos < (ft_lstsize(*a) / 2))
		do_oper_print("ra", a, b, mml.min_pos);
	else
		do_oper_print("rra", a, b, ft_lstsize(*a) - mml.min_pos);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc < 2)
		error_msg();
	if (fill_stack_a(&argv[1], &a))
		error_msg();
	sort_stack(&a, &b);
	return (0);
}
