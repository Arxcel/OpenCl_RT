/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:20:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/01 15:20:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

short				cyl_cross(t_object cyl, t_ray *r, float *t)
{
	float		t1;
	float		t2;
	t_vector	l;
	float		params[3];

	l = r->orig - cyl.point;
	params[0] = v_dot(r->dir, r->dir) - v_dot(r->dir, cyl.dir) * v_dot(r->dir, cyl.dir);
	params[1] = 2.0 * (v_dot(r->dir, l) - v_dot(r->dir, cyl.dir) * v_dot(l, cyl.dir));
	params[2] = v_dot(l, l) - cyl.radius2 - v_dot(l, cyl.dir) * v_dot(l, cyl.dir);
	if (!solve_quadratic(params, &t1, &t2))
		return (0);
	if (t1 < 0 && t2 < 0)
		return (0);
	else if (t1 > 0 && t2 < 0)
		*t = t1;
	else if (t1 < 0 && t2 > 0)
		*t = t2;
	else if (t1 > 0 && t2 > 0)
		*t = t1 < t2 ? t1 : t2;
	return (1);
}

short				get_cyl_data(t_ray *ray, t_object cyl, float t)
{
	float m;

	m = v_dot(ray->dir, cyl.dir) * t + v_dot(ray->orig - cyl.point, cyl.dir);
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = ray->p_hit - cyl.point - v_mult_d(cyl.dir, m);
	ray->n_hit = v_normalize(ray->n_hit);
	return (1);
}
