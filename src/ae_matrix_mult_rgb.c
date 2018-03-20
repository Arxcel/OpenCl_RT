/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_matrix_mult_rgb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:22:28 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/20 20:33:56 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static unsigned char		matrix_get_red(unsigned int **m,
		unsigned int coef)
{
	unsigned int	res;

	res = (get_color_rgb(m[0][0]).red + get_color_rgb(m[0][1]).red + get_color_rgb(m[0][2]).red +
	get_color_rgb(m[1][0]).red + get_color_rgb(m[1][1]).red + get_color_rgb(m[1][2]).red +
	get_color_rgb(m[2][0]).red + get_color_rgb(m[2][1]).red + get_color_rgb(m[2][2]).red) / coef;
	return (clamp_rgb(res));
}

static unsigned char		matrix_get_green(unsigned int **m,
		unsigned int coef)
{
	unsigned int	res;

	res = (get_color_rgb(m[0][0]).green + get_color_rgb(m[0][1]).green +
	get_color_rgb(m[0][2]).green + get_color_rgb(m[1][0]).green +
	get_color_rgb(m[1][1]).green + get_color_rgb(m[1][2]).green +
	get_color_rgb(m[2][0]).green + get_color_rgb(m[2][1]).green +
	get_color_rgb(m[2][2]).green) / coef;
	return (clamp_rgb(res));
}
static unsigned char		matrix_get_blue(unsigned int **m,
		unsigned int coef)
{
	unsigned int	res;

	res = (get_color_rgb(m[0][0]).blue + get_color_rgb(m[0][1]).blue +
	get_color_rgb(m[0][2]).blue + get_color_rgb(m[1][0]).blue +
	get_color_rgb(m[1][1]).blue + get_color_rgb(m[1][2]).blue +
	get_color_rgb(m[2][0]).blue + get_color_rgb(m[2][1]).blue +
	get_color_rgb(m[2][2]).blue) / coef;
	return (clamp_rgb(res));
}

unsigned int			ae_calc_matrix(unsigned int **m,
		unsigned int coef)
{
	t_color			res;

	res.col = 0;
	res.argb.red = matrix_get_red(m, coef);
	res.argb.green = matrix_get_green(m, coef);
	res.argb.blue = matrix_get_blue(m, coef);
	free_matrix(m);
	return (res.col);
}
