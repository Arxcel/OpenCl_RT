/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_median_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:14:29 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 19:36:12 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

void				sort_colors(unsigned int *cols, int how_much)
{
	int				i;
	int				j;
	unsigned int	tmp;

	i = -1;
	while (++i < how_much)
	{
		j = i;
		while (++j < how_much)
			if (cols[i] > cols[j])
			{
				tmp = cols[i];
				cols[i] = cols[j];
				cols[j] = tmp;
			}
	}
}

static void			first_block(size_t x, size_t y,
	t_ae *ae, unsigned int *out)
{
	out[0] = get_color_rgb((*ae->pixels)[x - 2 + (y - 2) * *ae->w]).red;
	out[1] = get_color_rgb((*ae->pixels)[x - 1 + (y - 2) * *ae->w]).red;
	out[2] = get_color_rgb((*ae->pixels)[x + (y - 2) * *ae->w]).red;
	out[3] = get_color_rgb((*ae->pixels)[x + 1 + (y - 2) * *ae->w]).red;
	out[4] = get_color_rgb((*ae->pixels)[x + 2 + (y - 2) * *ae->w]).red;
	out[5] = get_color_rgb((*ae->pixels)[x - 2 + (y - 1) * *ae->w]).red;
	out[6] = get_color_rgb((*ae->pixels)[x - 1 + (y - 1) * *ae->w]).red;
	out[7] = get_color_rgb((*ae->pixels)[x + (y - 1) * *ae->w]).red;
	out[8] = get_color_rgb((*ae->pixels)[x + 1 + (y - 1) * *ae->w]).red;
	out[9] = get_color_rgb((*ae->pixels)[x + 2 + (y - 1) * *ae->w]).red;
	out[10] = get_color_rgb((*ae->pixels)[x - 2 + y * *ae->w]).red;
	out[11] = get_color_rgb((*ae->pixels)[x - 1 + y * *ae->w]).red;
	out[12] = get_color_rgb((*ae->pixels)[x + y * *ae->w]).red;
	out[13] = get_color_rgb((*ae->pixels)[x + 1 + y * *ae->w]).red;
	out[14] = get_color_rgb((*ae->pixels)[x + 2 + y * *ae->w]).red;
	out[15] = get_color_rgb((*ae->pixels)[x - 2 + (y + 1) * *ae->w]).red;
	out[16] = get_color_rgb((*ae->pixels)[x - 1 + (y + 1) * *ae->w]).red;
	out[17] = get_color_rgb((*ae->pixels)[x + (y + 1) * *ae->w]).red;
	out[18] = get_color_rgb((*ae->pixels)[x + 1 + (y + 1) * *ae->w]).red;
	out[19] = get_color_rgb((*ae->pixels)[x + 2 + (y + 1) * *ae->w]).red;
	out[20] = get_color_rgb((*ae->pixels)[x - 2 + (y + 2) * *ae->w]).red;
	out[21] = get_color_rgb((*ae->pixels)[x - 1 + (y + 2) * *ae->w]).red;
	out[22] = get_color_rgb((*ae->pixels)[x + (y + 2) * *ae->w]).red;
	out[23] = get_color_rgb((*ae->pixels)[x + 1 + (y + 2) * *ae->w]).red;
}

unsigned int		get_median_red(size_t x, size_t y,
	t_ae *ae)
{
	unsigned int	array[25];

	array[24] = get_color_rgb((*ae->pixels)[x + 2 + (y + 2) * *ae->w]).red;
	first_block(x, y, ae, array);
	sort_colors(array, 25);
	return (array[12]);
}
