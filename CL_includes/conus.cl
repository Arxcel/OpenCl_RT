/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:22:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/01 18:22:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void			ft_swap_d(float *d1, float *d2)
{
	float buf;

	buf = *d1;
	*d1 = *d2;
	*d2 = buf;
}

short				con_cross(t_object con, t_vector orig,
							t_vector dir, float *t)
{
	float		k;
	float		t1;
	float		t2;
	t_vector	l;
	float		p[3];

	k = native_tan(ft_deg2rad(con.angle / 2));
	l = orig - con.point;
	p[0] = v_dot(dir, dir) - (1 + k * k) *
							v_dot(dir, con.dir) * v_dot(dir, con.dir);
	p[1] = 2.0 * (v_dot(dir, l) - (1 + k * k) *
							v_dot(dir, con.dir) * v_dot(l, con.dir));
	p[2] = v_dot(l, l) - (1 + k * k) * v_dot(l, con.dir) * v_dot(l, con.dir);
	if (!solve_quadratic(p, &t1, &t2))
		return (0);
	if (t1 > t2)
		ft_swap_d(&t1, &t2);
	if (t1 < 0)
	{
		t1 = t2;
		if (t1 < 0)
			return (0);
	}
	*t = t1;
	return (1);
}

short				get_con_data(t_ray *ray, t_object con, float t)
{
	float m;
	float k;

	k = native_tan(ft_deg2rad(con.angle / 2));
	m = v_dot(ray->dir, con.dir) * t + v_dot(ray->orig - con.point, con.dir);
	m *= (1 + k * k);
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = ray->p_hit - con.point - v_mult_d(con.dir, m);
	ray->n_hit = v_normalize(ray->n_hit);
	return (1);
}
