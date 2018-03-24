/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:16:38 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 15:05:30 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

static int		get_average(size_t i, size_t size, unsigned int *out)
{
	int		lab;

	lab = 0;
	while (i < size)
	{
		lab = (int)(get_color_rgb(out[i]).red * 0.299 +
			get_color_rgb(out[i]).green * 0.587 +
			get_color_rgb(out[i]).blue * 0.114);
		i++;
	}
	lab /= size;
	return (lab);
}

static void		set_final_contrast(unsigned int *out,
	size_t size, int scale[FILTER_SIZE])
{
	size_t			i;
	t_color			tmp_col;

	tmp_col.col = 0;
	i = 0;
	while (i < size)
	{
		tmp_col.col = out[i];
		tmp_col.argb.red = scale[tmp_col.argb.red];
		tmp_col.argb.green = scale[tmp_col.argb.green];
		tmp_col.argb.blue = scale[tmp_col.argb.blue];
		out[i] = tmp_col.col;
		i++;
	}
}

void			set_contrast(t_ae *ae, unsigned int **out, size_t count)
{
	int				scale[FILTER_SIZE];
	size_t			size;
	int				lab;
	double			korr;
	size_t			z;

	z = -1;
	(void)count;
	size = *ae->w * *ae->h;
	lab = get_average(0, size, *out);
	korr = 1.0 + ae->coeficient / 100.0;
	while (++z < FILTER_SIZE)
		scale[z] = clamp_rgb((int)(lab + korr * ((int)z - lab)));
	set_final_contrast(*out, size, scale);
}
