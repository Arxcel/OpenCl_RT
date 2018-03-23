/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_blur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:22:45 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 15:45:57 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static unsigned int		*one_time_blur(t_ae *ae, unsigned int *in, size_t size)
{
	size_t			x;
	size_t			y;
	unsigned int	*res;

	y = 0;
	res = (unsigned int*)malloc(sizeof(unsigned int) * size);
	*ae->pixels = in;
	while (++y < (*ae->h - 1) && !(x = 0))
		while (++x < (*ae->w - 1))
			res[x + y * *ae->w] = set_smooth(ae, x, y, in);
	free(in);
	return (res);
}

void					set_blur(t_ae *ae,
	unsigned int **in_out, size_t count)
{
	size_t			i;

	i = -1;
	while (++i < count)
		*in_out = one_time_blur(ae, *in_out,
			*ae->h * *ae->w);
}
