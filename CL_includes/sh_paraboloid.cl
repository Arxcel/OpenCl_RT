/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_paraboloid.cl                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:34:34 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/18 16:34:38 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

short				par_cross(t_object sh, t_ray *ray, float *t)
{

	float		t1;
	float		t2;
	t_vector	l;
	float		params[3];
	float		m1;
	float		m2;

	l = ray->orig - sh.point;
	params[0] = v_dot(ray->dir, ray->dir) - v_dot(ray->dir, sh.dir) * v_dot(ray->dir, sh.dir);
	params[1] = 2 * (v_dot(l, ray->dir) - v_dot(ray->dir, sh.dir) * v_dot(l, sh.dir) + 2 * sh.radius);
	params[2] = v_dot(l, l) - v_dot(l, sh.dir) * (v_dot(l, sh.dir) + 4 * sh.radius);
	if (!solve_quadratic(params, &t2, &t1))
		return (0);
	m1 = v_dot(ray->dir, sh.dir) * t1 + v_dot(l, sh.dir);
	m2 = v_dot(ray->dir, sh.dir) * t2 + v_dot(l, sh.dir);
	if ((t1 < 0 && t2 < 0) || (t1 == t2))
		return (0);
	if (sh.max > 0)
	{
		if (t1 > 0 && t2 < 0 && m1 > 0 && m1 < sh.max)
		{
			*t = t1;
			return (1);
		}
		else if (t2 > 0 && t1 < 0 && m2 > 0 && m2 < sh.max)
		{
			*t = t2;
			return (1);
		}
		else if (t1 > 0 && t2 > 0)
		{
			if (m1 > 0 && m1 < sh.max)
			{
				*t = t1;
				return (1);
			}
			else if (m2 > 0 && m2 < sh.max)
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

short				get_par_data(t_ray *ray, t_object sh, float t)
{
	float m;

	m = v_dot(ray->dir, sh.dir) * t + v_dot(ray->orig - sh.point, sh.dir);
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = v_normalize(ray->p_hit - sh.point - v_mult_d(sh.dir, m));
	if (v_dot(ray->n_hit, ray->dir) > 0)
		ray->n_hit = v_mult_d(ray->n_hit, -1.0);
	return (1);
}
