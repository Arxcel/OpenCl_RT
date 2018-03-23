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

#include "ft_rt.h"

short			con_cross(t_object con, t_ray *r, float *t)
{
	float		t1;
	float		t2;
	t_vector	x;
	float		p[3];
	float		m1;
	float		m2;

	x = r->orig - con.pos1;
	p[0] = v_dot(r->dir, r->dir) - (1 + con.angle * con.angle) * v_dot(r->dir, con.dir) * v_dot(r->dir, con.dir);
	p[1] = 2 * (v_dot(r->dir, x) - (1 + con.angle * con.angle) * v_dot(r->dir, con.dir) * v_dot(x, con.dir));
	p[2] = v_dot(x, x) - (1 + con.angle * con.angle) * v_dot(x, con.dir) * v_dot(x, con.dir);
	if (!solve_quadratic(p, &t2, &t1))
		return (0);
	m1 = v_dot(r->dir, con.dir) * t1 + v_dot(r->orig - con.pos1, con.dir);
	m2 = v_dot(r->dir, con.dir) * t2 + v_dot(r->orig - con.pos1, con.dir);
	if ((t1 < 0 && t2 < 0) || (t1 == t2))
		return (0);
	if (con.max > 0 || con.min < 0)
	{
		if (t1 > 0 && t2 < 0 && m1 >= con.min && m1 <= con.max)
		{
			*t = t1;
			return (1);
		}
		else if (t2 > 0 && t1 < 0 && m2 >= con.min && m2 <= con.max)
		{
			*t = t2;
			return (1);
		}
		else if (t1 > 0 && t2 > 0)
		{
			if (m1 >= con.min && m1 <= con.max)
			{
				*t = t1;
				return (1);
			}
			else if (m2 >= con.min && m2 <= con.max)
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

short		get_con_data(t_ray *ray, t_object con, float t)
{
	float		m;
	t_vector	x;

	x = ray->orig - con.pos1;
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	m = v_dot(ray->dir, con.dir) * t + v_dot(x, con.dir);
	ray->n_hit = v_normalize(ray->p_hit - con.pos1 - v_mult_d(v_mult_d(con.dir, m), (1 + con.angle * con.angle)));
	if (!con.dir[0] && !con.dir[1])
	{
		ray->tex[0] = (1 + atan2(ray->n_hit[1], ray->n_hit[0]) / M_PI) * 0.5;
		ray->tex[1] = ray->p_hit[2];
	}
	else if (!con.dir[0] && !con.dir[2])
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
