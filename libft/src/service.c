/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:23:02 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void			pf_putpad(t_pf *pf, int strlen, int width, char c)
{
	while (strlen < width)
	{
		pf_buffer(&c, 1, 0, pf);
		strlen++;
	}
}

size_t			ft_strnlen(const char *str, size_t maxlen)
{
	size_t i;

	i = 0;
	while (*str++ && i < maxlen)
		i++;
	return (i);
}

void			pf_buffer(char *str, int size, int print, t_pf *pf)
{
	char	*tmp;
	int		l;

	l = 0;
	tmp = pf->res;
	while (l < size)
	{
		if (pf->ret / PF_BUF == 1)
		{
			write(1, pf->res, PF_BUF);
			ft_strclr(pf->res);
			pf->i = 0;
			pf->cb++;
		}
		if (!str)
			tmp[pf->i] = '\0';
		else
			tmp[pf->i] = str[l];
		pf->ret++;
		pf->i++;
		l++;
	}
	if (print)
		write(1, pf->res, pf->i);
}
