/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_smooth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:12:46 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 16:39:28 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static unsigned int			get_b_red(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color		result;

	result.col = 0;
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).red * 0.5);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).red * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).red * 0.5);

	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).red * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).red);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).red * 0.75);

	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).red * 0.5);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).red * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).red * 0.5);
	return (result.col / 6);
}

static unsigned int			get_b_green(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color		result;

	result.col = 0;
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).green * 0.5);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).green * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).green * 0.5);

	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).green * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).green);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).green * 0.75);

	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).green * 0.5);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).green * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).green * 0.5);
	return (result.col / 6);
}

static unsigned int			get_b_blue(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color		result;

	result.col = 0;
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).blue * 0.5);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).blue * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).blue * 0.5);

	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).blue * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).blue);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).blue * 0.75);

	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).blue * 0.5);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).blue * 0.75);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).blue * 0.5);
	return (result.col / 6);
}

unsigned int			set_smooth(t_main *main, size_t x, size_t y, unsigned int *in)
{
	t_color		tmp;
	size_t		w;

	w = main->sdl.img.w;
	tmp.argb.red = clamp_rgb(get_b_red(x, y, in, main->sdl.img.w));
	tmp.argb.green = clamp_rgb(get_b_green(x, y, in, main->sdl.img.w));
	tmp.argb.blue = clamp_rgb(get_b_blue(x, y, in, main->sdl.img.w));
	return (tmp.col);
}
