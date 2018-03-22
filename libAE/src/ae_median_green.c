/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_median_green.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:14:49 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 19:34:56 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static void			first_block(size_t x, size_t y,
	t_ae *ae, unsigned int *out)
{
	out[0] = get_color_rgb((*ae->pixels)[x - 2 + (y - 2) * *ae->w]).green;
	out[1] = get_color_rgb((*ae->pixels)[x - 1 + (y - 2) * *ae->w]).green;
	out[2] = get_color_rgb((*ae->pixels)[x + (y - 2) * *ae->w]).green;
	out[3] = get_color_rgb((*ae->pixels)[x + 1 + (y - 2) * *ae->w]).green;
	out[4] = get_color_rgb((*ae->pixels)[x + 2 + (y - 2) * *ae->w]).green;
	out[5] = get_color_rgb((*ae->pixels)[x - 2 + (y - 1) * *ae->w]).green;
	out[6] = get_color_rgb((*ae->pixels)[x - 1 + (y - 1) * *ae->w]).green;
	out[7] = get_color_rgb((*ae->pixels)[x + (y - 1) * *ae->w]).green;
	out[8] = get_color_rgb((*ae->pixels)[x + 1 + (y - 1) * *ae->w]).green;
	out[9] = get_color_rgb((*ae->pixels)[x + 2 + (y - 1) * *ae->w]).green;
	out[10] = get_color_rgb((*ae->pixels)[x - 2 + y * *ae->w]).green;
	out[11] = get_color_rgb((*ae->pixels)[x - 1 + y * *ae->w]).green;
	out[12] = get_color_rgb((*ae->pixels)[x + y * *ae->w]).green;
	out[13] = get_color_rgb((*ae->pixels)[x + 1 + y * *ae->w]).green;
	out[14] = get_color_rgb((*ae->pixels)[x + 2 + y * *ae->w]).green;
	out[15] = get_color_rgb((*ae->pixels)[x - 2 + (y + 1) * *ae->w]).green;
	out[16] = get_color_rgb((*ae->pixels)[x - 1 + (y + 1) * *ae->w]).green;
	out[17] = get_color_rgb((*ae->pixels)[x + (y + 1) * *ae->w]).green;
	out[18] = get_color_rgb((*ae->pixels)[x + 1 + (y + 1) * *ae->w]).green;
	out[19] = get_color_rgb((*ae->pixels)[x + 2 + (y + 1) * *ae->w]).green;
	out[20] = get_color_rgb((*ae->pixels)[x - 2 + (y + 2) * *ae->w]).green;
	out[21] = get_color_rgb((*ae->pixels)[x - 1 + (y + 2) * *ae->w]).green;
	out[22] = get_color_rgb((*ae->pixels)[x + (y + 2) * *ae->w]).green;
	out[23] = get_color_rgb((*ae->pixels)[x + 1 + (y + 2) * *ae->w]).green;
}

unsigned int		get_median_green(size_t x, size_t y,
	t_ae *ae)
{
	unsigned int	array[25];

	array[24] = get_color_rgb((*ae->pixels)[x + 2 + (y + 2) * *ae->w]).green;
	first_block(x, y, ae, array);
	sort_colors(array, 25);
	return (array[12]);
}
