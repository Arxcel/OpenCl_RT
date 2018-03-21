/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_sharpness.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:43:08 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 16:48:26 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static unsigned int		*make_sharpness(t_main *main, unsigned int *in, size_t size)
{
	size_t			x;
	size_t			y;
	unsigned int	*res;

	y = 0;
	res = (unsigned int*)malloc(sizeof(unsigned int) * size);
	ft_bzero(res, sizeof(unsigned int) * size);
	while (++y < (main->sdl.img.h - 1) && !(x = 0))
		while (++x < (main->sdl.img.w - 1))
			res[x + y * main->sdl.img.w] = set_sharpness(main, x, y, in);
	free(in);
	return (res);
}

void				ae_sharpness(t_main *main, unsigned int **in_out, size_t count)
{
	size_t			i;

	i = -1;
	while (++i < count)
		*in_out = make_sharpness(main, *in_out, main->sdl.img.h * main->sdl.img.w);
}
