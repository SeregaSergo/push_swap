/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:31:11 by bswag             #+#    #+#             */
/*   Updated: 2021/04/27 22:40:26 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		f_dbl_swap(t_list **a, t_list **b)
{
	f_swap(a);
	f_swap(b);
	return (0);
}

int		f_dbl_rotate(t_list **a, t_list **b)
{
	f_rotate(a);
	f_rotate(b);
	return (0);
}

int		f_dbl_reverse(t_list **a, t_list **b)
{
	f_reverse(a);
	f_reverse(b);
	return (0);
}
