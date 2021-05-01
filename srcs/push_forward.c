/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:25:32 by bswag             #+#    #+#             */
/*   Updated: 2021/05/01 18:39:29 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_p_cntnt	copy_array(t_p_cntnt ar, int s, int e)
{
	t_p_cntnt	new;
	int			len;

	len = e - s + 1;
	new = (t_p_cntnt)malloc(sizeof(t_cntnt) * (len + 1));
	if (!new)
		error_msg();
	new[len] = LLONG_MAX;
	while (len > 0)
	{
		new[len - 1] = ar[s + len - 1];
		len--;
	}
	return (new);
}

void	merge(t_p_cntnt ar, int s, int m, int e)
{
	t_p_cntnt	L;
	t_p_cntnt	R;
	t_cntnt		i;
	t_cntnt		j;

	L = copy_array(ar, s, m);
	R = copy_array(ar, m + 1, e);
	i = 0;
	j = 0;
	while (s <= e)
	{
		if (L[i] <= R[j])
		{
			ar[s] = L[i];
			i++;
		}
		else
		{
			ar[s] = R[j];
			j++;
		}
		s++;
	}
	free(L);
	free(R);
}

/*
** This is a main function of merge-sort based on divide and conquer algorithm
*/
void	part(t_p_cntnt ar, int start_pos, int end_pos)
{
	int	middle;

	if (start_pos < end_pos)
	{
		middle = (start_pos + end_pos) / 2;
		part(ar, start_pos, middle);
		part(ar, middle + 1, end_pos);
		merge(ar, start_pos, middle, end_pos);
	}
}

int	what_to_rotate(t_list *a, t_list *b, t_cntnt mod_a, t_cntnt mod_b)
{
	int	res;

	res = 0;
	if (a && *(t_p_cntnt)a->content > mod_a)
		res += 1;
	if (b && *(t_p_cntnt)b->content < mod_b)
		res += 10;
	return (res);
}

int	what_to_reverse(t_list *a, t_list *b, t_cntnt mod_a, t_cntnt mod_b)
{
	int	res;

	res = 0;
	if (a && *((t_p_cntnt)ft_lstlast(a)->content) < mod_a)
		res += 1;
	if (b && *((t_p_cntnt)ft_lstlast(b)->content) > mod_b)
		res += 10;
	return (res);
}
