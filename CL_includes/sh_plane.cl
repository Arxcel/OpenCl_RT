/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:57:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/09 11:57:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

short				plane_cross(t_object *p, t_ray *r, float *t)
{
	float a;
	float t0;
	t_vector v;

	a = v_dot(p->dir, r->dir);
	if (a)
	{
		v = p->pos1 - r->orig; 
		t0 = v_dot(v, p->dir) / a;
		if (t0 > 0e-6)
		{
			*t = t0;
			return (1); 
		}
	}
	return (0);
}

short				get_plane_data(t_ray *ray, t_object plane, float t)
{
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = plane.dir;
	ray->tex[0] = ray->p_hit[0];
	ray->tex[1] = ray->p_hit[2];
	return (1);
}
