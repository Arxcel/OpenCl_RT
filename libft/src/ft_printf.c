/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:32:35 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void			get_operator(char **format, t_pf *pf, t_printf *sarg)
{
	if (ft_strchr("cCsS", sarg->c))
		ft_char_cases(format, pf, sarg);
	else if (ft_strchr("idDxXoOuUb", sarg->c))
		ft_num_cases(format, pf, sarg);
	else if (ft_strchr("pn%", sarg->c))
		ft_other_cases(format, pf, sarg);
	else
		pf_putnull(format, pf, sarg);
}

static int		pf_process_arg(char **format,
										t_pf *pf, t_printf *sarg)
{
	if (*(++(*format)) == '\0')
		return (0);
	if ((pf_flags(format, sarg)) == NULL)
		return (-1);
	if ((pf_min_len(format, pf, sarg)) == NULL)
		return (-1);
	if ((pf_precision(format, pf, sarg)) == NULL)
		return (-1);
	if ((pf_length(format, sarg)) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	sarg->c = **format;
	(*format)++;
	get_operator(format, pf, sarg);
	return (1);
}

static void		private_printf(const char *format, t_pf *pf)
{
	t_printf		sarg;
	ssize_t			handler_len;

	while (*format)
	{
		if (*format == '%')
		{
			ft_bzero(&sarg, sizeof(sarg));
			handler_len = pf_process_arg((char**)&format, pf, &sarg);
			if (handler_len == -1)
				return ;
			else
				continue ;
		}
		pf_buffer((char*)format, 1, 0, pf);
		format++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_pf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.ret = 0;
	va_start(pf.ar, format);
	private_printf(format, &pf);
	va_end(pf.ar);
	pf_buffer(NULL, 0, 1, &pf);
	return (pf.ret + PF_BUF * pf.cb);
}
