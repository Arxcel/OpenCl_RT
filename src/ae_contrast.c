/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:16:38 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 12:57:01 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"
# define FILTER_SIZE 256

static int		get_average(size_t i, size_t size, unsigned int *out)
{
	int		lab;

	lab = 0;
	while (i < size)
	{
		lab = (int)(get_color_rgb(out[i]).red * 0.299 + get_color_rgb(out[i]).green * 0.587 + get_color_rgb(out[i]).blue * 0.114);
		i++;
	}
	lab /= size;
	return (lab);
}

void			set_contrast(t_main *main, unsigned int *out)
{
	int				scale[FILTER_SIZE];
	size_t			i;
	size_t			size;
	int				lab;
	double			korr;
	t_color			tmp_col;
	unsigned char	value;
	int				delta;
	int				temp;

	size = main->sdl.img.w * main->sdl.img.h;
	lab = get_average(0, size, out);
	korr = 1.0 + main->coeficient / 100.0;
	for (int z = 0; z < FILTER_SIZE; z++)
	{
		delta = (int)z - lab;
		temp  = (int)(lab + korr * delta);

		scale[z] = clamp_rgb(temp);
	}
	for (int i = 0; i < size; i++)
	{
		tmp_col.col = out[i];
		tmp_col.argb.red = scale[tmp_col.argb.red];
		tmp_col.argb.green = scale[tmp_col.argb.green];
		tmp_col.argb.blue = scale[tmp_col.argb.blue];
		out[i] = tmp_col.col;
	}
}