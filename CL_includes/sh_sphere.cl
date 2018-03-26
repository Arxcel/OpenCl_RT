/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:42:03 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/23 20:42:16 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.cl"

short				sphere_cross(t_object sphere, t_ray *r, float *t)
{
	float		t1;
	float		t2;
	t_vector	l;
	float		params[3];

	l = r->orig - sphere.pos1;
	if (v_length(l) == sphere.radius)
		return (0);
	params[0] = v_dot(r->dir, r->dir);
	params[1] = 2.0 * v_dot(r->dir, l);
	params[2] = v_dot(l, l) - sphere.radius * sphere.radius;
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

short				get_sphere_data(t_ray *ray, t_object sphere, float t)
{
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = v_normalize(ray->p_hit - sphere.pos1);
	ray->tex[0] = (1 + atan2(ray->n_hit[2], ray->n_hit[0]) / M_PI) * 0.5;
	ray->tex[1] = acos(ray->n_hit[1]) / M_PI;
	return (1);
}
