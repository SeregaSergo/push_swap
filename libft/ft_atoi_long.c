/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bswag <bswag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:43:01 by bswag             #+#    #+#             */
/*   Updated: 2021/04/27 17:44:47 by bswag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoi_long(const char *str)
{
	long long int	result;
	int	sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
