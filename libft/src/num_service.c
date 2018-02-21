/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_service.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 01:08:48 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

size_t				ft_nbrlen(uintmax_t nbr, int base)
{
	size_t nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		nbr_len++;
	}
	return (nbr_len);
}

size_t				pf_nbrlen(uintmax_t nbr,
							char *p, t_printf *arg)
{
	size_t nbr_len;
	size_t nbrstrlen;

	nbr_len = ft_nbrlen(nbr, arg->base);
	if (nbr == 0 && arg->t & PF_GOT_PRECI && arg->prec == 0)
		nbrstrlen = 0;
	else if (arg->t & PF_GOT_PRECI)
		nbrstrlen = MAX(nbr_len, arg->prec);
	else
		nbrstrlen = nbr_len;
	if (arg->t & PF_SHARP && p != NULL && nbr != 0)
		nbrstrlen += ft_strlen(p);
	return (nbrstrlen);
}

static void			private_putnbrbase(uintmax_t nbr,
								char *base, size_t baselen, t_pf *pf)
{
	if (nbr >= baselen)
	{
		private_putnbrbase(nbr / baselen, base, baselen, pf);
		private_putnbrbase(nbr % baselen, base, baselen, pf);
	}
	else
		pf_buffer(&base[nbr], 1, 0, pf);
}

void				ft_putnbrbase(uintmax_t nbr, int base,
											t_pf *pf, t_printf *arg)
{
	char *b;

	b = NULL;
	if (base == 2)
		b = "01";
	else if (base == 8)
		b = "01234567";
	else if (base == 10)
		b = "0123456789";
	else if (base == 16 && arg->c == 'X')
		b = "0123456789ABCDEF";
	else if (base == 16)
		b = "0123456789abcdef";
	private_putnbrbase(nbr, b, ft_strlen(b), pf);
}
