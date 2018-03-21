/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_filters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:37:03 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 17:06:41 by afarapon         ###   ########.fr       */
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

static unsigned int		*use_filters(t_main *main, unsigned int **out)
{
	if (main->after_effect & AE_SMOOTH)
		set_blur(main, out, 1);
	if (main->after_effect & AE_M_BLUR)
		set_blur(main, out, 10);
	if (main->after_effect & AE_CONTR)
		set_contrast(main, *out);
	if (main->after_effect & AE_SEPIA)
		set_sepia(main, *out);
	if (main->after_effect & AE_TOON)
		ae_test_blur(main, out, 5);
	if (main->after_effect & AE_SHARPNESS)
		ae_sharpness(main, out, 1);
	return (*out);
}

void				set_filter(t_main *main)
{
	unsigned int	*out;
	size_t			i;
	size_t			size;

	size = main->sdl.img.w * main->sdl.img.h;
	if (main->after_effect)
	{
		i = -1;
		out = (unsigned int*)malloc(sizeof(unsigned int) * size);
		while (++i < size)
			out[i] = main->sdl.img.pixels[i];
		free(main->sdl.img.pixels);
		main->sdl.img.pixels = use_filters(main, &out);
	}
}
