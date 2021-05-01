/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:12:08 by bswag             #+#    #+#             */
/*   Updated: 2021/05/01 16:51:28 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_msg(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	check_result(t_list *a)
{
	int	prev;

	prev = INT_MIN;
	while (a)
	{
		if (*((t_p_cntnt)a->content) < prev)
			return (1);
		prev = *((t_p_cntnt)a->content);
		a = a->next;
	}
	return (0);
}

int	check_int(t_cntnt arg, t_list *a)
{
	if (arg < INT_MIN || arg > INT_MAX)
		return (1);
	while (a)
	{
		if (*((t_p_cntnt)a->content) == arg)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_number(char *arg)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg != '\0')
	{
		if (!ft_isdigit(*arg))
			return (1);
		arg++;
	}
	return (0);
}

int	fill_stack_a(char **argv, t_list **a)
{
	long long int	arg;
	long long int	*new_cont;
	t_list			*new;

	while (*argv != NULL)
	{
		if (is_number(*argv))
			return (1);
		arg = ft_atoi_long(*argv);
		if (check_int(arg, *a))
			return (1);
		new_cont = (t_p_cntnt)malloc(sizeof(t_cntnt));
		if (!new_cont)
			return (1);
		*new_cont = arg;
		new = ft_lstnew(new_cont);
		if (!new)
			return (1);
		ft_lstadd_back(a, new);
		argv++;
	}
	return (0);
}
