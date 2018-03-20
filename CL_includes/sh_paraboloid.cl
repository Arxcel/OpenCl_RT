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
	t_vector	x;
	float		params[3];
	float		m1;
	float		m2;

	x = ray->orig - sh.pos1;
	params[0] = v_dot(ray->dir, ray->dir) - v_dot(ray->dir, sh.dir) * v_dot(ray->dir, sh.dir);

	params[1] = 2 * (v_dot(x, ray->dir) - v_dot(ray->dir, sh.dir) * (v_dot(x, sh.dir) + 2 * sh.radius));
	params[2] = v_dot(x, x) - v_dot(x, sh.dir) * (v_dot(x, sh.dir) + 4 * sh.radius);
	if (!solve_quadratic(params, &t2, &t1))
		return (0);
	m1 = v_dot(ray->dir, sh.dir) * t1 + v_dot(x, sh.dir);
	m2 = v_dot(ray->dir, sh.dir) * t2 + v_dot(x, sh.dir);
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

	m = v_dot(ray->dir, sh.dir) * t + v_dot(ray->orig - sh.pos1, sh.dir);
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = v_normalize(ray->p_hit - sh.pos1 - v_mult_d(sh.dir, m + sh.radius));
	return (1);
}
