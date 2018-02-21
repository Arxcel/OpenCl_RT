/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 02:17:16 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void	pf_putint(char **format, t_pf *pf, t_printf *arg)
{
	intmax_t				nbr;
	char					*prefix;

	(void)format;
	arg->base = 10;
	if (arg->t & PF_GOT_PRECI)
		arg->t &= ~PF_ZERO;
	if ((nbr = get_signed(&pf->ar, arg)) < 0 || arg->t & PF_SHARP
							|| arg->t & PF_SPACE || arg->t & PF_PLUS)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (arg->t & PF_PLUS)
			prefix = "+";
		else if (arg->t & PF_SPACE)
			prefix = " ";
		else
			prefix = "";
		pf_put_nb_with_prefix(nbr, arg, prefix, pf);
	}
	else
		pf_putuint(nbr, arg, NULL, pf);
}
