/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_elipsoid.cl                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:34:34 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/18 16:34:38 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

short				cross_elipsoid(t_object elips, t_ray *r, float *t)
{
	float		t1;
	float		t2;
	t_vector	X;
	float		params[3];
	float		A1;
	float		A2;
	float		r2;

	r2 = elips.radius * elips.radius;
	X = r->orig - elips.pos1;
	A1 = 2 * elips.angle * v_dot(r->dir, elips.dir);
	A2 = r2 + 2 * elips.angle * v_dot(X, elips.dir) - elips.angle;
	params[0] = 4 * r2 * v_dot(r->dir, r->dir) - A1 * A1;
	params[1] = 2 * (4 * r2 * v_dot(r->dir, X) - A1 * A2);
	params[2] = 4 * r2 * v_dot(X, X) - A2 * A2;
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

short				get_elipsoid_data(t_ray *ray, t_object elips, float t)
{
	float		a;
	float		b;
	t_vector	cmid;
	t_vector	R;
	float		A1;
	float		A2;
	t_vector	X;
	float		r2;

	r2 = elips.radius * elips.radius;
	X = ray->orig - elips.pos1;
	A1 = 2 * elips.angle * v_dot(ray->dir, elips.dir);
	A2 = r2 + 2 * elips.angle * v_dot(X, elips.dir) - elips.angle;
	a = 4 * elips.radius * elips.radius * v_dot(ray->dir, ray->dir) - A1 * A1;
	b = 2.0 * (4 * elips.radius * elips.radius * v_dot(ray->dir, X) - A1 * A2);

	cmid = elips.pos1 + v_mult_d(ray->dir, elips.angle / 2);
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	R = ray->p_hit - cmid;
	ray->n_hit = -v_normalize(R - v_mult_d(ray->dir, (1 - (b * b) / (a * a)) * (v_dot(R, ray->dir))));
	// ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	// ray->n_hit = v_normalize(ray->p_hit - sphere.pos1);
	// ray->tex[0] = (1 + atan2(ray->n_hit[2], ray->n_hit[0]) / M_PI) * 0.5;
	// ray->tex[1] = acos(ray->n_hit[1]) / M_PI;
	return (1);
}

