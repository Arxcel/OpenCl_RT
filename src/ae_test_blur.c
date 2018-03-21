/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_test_blur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:16:18 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 16:22:44 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static unsigned int		*test_blur(t_main *main, unsigned int *in, size_t size)
{
	size_t			x;
	size_t			y;
	unsigned int	*res;

	y = 1;
	res = (unsigned int*)malloc(sizeof(unsigned int) * size);
	ft_bzero(res, sizeof(unsigned int) * size);
	while (++y < (main->sdl.img.h - 2) && (x = 1))
		while (++x < (main->sdl.img.w - 2))
			res[x + y * main->sdl.img.w] = set_test_blur(main, in, x, y);
	free(in);
	return (res);
}

void				ae_test_blur(t_main *main, unsigned int **in_out, size_t count)
{
	size_t			i;

	i = -1;
	while (++i < count)
		*in_out = test_blur(main, *in_out, main->sdl.img.h * main->sdl.img.w);
}
