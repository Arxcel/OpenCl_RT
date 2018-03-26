/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:01:13 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/26 10:05:42 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static char		*pair(const char *name, double value)
{
	char *buf;
	char *res;

	buf = ft_itoa(value);
	res = ft_strjoin(name, buf);
	free(buf);
	return (res);
}

static char		*add_value(char *value, char *base)
{
	char *to_free;

	to_free = base;
	base = ft_strjoin(base, value);
	free(to_free);
	free(value);
	return (base);
}

char			*set_flags(const char *path)
{
	char *flags;

	flags = ft_strjoin("-I ", path);
	flags = add_value(pair(" -D MAX_ITER=", MAX_ITER), flags);
	return (flags);
}
