/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_median_blue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:15:00 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 19:34:48 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static void			first_block(size_t x, size_t y,
	t_ae *ae, unsigned int *out)
{
	out[0] = get_color_rgb((*ae->pixels)[x - 2 + (y - 2) * *ae->w]).blue;
	out[1] = get_color_rgb((*ae->pixels)[x - 1 + (y - 2) * *ae->w]).blue;
	out[2] = get_color_rgb((*ae->pixels)[x + (y - 2) * *ae->w]).blue;
	out[3] = get_color_rgb((*ae->pixels)[x + 1 + (y - 2) * *ae->w]).blue;
	out[4] = get_color_rgb((*ae->pixels)[x + 2 + (y - 2) * *ae->w]).blue;
	out[5] = get_color_rgb((*ae->pixels)[x - 2 + (y - 1) * *ae->w]).blue;
	out[6] = get_color_rgb((*ae->pixels)[x - 1 + (y - 1) * *ae->w]).blue;
	out[7] = get_color_rgb((*ae->pixels)[x + (y - 1) * *ae->w]).blue;
	out[8] = get_color_rgb((*ae->pixels)[x + 1 + (y - 1) * *ae->w]).blue;
	out[9] = get_color_rgb((*ae->pixels)[x + 2 + (y - 1) * *ae->w]).blue;
	out[10] = get_color_rgb((*ae->pixels)[x - 2 + y * *ae->w]).blue;
	out[11] = get_color_rgb((*ae->pixels)[x - 1 + y * *ae->w]).blue;
	out[12] = get_color_rgb((*ae->pixels)[x + y * *ae->w]).blue;
	out[13] = get_color_rgb((*ae->pixels)[x + 1 + y * *ae->w]).blue;
	out[14] = get_color_rgb((*ae->pixels)[x + 2 + y * *ae->w]).blue;
	out[15] = get_color_rgb((*ae->pixels)[x - 2 + (y + 1) * *ae->w]).blue;
	out[16] = get_color_rgb((*ae->pixels)[x - 1 + (y + 1) * *ae->w]).blue;
	out[17] = get_color_rgb((*ae->pixels)[x + (y + 1) * *ae->w]).blue;
	out[18] = get_color_rgb((*ae->pixels)[x + 1 + (y + 1) * *ae->w]).blue;
	out[19] = get_color_rgb((*ae->pixels)[x + 2 + (y + 1) * *ae->w]).blue;
	out[20] = get_color_rgb((*ae->pixels)[x - 2 + (y + 2) * *ae->w]).blue;
	out[21] = get_color_rgb((*ae->pixels)[x - 1 + (y + 2) * *ae->w]).blue;
	out[22] = get_color_rgb((*ae->pixels)[x + (y + 2) * *ae->w]).blue;
	out[23] = get_color_rgb((*ae->pixels)[x + 1 + (y + 2) * *ae->w]).blue;
}

unsigned int		get_median_blue(size_t x, size_t y,
	t_ae *ae)
{
	unsigned int	array[25];

	array[24] = get_color_rgb((*ae->pixels)[x + 2 + (y + 2) * *ae->w]).blue;
	first_block(x, y, ae, array);
	sort_colors(array, 25);
	return (array[12]);
}
