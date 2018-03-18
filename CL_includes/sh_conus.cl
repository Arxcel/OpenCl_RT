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

// short				con_cross(t_object con, t_ray *r, float *t)
// {
// 	float		t1;
// 	float		t2;
// 	t_vector	l;
// 	float		p[3];
// 	float		m1;
// 	float		m2;

// 	l = r->orig - con.point;
// 	p[0] = v_dot(r->dir, r->dir) - (1 + con.angle * con.angle) * v_dot(r->dir, con.dir) * v_dot(r->dir, con.dir);
// 	p[0] = v_dot(r->dir, r->dir)
// 	p[1] = 2.0 * (v_dot(r->dir, l) - (1 + con.angle * con.angle) * v_dot(r->dir, con.dir) * v_dot(l, con.dir));
// 	p[2] = v_dot(l, l) - (1 + con.angle * con.angle) * v_dot(l, con.dir) * v_dot(l, con.dir);
// 	if (!solve_quadratic(p, &t2, &t1))
// 		return (0);
// 	if ((t1 < 0 && t2 < 0) || (t1 == t2))
// 		return (0);
// 	if (con.max > 0)
// 	{
// 		if (t1 > 0 && t2 < 0 && m1 > 0 && m1 < con.max)
// 		{
// 			*t = t1;
// 			return (1);
// 		}
// 		else if (t2 > 0 && t1 < 0 && m2 > 0 && m2 < con.max)
// 		{
// 			*t = t2;
// 			return (1);
// 		}
// 		else if (t1 > 0 && t2 > 0)
// 		{
// 			if (m1 > 0 && m1 < con.max)
// 			{
// 				*t = t1;
// 				return (1);
// 			}
// 			else if (m2 > 0 && m2 < con.max)
// 			{
// 				*t = t2;
// 				return (1);
// 			}
// 		}
// 	}
// 	else if (t1 > 0 && t2 > 0)
// 	{
// 		*t = t1 < t2 ? t1 : t2;
// 		return (1);
// 	}
// 	else if (t1 > 0 && t2 < 0)
// 	{
// 		*t = t1;
// 		return (1);
// 	}
// 	else if (t2 > 0 && t1 < 0)
// 	{
// 		*t = t2;
// 		return (1);
// 	}
// 	return (0);
// }
// short				get_con_data(t_ray *ray, t_object con, float t)
// {
// 	float		m;
// 	t_vector	point;

// 	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
// 	ray->n_hit = v_normalize(ray->p_hit - con.point - v_mult_d(con.dir, m * (1 + con.angle * con.angle)));
// 	return (1);
// }
short    con_cross(t_object con, t_ray *r, float *t)
{
 float  t1;
 float  t2;
 t_vector l;
 float  p[3];
 	float		m1;
	float		m2;

 l = r->orig - con.point;
 p[0] = v_dot(r->dir, r->dir) - (1 + con.angle * con.angle) * v_dot(r->dir, con.dir) * v_dot(r->dir, con.dir);
 p[1] = 2.0 * (v_dot(r->dir, l) - (1 + con.angle * con.angle) * v_dot(r->dir, con.dir) * v_dot(l, con.dir));
 p[2] = v_dot(l, l) - (1 + con.angle * con.angle) * v_dot(l, con.dir) * v_dot(l, con.dir);
 if (!solve_quadratic(p, &t1, &t2))
  return (0);
 m1 = v_dot(r->dir, con.dir) * t1 + v_dot(r->orig - con.point, con.dir) * (1 + con.angle * con.angle);
m2 = v_dot(r->dir, con.dir) * t2 + v_dot(r->orig - con.point, con.dir) * (1 + con.angle * con.angle);

if ((t1 < 0 && t2 < 0) || (t1 == t2))
		return (0);
	if (con.max > 0)
	{
		if (t1 > 0 && t2 < 0 && m1 > 0 && m1 < con.max)
		{
			*t = t1;
			return (1);
		}
		else if (t2 > 0 && t1 < 0 && m2 > 0 && m2 < con.max)
		{
			*t = t2;
			return (1);
		}
		else if (t1 > 0 && t2 > 0)
		{
			if (m1 > 0 && m1 < con.max)
			{
				*t = t1;
				return (1);
			}
			else if (m2 > 0 && m2 < con.max)
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

short    get_con_data(t_ray *ray, t_object con, float t)
{
 float m;

 m = v_dot(ray->dir, con.dir) * t + v_dot(ray->orig - con.point, con.dir) * (1 + con.angle * con.angle);
 ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
 ray->n_hit = ray->p_hit - con.point - v_mult_d(con.dir, m);
 ray->n_hit = v_normalize(ray->n_hit);
 return (1);
}