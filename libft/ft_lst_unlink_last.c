/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_unlink_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:31:12 by bswag             #+#    #+#             */
/*   Updated: 2021/04/27 22:24:52 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_unlink_last(t_list **lst)
{
	t_list	*last;
	t_list	**prev;

	if (!*lst)
		return (NULL);
	last = *lst;
	prev = lst;
	while (last->next)
	{
		prev = &(last->next);
		last = last->next;
	}
	*prev = NULL;
	return (last);
}
