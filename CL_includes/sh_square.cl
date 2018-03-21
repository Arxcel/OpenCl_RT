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

#include "ft_rtv1.h"

static short		is_in_square(t_vector p1, t_object *p)
{
	t_vector	p_pos2;
    t_vector	p_pos1;
    t_vector    p_pos3;
	t_vector	x;
	t_vector	y;
    t_vector    s;
    float       d;

	x = v_normalize(p->pos1 - p->pos2);
	p_pos2 = v_normalize(p->pos2 - p1);
	p_pos1 = v_normalize(p->pos1 - p1);
	p_pos3 = v_normalize(p->pos3 - p1);
	y = v_normalize(p->pos3 - p->pos2);
	if ((v_dot(x, p_pos2) <= 0 && v_dot(y, p_pos2) <= 0))
    {
        if ((v_dot(x, p_pos1) >= 0 && v_dot(y, p_pos3) >= 0))
		    return (1);
		return (0);
    }
	return (0);
}

short				square_cross(t_object *p, t_ray *r, float *t)
{
	float		a;
	float		t0;
	t_vector	v;

	a = v_dot(p->dir, r->dir);
	if (a)
	{
		v = p->pos2 - r->orig; 
		t0 = v_dot(v, p->dir) / a;
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
	return (1);
}