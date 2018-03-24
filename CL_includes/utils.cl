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

#include "ft_rt.h"

unsigned int		set_rgb(t_vector c)
{
	c = v_mult_d(c, 255.0f);
	c[0] = clamp(c[0], 0.0f, 255.0f);
	c[1] = clamp(c[1], 0.0f, 255.0f);
	c[2] = clamp(c[2], 0.0f, 255.0f);
	return (((int)c[0] << 16) | ((int)c[1] << 8) | (int)c[2]);
}

t_vector			get_rgb(unsigned int c)
{
	t_vector res;

	res[0] = ((c & 0x00ff0000) >> 16);
	res[1] = ((c & 0x0000ff00) >> 8);
	res[2] = ((c & 0x000000ff));
	res = v_mult_d(res, 1.0f / 255.0f);
	return (res);
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

t_matrix33			v_rot2(float angle)
{
	t_matrix33	a;
	float		an;

	an = angle;
	a.r[0] = (t_mrow3){native_cos(an), -native_sin(an), 0};
	a.r[1] = (t_mrow3){native_sin(an), native_cos(an), 0};
	a.r[2] = (t_mrow3){0, 0, 1};
	return (a);
}
