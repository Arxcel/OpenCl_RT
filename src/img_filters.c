/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_filters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:37:03 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/20 20:39:00 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

unsigned char	clamp_rgb(int color)
{
	unsigned char	res;

	if (color > 255)
		res = 255;
	else if (color < 0)
		res = 0;
	else
		res = color;
	return (res);
}

t_rgb			get_color_rgb(int col)
{
	t_color			res;

	res.col = col;
	return (res.argb);
}

static unsigned int	use_filter(t_main *main, size_t x, size_t y)
{
	if (main->after_effect & AE_SEPIA)
		return (set_sepia(main->sdl.img.pixels[y * main->sdl.img.w + x]));
	if (main->after_effect & AE_SMOOTH)
		return (set_smooth(main, x, y, main->sdl.img.pixels));
	return (main->sdl.img.pixels[y * main->sdl.img.w + x]);
}

static void			set_filters(t_main *main, unsigned int *out,
	size_t width, size_t height)
{
	unsigned int	*in;
	t_color			pixel;
	size_t			x;
	size_t			y;

	y = -1;
	in = main->sdl.img.pixels;
	pixel.col = 0;
	while (++y < height && (x = -1))
		while (++x < width)
			out[y * width + x] = use_filter(main, x, y);
	main->sdl.img.pixels = out;
	free(in);
}

void				set_filter(t_main *main)
{
	unsigned int	*out;

	if (main->after_effect > 0)
	{
		out = (unsigned int*)malloc(sizeof(unsigned int) * (main->sdl.img.w * main->sdl.img.h));
		set_filters(main, out, main->sdl.img.w, main->sdl.img.h);
	}
}
