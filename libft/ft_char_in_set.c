/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:13:40 by bswag             #+#    #+#             */
/*   Updated: 2021/03/16 20:55:11 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_in_set(char c, char *pattern)
{
	int	i;

	i = 0;
	while (pattern[i])
	{
		if (c == pattern[i])
			return (1);
		i++;
	}
	return (0);
}