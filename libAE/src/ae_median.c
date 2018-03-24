/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:43:53 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 19:34:35 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static unsigned int		set_median(t_ae *ae, size_t x, size_t y)
{
	t_color			result;
	size_t			w;

	w = *ae->w;
	result.argb.red = get_median_red(x, y, ae);
	result.argb.green = get_median_green(x, y, ae);
	result.argb.blue = get_median_blue(x, y, ae);
	return (result.col);
}

static unsigned int		*one_time_median(t_ae *ae,
	unsigned int *in, size_t size)
{
	size_t			x;
	size_t			y;
	unsigned int	*res;

	y = 1;
	res = (unsigned int*)malloc(sizeof(unsigned int) * size);
	*ae->pixels = in;
	while (++y < (*ae->h - 2) && (x = 1))
		while (++x < (*ae->w - 2))
			res[x + y * *ae->w] = set_median(ae, x, y);
	free(in);
	return (res);
}

void					ae_set_median(t_ae *ae,
	unsigned int **in_out, size_t count)
{
	size_t			i;

	i = -1;
	while (++i < count)
		*in_out = one_time_median(ae, *in_out,
			*ae->h * *ae->w);
}
