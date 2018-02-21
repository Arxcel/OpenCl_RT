/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 00:55:21 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

intmax_t		get_signed(va_list *args, t_printf *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->t & PF_HH)
		nbr = (char)nbr;
	else if (arg->t & PF_H)
		nbr = (short)nbr;
	else if (arg->t & PF_L)
		nbr = (long int)nbr;
	else if (arg->t & PF_LL)
		nbr = (long long int)nbr;
	else if (arg->t & PF_J)
		nbr = (intmax_t)nbr;
	else if (arg->t & PF_Z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t		ft_get_unsigned(va_list *args, t_printf *arg)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, uintmax_t);
	if (arg->t & PF_HH)
		nbr = (unsigned char)nbr;
	else if (arg->t & PF_H)
		nbr = (unsigned short int)nbr;
	else if (arg->t & PF_L)
		nbr = (unsigned long int)nbr;
	else if (arg->t & PF_LL)
		nbr = (unsigned long long int)nbr;
	else if (arg->t & PF_J)
		nbr = (uintmax_t)nbr;
	else if (arg->t & PF_Z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
