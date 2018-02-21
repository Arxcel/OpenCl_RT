/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unum_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:31:56 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void			pf_putnbr(uintmax_t nbr,
							t_printf *arg, unsigned nbr_len, t_pf *pf)
{
	if ((arg->c == 'x' || arg->c == 'X') &&
				arg->t & PF_SHARP && arg->t & PF_ZERO)
		pf_putpad(pf, nbr_len + 2, arg->prec, '0');
	else if (arg->t & PF_GOT_PRECI)
		pf_putpad(pf, nbr_len, arg->prec, '0');
	if (nbr == 0 && arg->t & PF_GOT_PRECI && arg->prec == 0)
		return ;
	else
		ft_putnbrbase(nbr, arg->base, pf, arg);
}

void			pf_putuint(uintmax_t nbr,
		t_printf *arg, char *prefix, t_pf *pf)
{
	unsigned int			nbr_len;
	unsigned int			nbrstrlen;

	if (arg->t & PF_GOT_PRECI)
		arg->t &= ~PF_ZERO;
	nbr_len = ft_nbrlen(nbr, arg->base);
	if (arg->t & PF_GOT_ML && !(arg->t & PF_MINUS) && arg->t & PF_ZERO)
	{
		arg->prec = arg->t & PF_GOT_PRECI ? MAX(arg->ml, arg->prec)
												: MAX(arg->ml, nbr_len);
		arg->t |= PF_GOT_PRECI;
		arg->t &= ~PF_GOT_ML;
	}
	nbrstrlen = pf_nbrlen(nbr, prefix, arg);
	if (arg->t & PF_GOT_ML && !(arg->t & PF_MINUS))
		pf_putpad(pf, nbrstrlen, arg->ml, ' ');
	if (arg->t & PF_SHARP && prefix != NULL && nbr != 0)
		pf_buffer(prefix, ft_strlen(prefix), 0, pf);
	pf_putnbr(nbr, arg, nbr_len, pf);
	if (arg->t & PF_GOT_ML && arg->t & PF_MINUS)
		pf_putpad(pf, nbrstrlen, arg->ml, ' ');
}

void			pf_putu(char **format, t_pf *pf, t_printf *arg)
{
	uintmax_t	nbr;

	(void)format;
	arg->base = 10;
	nbr = ft_get_unsigned(&pf->ar, arg);
	pf_putuint(nbr, arg, NULL, pf);
}
