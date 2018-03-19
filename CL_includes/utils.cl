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

float				ft_deg2rad(float deg)
{
	return (deg * 3.14 / 180);
}

t_vector			set_sepia(t_vector in)
{
	t_vector		res;
	res[0] = (in[0] * 0.393) + (in[1] * 0.769) + (in[2] * 0.189);
	res[1] = (in[0] * 0.349) + (in[1] * 0.686) + (in[2] * 0.168);
	res[2] = (in[0] * 0.272) + (in[1] * 0.534) + (in[2] * 0.131);
	return (res);
}

unsigned int		set_rgb(t_vector c)
{
	c = v_mult_d(c, 255);
	// c = set_sepia(c);
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

short				solve_quadratic(const float *p, float *x0, float *x1)
{
	float d;

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
		*x0 = -0.5 * (p[1] - native_sqrt(d)) / p[0];
		*x1 = -0.5 * (p[1] + native_sqrt(d)) / p[0];
	}
	return (1);
}
