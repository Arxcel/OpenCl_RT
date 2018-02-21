/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:50:12 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

int		ft_atoi(const char *str)
{
	unsigned long long	nbr;
	unsigned long long	max;
	int					sign;

	sign = 1;
	nbr = 0;
	max = 9223372036854775807;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*(str++) - 48);
		if (nbr > max && sign == 1)
			return (-1);
		if (nbr > max + 1 && sign == -1)
			return (0);
	}
	return (sign * nbr);
}
