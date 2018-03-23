/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_triple_blur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:16:18 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 14:37:14 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static unsigned int		*triple_blur(t_ae *ae, unsigned int *in, size_t size)
{
	size_t			x;
	size_t			y;
	unsigned int	*res;

	y = 1;
	res = (unsigned int*)malloc(sizeof(unsigned int) * size);
	ft_bzero(res, sizeof(unsigned int) * size);
	while (++y < (*ae->h - 2) && (x = 1))
		while (++x < (*ae->w - 2))
			res[x + y * *ae->w] = set_test_blur(ae, in, x, y);
	free(in);
	return (res);
}

void					ae_triple_blur(t_ae *ae,
	unsigned int **in_out, size_t count)
{
	size_t			i;

	i = -1;
	while (++i < count)
		*in_out = triple_blur(ae, *in_out, *ae->h * *ae->w);
}
