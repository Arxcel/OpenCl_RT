/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:20:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/17 18:38:53 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

short				cyl_cross(t_object cyl, t_ray *r, float *t)
{

	float		t1;
	float		t2;
	t_vector	l;
	float		params[3];
	float		m1;
	float		m2;

	l = r->orig - cyl.pos1;
	params[0] = v_dot(r->dir, r->dir) - v_dot(r->dir, cyl.dir) * v_dot(r->dir, cyl.dir);
	params[1] = 2.0 * (v_dot(r->dir, l) - v_dot(r->dir, cyl.dir) * v_dot(l, cyl.dir));
	params[2] = v_dot(l, l) - cyl.radius * cyl.radius - v_dot(l, cyl.dir) * v_dot(l, cyl.dir);
	if (!solve_quadratic(params, &t2, &t1))
		return (0);
	m1 = v_dot(r->dir, cyl.dir) * t1 + v_dot(l, cyl.dir);
	m2 = v_dot(r->dir, cyl.dir) * t2 + v_dot(l, cyl.dir);
	if ((t1 < 0 && t2 < 0) || (t1 == t2))
		return (0);
	if (cyl.max > 0)
	{
		if (t1 > 0 && t2 < 0 && m1 > 0 && m1 < cyl.max)
		{
			*t = t1;
			return (1);
		}
		else if (t2 > 0 && t1 < 0 && m2 > 0 && m2 < cyl.max)
		{
			*t = t2;
			return (1);
		}
		else if (t1 > 0 && t2 > 0)
		{
			if (m1 > 0 && m1 < cyl.max)
			{
				*t = t1;
				return (1);
			}
			else if (m2 > 0 && m2 < cyl.max)
			{
				*t = t2;
				return (1);
			}
		}
	}
	else if (t1 > 0 && t2 > 0)
	{
		*t = t1 < t2 ? t1 : t2;
		return (1);
	}
	else if (t1 > 0 && t2 < 0)
	{
		*t = t1;
		return (1);
	}
	else if (t2 > 0 && t1 < 0)
	{
		*t = t2;
		return (1);
	}
	return (0);
}

short				get_cyl_data(t_ray *ray, t_object cyl, float t)
{
	float m;

	m = v_dot(ray->dir, cyl.dir) * t + v_dot(ray->orig - cyl.pos1, cyl.dir);
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = v_normalize(ray->p_hit - cyl.pos1 - v_mult_d(cyl.dir, m));
	if (!cyl.dir[0] && !cyl.dir[1])
	{
		ray->tex[0] = (1 + atan2(ray->n_hit[1], ray->n_hit[0]) / M_PI) * 0.5;
		ray->tex[1] = ray->p_hit[2];
	}
	else if (!cyl.dir[0] && !cyl.dir[2])
	{
		ray->tex[0] = (1 + atan2(ray->n_hit[2], ray->n_hit[0]) / M_PI) * 0.5;
		ray->tex[1] = ray->p_hit[1];
	}
	else
	{
		ray->tex[0] = (1 + atan2(ray->n_hit[1], ray->n_hit[0]) / M_PI) * 0.5;
		ray->tex[1] = ray->p_hit[2];
	}
	return (1);
}
