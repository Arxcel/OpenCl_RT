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
	float b;
	float t0;

	if (!(a = v_dot(p->dir, r->dir)))
		return (0);
	b = -(v_dot(p->dir, r->orig) + p->p);
	if ((t0 = b / a) > 0.000001)
	{
		*t = t0;
		return (1);
	}
	return (0);
}

short				get_plane_data(t_ray *ray, t_object plane, float t)
{
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = plane.dir;
	ray->n_hit = v_normalize(ray->n_hit);
	return (1);
}
