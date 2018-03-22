/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_get_large_red.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:14:30 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 18:41:37 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static unsigned int		first_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 2) * w]).red * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 2) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 2) * w]).red * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 2) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 2) * w]).red * O1);
	return (result.col);
}

static unsigned int		second_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y - 1) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y - 1) * w]).red * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y - 1) * w]).red * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y - 1) * w]).red * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y - 1) * w]).red * O2);
	return (result.col);
}

static unsigned int		third_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + y * w]).red * O3);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + y * w]).red * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + y * w]).red * O6);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + y * w]).red * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + y * w]).red * O3);
	return (result.col);
}

static unsigned int		fourth_block(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = clamp_rgb(get_color_rgb(in[x - 2 + (y + 1) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 1) * w]).red * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 1) * w]).red * O5);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 1) * w]).red * O4);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 1) * w]).red * O2);
	return (result.col);
}

unsigned int			get_large_red(size_t x, size_t y,
	unsigned int *in, size_t w)
{
	t_color			result;

	result.col = first_block(x, y, in, w);
	result.col += second_block(x, y, in, w);
	result.col += third_block(x, y, in, w);
	result.col += fourth_block(x, y, in, w);
	result.col += clamp_rgb(get_color_rgb(in[x - 2 + (y + 2) * w]).red * O1);
	result.col += clamp_rgb(get_color_rgb(in[x - 1 + (y + 2) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + (y + 2) * w]).red * O3);
	result.col += clamp_rgb(get_color_rgb(in[x + 1 + (y + 2) * w]).red * O2);
	result.col += clamp_rgb(get_color_rgb(in[x + 2 + (y + 2) * w]).red * O1);
	return (result.col);
}
