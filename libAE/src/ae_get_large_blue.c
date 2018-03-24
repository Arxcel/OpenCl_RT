/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_get_large_blue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:14:12 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 13:32:50 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static unsigned int		first_b_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 2) * w]).blue * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 2) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 2) * w]).blue * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 2) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 2) * w]).blue * O1);
	return (result.col);
}

static unsigned int		second_b_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 1) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).blue * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).blue * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).blue * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 1) * w]).blue * O2);
	return (result.col);
}

static unsigned int		third_b_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + y * w]).blue * O3);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).blue * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).blue * O6);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).blue * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + y * w]).blue * O3);
	return (result.col);
}

static unsigned int		fourth_b_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y + 1) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).blue * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).blue * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).blue * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 1) * w]).blue * O2);
	return (result.col);
}

unsigned int			get_large_blue(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = first_b_block(x, y, in, w);
	result.col += second_b_block(x, y, in, w);
	result.col += third_b_block(x, y, in, w);
	result.col += fourth_b_block(x, y, in, w);
	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 2) * w]).blue * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 2) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 2) * w]).blue * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 2) * w]).blue * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 2) * w]).blue * O1);
	return (result.col);
}
