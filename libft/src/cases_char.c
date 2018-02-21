/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 00:35:07 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void		pf_putchar(char **format, t_pf *pf, t_printf *arg)
{
	char c;

	(void)format;
	c = va_arg(pf->ar, int);
	if (arg->t & PF_GOT_ML && !(arg->t & PF_MINUS))
		pf_putpad(pf, 1, arg->ml, (arg->t & PF_ZERO) ? '0' : ' ');
	if (c == 0)
		pf_buffer(NULL, 1, 0, pf);
	if (c != 0)
		pf_buffer(&c, 1, 0, pf);
	if ((arg->t & PF_GOT_ML) && (arg->t & PF_MINUS))
		pf_putpad(pf, 1, arg->ml, ' ');
}
