/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_smooth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:12:46 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 10:03:45 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static unsigned int		multiple_rgb(unsigned int col, float coef)
{
	t_color		tmp;

	tmp.col = col;
	tmp.argb.red = (unsigned char)(tmp.argb.red * coef);
	tmp.argb.green = (unsigned char)(tmp.argb.green * coef);
	tmp.argb.blue = (unsigned char)(tmp.argb.blue * coef);
	return (tmp.col);
}

unsigned int			rgb_mult(unsigned int col, float coef)
{
	t_color			tmp;

	tmp.col = col;
	tmp.argb.red = tmp.argb.red * coef;
	tmp.argb.green = tmp.argb.green * coef;
	tmp.argb.blue = tmp.argb.blue * coef;
	return (tmp.col);
}

static void				smoth_matrix(unsigned int **m)
{
	m[0][0] = rgb_mult(m[0][0], 0.5);
	m[0][1] = rgb_mult(m[0][1], 0.75);
	m[0][2] = rgb_mult(m[0][2], 0.5);
	m[1][0] = rgb_mult(m[1][0], 0.75);
	m[1][2] = rgb_mult(m[1][2], 0.75);
	m[2][0] = rgb_mult(m[2][0], 0.5);
	m[2][1] = rgb_mult(m[2][1], 0.75);
	m[2][2] = rgb_mult(m[2][2], 0.5);
}

unsigned int			set_smooth(t_main *main, size_t x, size_t y, unsigned int *in)
{
	unsigned int		**m;

	m = get_matrix(main, x, y, in);
	smoth_matrix(m);
	return (ae_calc_matrix(m, 6));
}