/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:08:22 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/23 20:00:42 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

t_vector		v_mult_d(t_vector v, float d)
{
	v[0] *= d;
	v[1] *= d;
	v[2] *= d;
	return (v);
}

t_vector		v_div_d(t_vector v, float d)
{
	v[0] /= d;
	v[1] /= d;
	v[2] /= d;
	return (v);
}

float			v_length(t_vector v)
{
	float norm;
	float sqrt_calculated;
	float length;

	norm = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	sqrt_calculated = sqrt(norm);
	length = sqrt_calculated < 0 ? -sqrt_calculated : sqrt_calculated;
	return (length);
}

t_vector		v_normalize(t_vector v)
{
	float		norm;
	t_vector	res;

	norm = v_length(v);
	res = v_div_d(v, norm);
	return (res);
}

float			v_dot(t_vector v1, t_vector v2)
{
	float	res;

	res = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
	return (res);
}

t_vector	v_cross(t_vector a, t_vector b)
{
	t_vector c;

	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
	return (c);
}

t_vector2		v_mult_d2(t_vector2 v, float d)
{
	v[0] *= d;
	v[1] *= d;
	return (v);
}

t_vector2		v_div_d2(t_vector2 v, float d)
{
	v[0] /= d;
	v[1] /= d;
	return (v);
}

float			v_length2(t_vector2 v)
{
	float norm;
	float sqrt_calculated;
	float length;

	norm = v[0] * v[0] + v[1] * v[1];
	sqrt_calculated = native_sqrt(norm);
	length = sqrt_calculated < 0 ? -sqrt_calculated : sqrt_calculated;
	return (length);
}

t_vector2		v_normalize2(t_vector2 v)
{
	float		norm;
	t_vector2	res;

	norm = v_length2(v);
	res = v_div_d2(v, norm);
	return (res);
}

float			v_dot2(t_vector2 v1, t_vector2 v2)
{
	float	res;

	res = v1[0] * v2[0] + v1[1] * v2[1];
	return (res);
}