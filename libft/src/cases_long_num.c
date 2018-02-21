/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_long_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 02:16:29 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void	pf_putlong(char **format, t_pf *pf, t_printf *arg)
{
	if ((arg->t & PF_HH))
		arg->t &= ~PF_HH;
	if ((arg->t & PF_H))
		arg->t &= ~PF_H;
	arg->t |= PF_L;
	if (arg->c == 'D')
		pf_putint(format, pf, arg);
	else if (arg->c == 'O')
		pf_putoct(format, pf, arg);
	else if (arg->c == 'U')
		pf_putu(format, pf, arg);
}
