/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:07:24 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void			ft_other_cases(char **format, t_pf *pf, t_printf *sarg)
{
	if (sarg->c == '%')
		pf_putescape(format, pf, sarg);
	else if (sarg->c == 'p')
		pf_putptr(format, pf, sarg);
	else if (sarg->c == 'n')
		pf_putprinted(format, pf, sarg);
}

void			pf_putnull(char **format, t_pf *pf, t_printf *arg)
{
	char c;

	c = arg->c;
	(void)(**format);
	(void)(pf);
	if ((arg->t & PF_GOT_ML) && !(arg->t & PF_MINUS))
		pf_putpad(pf, 1, arg->ml, (arg->t & PF_ZERO) ? '0' : ' ');
	pf_buffer(&c, 1, 0, pf);
	if ((arg->t & PF_GOT_ML) && (arg->t & PF_MINUS))
		pf_putpad(pf, 1, arg->ml, ' ');
}

void			pf_putescape(char **format, t_pf *pf, t_printf *arg)
{
	(void)(**format);
	(void)(arg);
	if ((arg->t & PF_GOT_ML) && !(arg->t & PF_MINUS))
		pf_putpad(pf, 1, arg->ml, (arg->t & PF_ZERO) ? '0' : ' ');
	pf_buffer("%", 1, 0, pf);
	if ((arg->t & PF_GOT_ML) && (arg->t & PF_MINUS))
		pf_putpad(pf, 1, arg->ml, ' ');
}

void			pf_putptr(char **format, t_pf *pf, t_printf *arg)
{
	uintmax_t	nbr;

	(void)format;
	arg->base = 16;
	arg->t |= PF_Z;
	if (arg->t & PF_GOT_PRECI)
		arg->t &= ~PF_ZERO;
	nbr = ft_get_unsigned(&pf->ar, arg);
	pf_put_nb_with_prefix(nbr, arg, (char*)"0x", pf);
}

void			pf_putprinted(char **format, t_pf *pf, t_printf *arg)
{
	(void)format;
	arg->base = 10;
	if ((arg->t & PF_GOT_ML) && !(arg->t & PF_MINUS))
		pf_putpad(pf, 1, arg->ml, (arg->t & PF_ZERO) ? '0' : ' ');
	pf_putuint(pf->ret + PF_BUF * pf->cb, arg, NULL, pf);
	if ((arg->t & PF_GOT_ML) && (arg->t & PF_MINUS))
		pf_putpad(pf, 1, arg->ml, ' ');
}
