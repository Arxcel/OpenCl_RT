/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:57:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/09 11:57:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

short				disk_cross(t_object *d, t_ray *r, float *t)
{
	float a;
	float t0;
	t_vector v;

	a = v_dot(d->dir, r->dir);
	if (a > 0)
	{
        v = d->point - r->orig; 
        t0 = v_dot(v, d->dir) / a;
		if (t0 >= 0)
		{
			r->p_hit = r->orig + v_mult_d(r->dir, t0);
			v = r->p_hit - d->point;
			if (d->radius * d->radius >= v_dot(v, v))
			{
				*t = t0;
				return (1);
			}
		}
    }
	return (0);
}

short				get_disk_data(t_ray *ray, t_object disk, float t)
{
	ray->n_hit = disk.dir;
	ray->n_hit = v_normalize(ray->n_hit);
	return (1);
}