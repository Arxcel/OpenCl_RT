/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:57 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/15 16:47:33 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static short		is_in_zone(t_vector p1, t_object *p)
{
	t_vector	c0;
	t_vector	e0;

	e0 = p->pos2 - p->pos1;
	c0 = p1 - p->pos1;
	if (v_dot(p->dir, v_cross(e0, c0)) < 0)
		return (0);
	e0 = p->pos3 - p->pos2;
	c0 = p1 - p->pos2;
	if (v_dot(p->dir, v_cross(e0, c0)) < 0)
		return (0);
	e0 = p->pos1 - p->pos3;
	c0 = p1 - p->pos3;
	if (v_dot(p->dir, v_cross(e0, c0)) < 0)
		return (0);
	return (1);
}

short				triangle_cross(t_object *p, t_ray *r, float *t)
{
	float		a;
	float		t0;
	t_vector	v;

	a = v_dot(p->dir, r->dir);
	if (a)
	{
		v = p->pos3 - r->orig; 
		t0 = v_dot(v, p->dir) / a;
		if (t0 >= 0)
		{
			if (!is_in_zone(r->orig + v_mult_d(r->dir, t0), p))
				return (0);
			*t = t0;
			return (1);
		}
	}
	return (0);
}

short				get_triangle_data(t_ray *ray, t_object triangle, float t)
{
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = triangle.dir;
	if (!ray->n_hit[0] && !ray->n_hit[1])
	{
		ray->tex[0] = ray->p_hit[0];
		ray->tex[1] = ray->p_hit[1];
	}
	else
	{
		ray->tex[0] = ray->p_hit[0];
		ray->tex[1] = ray->p_hit[2];
	}
	return (1);
}
