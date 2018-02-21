/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:37:25 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void			ft_num_cases(char **format, t_pf *pf, t_printf *sarg)
{
	if (sarg->c == 'i' || sarg->c == 'd')
		pf_putint(format, pf, sarg);
	else if (sarg->c == 'o')
		pf_putoct(format, pf, sarg);
	else if (sarg->c == 'x' || sarg->c == 'X')
		pf_puthex(format, pf, sarg);
	else if (ft_strchr("DOU", sarg->c))
		pf_putlong(format, pf, sarg);
	else if (sarg->c == 'b')
		pf_putbinary(format, pf, sarg);
	else if (sarg->c == 'u')
		pf_putu(format, pf, sarg);
}

void			pf_put_nb_with_prefix(uintmax_t nbr,
							t_printf *arg, char *prefix, t_pf *pf)
{
	size_t nbr_len;
	size_t nbr_cut;

	nbr_cut = ft_strlen(prefix);
	nbr_len = pf_nbrlen(nbr, NULL, arg) + nbr_cut;
	if (arg->t & PF_GOT_ML && !(arg->t & PF_MINUS) && !(arg->t & PF_ZERO))
	{
		pf_putpad(pf, nbr_len, arg->ml, ' ');
		arg->t &= ~PF_GOT_ML;
	}
	else if (arg->t & PF_GOT_ML)
		arg->ml -= nbr_cut;
	pf_buffer(prefix, nbr_cut, 0, pf);
	pf_putuint(nbr, arg, NULL, pf);
}

void			pf_putbinary(char **format, t_pf *pf, t_printf *arg)
{
	uintmax_t nbr;

	(void)format;
	arg->base = 2;
	nbr = ft_get_unsigned(&pf->ar, arg);
	pf_putuint(nbr, arg, (char *)"0b", pf);
}
