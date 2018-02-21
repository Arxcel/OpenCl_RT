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

#include "ft_rtv1.h"

short				sphere_cross(t_object sphere, t_vector orig,
								t_vector dir, float *t)
{
	float		t1;
	float		t2;
	t_vector	l;
	float		params[3];

	l = orig - sphere.point;
	params[0] = v_dot(dir, dir);
	params[1] = 2.0 * v_dot(dir, l);
	params[2] = v_dot(l, l) - sphere.radius * sphere.radius;
	if (!solve_quadratic(params, &t1, &t2))
		return (0);
	if (t1 > t2)
		ft_swap_d(&t1, &t2);
	if (t1 < 0)
	{
		t1 = t2;
		if (t1 < 0)
			return (0);
	}
	*t = t1;
	return (1);
}

short				get_sphere_data(t_ray *ray, t_object sphere, float t)
{
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = ray->p_hit - sphere.point;
	ray->n_hit = v_normalize(ray->n_hit);
	return (1);
}
