/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:57 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/15 16:47:33 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

static int			is_in_triangle(t_object *obj, t_vector p, t_vector e0,
	t_vector e1, t_vector e2)
{
		t_vector	c0;
		t_vector	c1;
		t_vector	c2;

		c0 = p - obj->p1;
		c1 = p - obj->p2;
		c2 = p - obj->p3;
			// 	Vec3f edge0 = v1 - v0; 
			// Vec3f edge1 = v2 - v1; 
			// Vec3f edge2 = v0 - v2; 
			// t_vector C0 = P - v0; 
			// t_vector C1 = P - v1; 
			// t_vector C2 = P - v2; 
			if (v_dot(obj->dir, v_cross(e0, c0)) > 0 && 
				v_dot(obj->dir, v_cross(e1, c1)) > 0 && 
				v_dot(obj->dir, v_cross(e2, c2)) > 0)
				return (1);
	return (0);
}

short				triangle_cross(t_object *p, t_ray *r, float *t)
{
	float		a;
	float		t0;
	t_vector	v;
	t_vector	c0;
	t_vector	c1;
	t_vector	c2;
	t_vector	e0;
	t_vector	e1;
	t_vector	e2;
	t_vector	point;

	a = v_dot(p->dir, r->dir);
	if (a)
	{
		v = p->p3 - r->orig; 
		t0 = v_dot(v, p->dir) / a;
		if (t0 >= 0)
		{
			point = r->orig + v_mult_d(r->dir, t0);
	// 		e0 = p->p2 - p->p1;
	// 		e1 = p->p3 - p->p2;
	// 		e2 = p->p1 - p->p3;
	// 		c0 = point - p->p1;
	// 		c1 = point - p->p2;
	// 		c2 = point - p->p3;
			t_vector c; // vector perpendicular to triangle's plane 
 
			// edge 0
			e0 = p->p2 - p->p1;
			c0 = point - p->p1;
			c = v_cross(e0, c0);
			if (v_dot(p->dir, c) < 0)
				return (0);
			
			e1 = p->p3 - p->p2;
			c1 = point - p->p2;
			c = v_cross(e1, c1);
			if (v_dot(p->dir, c) < 0)
				return (0);
			
			e2 = p->p1 - p->p1;
			c2 = point - p->p1;
			c = v_cross(e0, c0);
			if (v_dot(p->dir, c) < 0)
				return (0);
			*t = t0;
			return (1);
		}
	}
	return (0);
}

short				get_triangle_data(t_ray *ray, t_object triangle, float t)
{
	// t_vector a;
	// t_vector b;
	// t_vector c;

	// a = triangle.p2 - triangle.p1;
	// b = triangle.p3 - triangle.p1;
	// c = v_cross(a, b);
	// triangle.dir = v_normalize(c);
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = triangle.dir;
	return (1);
}