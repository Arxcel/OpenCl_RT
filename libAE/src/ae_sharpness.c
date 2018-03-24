/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_sharpness.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:43:08 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 14:31:43 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static unsigned int		*make_sharpness(t_ae *ae,
	unsigned int *in, size_t size)
{
	size_t			x;
	size_t			y;
	unsigned int	*res;

	y = 0;
	res = (unsigned int*)malloc(sizeof(unsigned int) * size);
	ft_bzero(res, sizeof(unsigned int) * size);
	while (++y < (*ae->h - 1) && !(x = 0))
		while (++x < (*ae->w - 1))
			res[x + y * *ae->w] = set_sharpness(ae, x, y, in);
	free(in);
	return (res);
}

void					ae_sharpness(t_ae *ae,
	unsigned int **in_out, size_t count)
{
	size_t			i;

	i = -1;
	while (++i < count)
		*in_out = make_sharpness(ae, *in_out, *ae->h * *ae->w);
}
