/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 00:35:53 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void			pf_putstr(char **format, t_pf *pf, t_printf *arg)
{
	char		*str;
	size_t		strlen;

	if (arg->t & PF_L)
		pf_putwstr(format, pf, arg);
	else
	{
		(void)format;
		str = va_arg(pf->ar, char *);
		if (str == NULL)
			str = (char *)"(null)";
		strlen = arg->t & PF_GOT_PRECI ? ft_strnlen(str,
										(size_t)arg->prec) : ft_strlen(str);
		if (arg->t & PF_GOT_ML && !(arg->t & PF_MINUS))
		{
			pf_putpad(pf, strlen, arg->ml, (arg->t & PF_ZERO)
													? (char)'0' : (char)' ');
		}
		pf_buffer(str, strlen, 0, pf);
		if ((arg->t & PF_GOT_ML) && (arg->t & PF_MINUS))
			pf_putpad(pf, strlen, arg->ml, ' ');
	}
}

void			pf_putwstr(char **format, t_pf *pf, t_printf *arg)
{
	wchar_t		*str;
	size_t		strlen;

	(void)format;
	(void)arg;
	str = va_arg(pf->ar, wchar_t *);
	if (str == NULL)
		str = L"(null)";
	strlen = arg->t & PF_GOT_PRECI ? pf_wstrlen(str, arg->prec, 0)
													: ft_wstrlen(str);
	if (arg->t & PF_GOT_ML && !(arg->t & PF_MINUS))
		pf_putpad(pf, strlen, arg->ml, (arg->t & PF_ZERO) ? '0' : ' ');
	ft_putnwstr(str, strlen, pf);
	if ((arg->t & PF_GOT_ML) && (arg->t & PF_MINUS))
		pf_putpad(pf, strlen, arg->ml, ' ');
}

void			ft_putnwstr(const wchar_t *str, size_t len, t_pf *pf)
{
	size_t i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar(*str++, pf);
	}
}

size_t			pf_wstrlen(wchar_t *str, int prec, size_t i)
{
	if (*str == '\0' || prec == 0)
		return (i);
	else if (*str <= 0x7F)
		return (pf_wstrlen(str + 1, prec - 1, i + 1));
	else if (*str <= 0x7FF && prec >= 2)
		return (pf_wstrlen(str + 1, prec - 2, i + 2));
	else if (*str <= 0xFFFF && prec >= 3)
		return (pf_wstrlen(str + 1, prec - 3, i + 3));
	else if (*str <= 0x10FFFF && prec >= 4)
		return (pf_wstrlen(str + 1, prec - 4, i + 4));
	else
		return (i);
}

size_t			ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}
