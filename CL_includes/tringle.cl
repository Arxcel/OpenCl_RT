/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tringle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:24:34 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/15 16:28:08 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

short				triangle_cross(t_object *p, t_ray *r, float *t)
{
	float a;
	float t0;
	t_vector v;

	a = v_dot(p->dir, r->dir);
	if (a > 0)
	{
		v = p->point - r->orig; 
		t0 = v_dot(v, p->dir) / a;
		if (t0 >= 0)
		{
			*t = t0;
			return (1); 
		}
	}
	return (0);
}

short				get_triangle_data(t_ray *ray, t_object triangle, float t)
{
	ray->n_hit = triangle.dir;
	return (1);
}