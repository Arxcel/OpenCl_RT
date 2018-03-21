/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_blur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:22:45 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 16:22:34 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static unsigned int			*one_time_blur(t_main *main, unsigned int *in, size_t size)
{
	size_t			x;
	size_t			y;
	unsigned int	*res;

	y = 0;
	res = (unsigned int*)malloc(sizeof(unsigned int) * size);
	main->sdl.img.pixels = in;
	while (++y < (main->sdl.img.h - 1) && !(x = 0))
		while (++x < (main->sdl.img.w - 1))
			res[x + y * main->sdl.img.w] = set_smooth(main, x, y, in);
	free(in);
	return (res);
}

void				set_blur(t_main *main, unsigned int **in_out, size_t count)
{
	size_t			i;

	i = -1;
	while (++i < count)
		*in_out = one_time_blur(main, *in_out, main->sdl.img.h * main->sdl.img.w);
}
