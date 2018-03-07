/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:01:13 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/07 21:51:48 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static char	*pair(const char *name, double value)
{
	char *buf;
	char *res;

	buf = ft_itoa(value);
	res = ft_strjoin(name, buf);
	free(buf);
	return (res);
}

char		*set_flags(const char *path)
{
	char *buf;
	char *to_free;
	char *flags;

	flags = ft_strjoin("-I ", path);
	buf = pair(" -D IMG_WIDTH=", WIN_W);
	to_free = flags;
	flags = ft_strjoin(flags, buf);
	free(to_free);
	free(buf);
	buf = pair(" -D WIN_WIDTH=", WIN_W);
	to_free = flags;
	flags = ft_strjoin(flags, buf);
	free(to_free);
	free(buf);
	buf = pair(" -D WIN_HEIGHT=", WIN_H);
	to_free = flags;
	flags = ft_strjoin(flags, buf);
	free(to_free);
	free(buf);
	buf = pair(" -D MAX_ITER=", MAX_ITER);
	to_free = flags;
	flags = ft_strjoin(flags, buf);
	free(to_free);
	free(buf);
	to_free = flags;
	flags = ft_strjoin(flags, " -D BIAS=0.3");
	free(to_free);
	to_free = flags;
	flags = ft_strjoin(flags, " -D INF=999999999999999999999999999999.9");
	free(to_free);
	return (flags);
}
