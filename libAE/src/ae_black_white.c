/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_black_white.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:36:02 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 19:31:25 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static unsigned int		set_bw_pixel(unsigned int in)
{
	t_color			col;
	t_color			res;
	unsigned char	mid;

	col.col = in;
	mid = (col.argb.red + col.argb.green + col.argb.blue) / 3;
	res.argb.red = mid;
	res.argb.green = mid;
	res.argb.blue = mid;
	return (res.col);
}

void					set_black_white(t_ae *ae,
	unsigned int **out, size_t count)
{
	size_t			size;
	size_t			i;

	i = 0;
	(void)count;
	size = *ae->h * *ae->w;
	while (i < size)
	{
		(*out)[i] = set_bw_pixel((*out)[i]);
		i++;
	}
}
