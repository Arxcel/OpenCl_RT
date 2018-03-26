/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_square.cl                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:42:03 by pprivalo          #+#    #+#             */
/*   Updated: 2018/01/23 20:42:16 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.cl"

static short		is_in_square(t_vector p1, t_object *p)
{
	t_vector	r_b;
	t_vector	p_b;
	t_vector	x;
	t_vector	y;
	float		d;

	d = v_length(p->pos2 - p->pos1);
	p_b = p->pos1 + v_mult_d(v_normalize(p->pos2 - p->pos1), d / 2);
	p_b = p_b + v_mult_d(v_normalize(v_cross(p->pos1 - p->pos2, p->dir)), d / 2);
	x = v_normalize(p->pos1 - p_b);
	r_b = v_normalize(p_b - p1);
	y = v_normalize(p->pos2 - p_b);
	if ((v_dot(x, r_b) <= 0 && v_dot(y, r_b) <= 0))
	{
		if ((v_dot(x, v_normalize(p->pos1 - p1)) >= 0 && v_dot(y, v_normalize(p->pos2 - p1)) >= 0))
			return (1);
		return (0);
	}
	return (0);
}

short				square_cross(t_object *p, t_ray *r, float *t)
{
	float		t0;
	t_vector	v;

	t0 = v_dot(p->dir, r->dir);
	if (t0)
	{
		v = p->pos1 - r->orig; 
		t0 = v_dot(v, p->dir) / t0;
		if (t0 >= 0)
		{
			if (!is_in_square(r->orig + v_mult_d(r->dir, t0), p))
				return (0);
			*t = t0;
			return (1);
		}
	}
	return (0);
}

short				get_square_data(t_ray *ray, t_object square, float t)
{
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = square.dir;
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
