/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:56:41 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/23 19:34:28 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

t_vector			get_color_percent(t_vector c)
{
	t_vector col;

	col = v_div_d(c, 255);
	return (col);
}

unsigned int		set_rgb(t_vector c)
{
	c = v_mult_d(c, 255);
	if (c[0] > 255)
		c[0] = 255;
	if (c[1] > 255)
		c[1] = 255;
	if (c[2] > 255)
		c[2] = 255;
	if (c[0] < 0)
		c[0] = 0;
	if (c[1] < 0)
		c[1] = 0;
	if (c[2] < 0)
		c[2] = 0;
	return (((int)c[0] << 16) | ((int)c[1] << 8) | (int)c[2]);
}

float				ft_deg2rad(float deg)
{
	return (deg * 3.14 / 180);
}

short				solve_quadratic(const float *p, float *x0, float *x1)
{
	float d;
	float q;

	d = p[1] * p[1] - 4 * p[0] * p[2];
	if (d < 0)
		return (0);
	else if (d == 0)
	{
		*x0 = -0.5 * p[1] / p[0];
		*x1 = -0.5 * p[1] / p[0];
	}
	else
	{
		q = (p[1] > 0) ? -0.5 * (p[1] + sqrt(d)) : -0.5 * (p[1] - sqrt(d));
		*x0 = q / p[0];
		*x1 = p[2] / q;
	}
	return (1);
}
