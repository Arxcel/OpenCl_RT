/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:01:13 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/20 17:36:11 by afarapon         ###   ########.fr       */
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
	char *to_free;
	char *flags;

	flags = ft_strjoin("-I ", path);
	flags = add_value(pair(" -D MAX_ITER=", MAX_ITER), flags);
	to_free = flags;
	flags = ft_strjoin(flags, " -D BIAS=0.03");
	free(to_free);
	to_free = flags;
	flags = ft_strjoin(flags, " -D INF=999999999999999999999999999999.9");
	free(to_free);
	return (flags);
}
