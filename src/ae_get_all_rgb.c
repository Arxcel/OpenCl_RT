/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_get_all_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:27:54 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 17:05:17 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"
#define COEF 2
#define O1 0.0029150 * COEF
#define O2 0.0130642 * COEF
#define O3 0.0215393 * COEF
#define O4 0.0585498 * COEF
#define O5 0.0965324 * COEF
#define O6 0.1591549 * COEF

static unsigned int			get_red(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 2) * w]).red * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 2) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 2) * w]).red * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 2) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 2) * w]).red * O1);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y - 1) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).red * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).red * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).red * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 1) * w]).red * O2);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + y * w]).red * O3);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).red * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).red * O6);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).red * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + y * w]).red * O3);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 1) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).red * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).red * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).red * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 1) * w]).red * O2);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 2) * w]).red * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 2) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 2) * w]).red * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 2) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 2) * w]).red * O1);
	return (result.col);
}

static unsigned int			get_green(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 2) * w]).green * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 2) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 2) * w]).green * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 2) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 2) * w]).green * O1);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y - 1) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).green * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).green * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).green * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 1) * w]).green * O2);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + y * w]).green * O3);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).green * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).green * O6);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).green * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + y * w]).green * O3);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 1) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).green * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).green * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).green * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 1) * w]).green * O2);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 2) * w]).green * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 2) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 2) * w]).green * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 2) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 2) * w]).green * O1);
	return (result.col);
}

static unsigned int			get_blue(size_t x, size_t y, unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 2) * w]).blue * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 2) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 2) * w]).blue * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 2) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 2) * w]).blue * O1);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y - 1) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).blue * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).blue * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).blue * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 1) * w]).blue * O2);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + y * w]).blue * O3);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).blue * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).blue * O6);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).blue * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + y * w]).blue * O3);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 1) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).blue * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).blue * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).blue * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 1) * w]).blue * O2);

	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 2) * w]).blue * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 2) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 2) * w]).blue * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 2) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 2) * w]).blue * O1);
	return (result.col);
}

unsigned int	set_test_blur(t_main *main, unsigned int *in, size_t x, size_t y)
{
	t_color		tmp;
	size_t		w;

	w = main->sdl.img.w;
	tmp.argb.red = clamp_rgb(get_red(x, y, in, main->sdl.img.w));
	tmp.argb.green = clamp_rgb(get_green(x, y, in, main->sdl.img.w));
	tmp.argb.blue = clamp_rgb(get_blue(x, y, in, main->sdl.img.w));
	return (tmp.col);
}