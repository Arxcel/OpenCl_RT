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

#include "ft_rt.h"

short				cube_cross(t_object *o, t_ray *ray, float *t)
{
    short		flag;
	float		t_buf;
	float		t_min;
	t_vector	par_buf[3];
    float       d;

	t_buf = INF;
	t_min = INF;
	flag = 0;
    d = v_length(o->pos1 - o->pos2);
	if (square_cross(o, ray, &t_buf) && t_buf < t_min)
	{
		t_min = t_buf;
		o->mini_type = O_SQUARE;
		flag = 1;
		*t = t_buf;
	}
	par_buf[0] = o->pos1;
    par_buf[1] = o->pos2;
	o->pos1 = o->pos1 + v_mult_d(v_normalize(o->dir), d / sqrt(2.0));
    o->pos2 = o->pos2 + v_mult_d(v_normalize(o->dir), d / sqrt(2.0));
	if (square_cross(o, ray, &t_buf) && t_buf < t_min)
	{
		t_min = t_buf;
		o->mini_type = O_SQUARE;
		flag = 1;
		*t = t_buf;
	}
	else
    {
		o->pos1 = par_buf[0];
        o->pos2 = par_buf[0];
    }
	return(flag);
}
