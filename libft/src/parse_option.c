/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:08:40 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

char	*pf_flags(char **format, t_printf *arg)
{
	if (**format == '#' || **format == '0' || **format == '-' || **format == '+'
		|| **format == ' ')
	{
		if (**format == '#')
			arg->t |= PF_SHARP;
		else if (**format == '0')
			arg->t |= PF_ZERO;
		else if (**format == '-')
			arg->t |= PF_MINUS;
		else if (**format == '+')
			arg->t |= PF_PLUS;
		else if (**format == ' ')
			arg->t |= PF_SPACE;
		(*format)++;
		if (arg->t & PF_MINUS)
			arg->t &= ~PF_ZERO;
		return (pf_flags(format, arg));
	}
	else
		return (*format);
}

char	*pf_min_len(char **format, t_pf *pf, t_printf *arg)
{
	int	len;

	arg->t &= ~PF_GOT_ML;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			len = va_arg(pf->ar, int);
			if (len < 0)
				arg->t |= PF_MINUS;
			arg->ml = len < 0 ? -len : len;
			arg->t |= PF_GOT_ML;
		}
		if (ft_isdigit(**format))
		{
			arg->t |= PF_GOT_ML;
			arg->ml = 0;
			while (ft_isdigit(**format))
				arg->ml = arg->ml * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

char	*pf_precision(char **format, t_pf *pf, t_printf *arg)
{
	arg->t &= ~PF_GOT_PRECI;
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			if ((arg->prec = va_arg(pf->ar, int)) >= 0)
				arg->t |= PF_GOT_PRECI;
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				arg->prec = arg->prec * 10 + (*(*format)++ - '0');
			arg->t |= PF_GOT_PRECI;
			return (*format);
		}
	}
	else
		return (*format);
}

char	*pf_length(char **format, t_printf *arg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		arg->t |= PF_HH;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		arg->t |= PF_LL;
		return (*format += 2);
	}
	if (**format == 'h' || **format == 'l' || **format == 'j' ||
					**format == 'z')
	{
		if (**format == 'h')
			arg->t |= PF_H;
		else if (**format == 'l')
			arg->t |= PF_L;
		else if (**format == 'j')
			arg->t |= PF_J;
		else if (**format == 'z')
			arg->t |= PF_Z;
		return ((*format)++);
	}
	else
		return (*format);
}
