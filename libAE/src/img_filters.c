/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_filters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:37:03 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 19:38:51 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

const t_effects g_func_array[6] = {
	&set_black_white, &set_sepia, &ae_sharpness, &set_blur, &ae_triple_blur,
	&ae_set_median
};

unsigned char			clamp_rgb(int color)
{
	unsigned char	res;

	if (color > 255)
		res = 255;
	else if (color < 0)
		res = 0;
	else
		res = color;
	return (res);
}

t_rgb					get_color_rgb(int col)
{
	t_color			res;

	res.col = col;
	return (res.argb);
}

static unsigned int		*use_filters(t_ae *ae,
	unsigned int **out, char *mutations)
{
	size_t			i;

	i = 0;
	while (mutations[i] >= 0 && i < 15)
	{
		g_func_array[(size_t)mutations[i]](ae, out, 1);
		i++;
	}
	set_contrast(ae, out, 1);
	return (*out);
}

void					set_filter(t_ae *ae)
{
	unsigned int	*out;
	size_t			i;
	size_t			size;

	size = *ae->w * *ae->h;
	if (ae->after_effect)
	{
		i = -1;
		out = (unsigned int*)malloc(sizeof(unsigned int) * size);
		while (++i < size)
			out[i] = (*ae->pixels)[i];
		free(*ae->pixels);
		*ae->pixels = use_filters(ae, &out, ae->effects);
	}
}
