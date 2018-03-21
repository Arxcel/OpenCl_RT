/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_set_sharpness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:40:18 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 17:02:22 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"


static unsigned int			get_c_red(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color		result;

	result.col = 0;
	result.col += (get_color_rgb(in[x - 1 + (y - 1) * w]).red * -1.0);
	result.col += (get_color_rgb(in[x + (y - 1) * w]).red * -1.0);
	result.col += (get_color_rgb(in[x + 1 + (y - 1) * w]).red * -1.0);

	result.col += (get_color_rgb(in[x - 1 + y * w]).red * -1.0);
	result.col += (get_color_rgb(in[x + y * w]).red * 10);
	result.col += (get_color_rgb(in[x + 1 + y * w]).red * -1.0);

	result.col += (get_color_rgb(in[x - 1 + (y + 1) * w]).red * -1.0);
	result.col += (get_color_rgb(in[x + (y + 1) * w]).red * -1.0);
	result.col += (get_color_rgb(in[x + 1 + (y + 1) * w]).red * -1.0);
	return (result.col);
}

static unsigned int			get_c_green(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color		result;

	result.col = 0;
	result.col += (get_color_rgb(in[x - 1 + (y - 1) * w]).green * -1.0);
	result.col += (get_color_rgb(in[x + (y - 1) * w]).green * -1.0);
	result.col += (get_color_rgb(in[x + 1 + (y - 1) * w]).green * -1.0);

	result.col += (get_color_rgb(in[x - 1 + y * w]).green * -1.0);
	result.col += (get_color_rgb(in[x + y * w]).green * 10);
	result.col += (get_color_rgb(in[x + 1 + y * w]).green * -1.0);

	result.col += (get_color_rgb(in[x - 1 + (y + 1) * w]).green * -1.0);
	result.col += (get_color_rgb(in[x + (y + 1) * w]).green * -1.0);
	result.col += (get_color_rgb(in[x + 1 + (y + 1) * w]).green * -1.0);
	return (result.col);
}

static unsigned int			get_c_blue(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color		result;

	result.col = 0;
	result.col += (get_color_rgb(in[x - 1 + (y - 1) * w]).blue * -1.0);
	result.col += (get_color_rgb(in[x + (y - 1) * w]).blue * -1.0);
	result.col += (get_color_rgb(in[x + 1 + (y - 1) * w]).blue * -1.0);

	result.col += (get_color_rgb(in[x - 1 + y * w]).blue * -1.0);
	result.col += (get_color_rgb(in[x + y * w]).blue * 10);
	result.col += (get_color_rgb(in[x + 1 + y * w]).blue * -1.0);

	result.col += (get_color_rgb(in[x - 1 + (y + 1) * w]).blue * -1.0);
	result.col += (get_color_rgb(in[x + (y + 1) * w]).blue * -1.0);
	result.col += (get_color_rgb(in[x + 1 + (y + 1) * w]).blue * -1.0);
	return (result.col);
}

unsigned int				set_sharpness(t_main *main, size_t x, size_t y, unsigned int *in)
{
	t_color		tmp;
	size_t		w;

	w = main->sdl.img.w;
	tmp.argb.red = clamp_rgb(get_c_red(x, y, in, main->sdl.img.w));
	tmp.argb.green = clamp_rgb(get_c_green(x, y, in, main->sdl.img.w));
	tmp.argb.blue = clamp_rgb(get_c_blue(x, y, in, main->sdl.img.w));
	return (tmp.col);
}

