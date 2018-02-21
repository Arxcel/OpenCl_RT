/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 01:37:10 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

static void		ft_put1byte(char wc, t_pf *pf)
{
	char c;

	c = wc;
	pf_buffer(&c, 1, 0, pf);
}

static void		ft_put2byte(char wc, t_pf *pf)
{
	char c;

	c = (wc >> 6) + 0xC0;
	pf_buffer(&c, 1, 0, pf);
	c = (wc & 0x3F) + 0x80;
	pf_buffer(&c, 1, 0, pf);
}

static void		ft_put3byte(char wc, t_pf *pf)
{
	char c;

	c = (wc >> 12) + 0xE0;
	pf_buffer(&c, 1, 0, pf);
	c = ((wc >> 6) & 0x3F) + 0x80;
	pf_buffer(&c, 1, 0, pf);
	c = (wc & 0x3F) + 0x80;
	pf_buffer(&c, 1, 0, pf);
}

static void		ft_put4byte(char wc, t_pf *pf)
{
	char c;

	c = (wc >> 18) + 0xF0;
	pf_buffer(&c, 1, 0, pf);
	c = ((wc >> 12) & 0x3F) + 0x80;
	pf_buffer(&c, 1, 0, pf);
	c = ((wc >> 6) & 0x3F) + 0x80;
	pf_buffer(&c, 1, 0, pf);
	c = (wc & 0x3F) + 0x80;
	pf_buffer(&c, 1, 0, pf);
}

void			ft_putwchar(wchar_t wc, t_pf *pf)
{
	if (wc <= 0x7F)
		ft_put1byte(wc, pf);
	else if (wc <= 0x7FF)
		ft_put2byte(wc, pf);
	else if (wc <= 0xFFFF)
		ft_put3byte(wc, pf);
	else if (wc <= 0x10FFFF)
		ft_put4byte(wc, pf);
}
