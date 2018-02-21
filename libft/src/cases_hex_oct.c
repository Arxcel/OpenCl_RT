/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_hex_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 02:17:52 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void	pf_putoct(char **format, t_pf *pf, t_printf *arg)
{
	uintmax_t	nbr;

	(void)format;
	arg->base = 8;
	nbr = ft_get_unsigned(&pf->ar, arg);
	if (arg->t & PF_SHARP && nbr == 0 &&
				arg->t & PF_GOT_PRECI && arg->prec == 0)
	{
		if (arg->t & PF_GOT_ML && !(arg->t & PF_MINUS))
			pf_putpad(pf, 1, arg->ml, arg->t & PF_ZERO ? '0' : ' ');
		pf_buffer("0", 1, 0, pf);
		if (arg->t & PF_GOT_ML && arg->t & PF_MINUS)
			pf_putpad(pf, 1, arg->ml, ' ');
	}
	else if (arg->t & PF_SHARP && nbr != 0)
	{
		arg->t |= PF_GOT_PRECI;
		arg->prec = MAX(arg->prec, ft_nbrlen(nbr, 8) + 1);
	}
	pf_putuint(nbr, arg, NULL, pf);
}

void	pf_puthex(char **format, t_pf *pf, t_printf *arg)
{
	uintmax_t	nbr;

	(void)format;
	arg->base = 16;
	nbr = ft_get_unsigned(&pf->ar, arg);
	if (arg->c == 'X')
		pf_putuint(nbr, arg, (char*)"0X", pf);
	else
		pf_putuint(nbr, arg, (char*)"0x", pf);
}
