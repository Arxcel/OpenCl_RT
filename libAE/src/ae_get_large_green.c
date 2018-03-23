/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_get_large_green.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:14:26 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 13:37:52 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static unsigned int		first_g_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 2) * w]).green * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 2) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 2) * w]).green * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 2) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 2) * w]).green * O1);
	return (result.col);
}

static unsigned int		second_g_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 1) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).green * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).green * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).green * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 1) * w]).green * O2);
	return (result.col);
}

static unsigned int		third_g_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + y * w]).green * O3);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).green * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).green * O6);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).green * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + y * w]).green * O3);
	return (result.col);
}

static unsigned int		fourth_g_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y + 1) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).green * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).green * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).green * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 1) * w]).green * O2);
	return (result.col);
}

unsigned int			get_large_green(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = first_g_block(x, y, in, w);
	result.col += second_g_block(x, y, in, w);
	result.col += third_g_block(x, y, in, w);
	result.col += fourth_g_block(x, y, in, w);
	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 2) * w]).green * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 2) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 2) * w]).green * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 2) * w]).green * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 2) * w]).green * O1);
	return (result.col);
}
