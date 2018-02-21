/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:34:42 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void			ft_char_cases(char **format, t_pf *pf, t_printf *sarg)
{
	if (sarg->c == 's')
		pf_putstr(format, pf, sarg);
	if (sarg->c == 'c')
		pf_putchar(format, pf, sarg);
	if (sarg->c == 'C')
		pf_putchar(format, pf, sarg);
	if (sarg->c == 'S')
		pf_putwstr(format, pf, sarg);
}
