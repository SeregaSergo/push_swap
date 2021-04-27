/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:54:30 by bswag             #+#    #+#             */
/*   Updated: 2021/03/18 17:25:12 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_pos(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (!s[i])
			return (-1);
		i++;
	}
	return (i);
}
