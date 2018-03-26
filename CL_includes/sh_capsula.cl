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

short				capsula_cross(t_object *object, t_ray *ray, float *t)
{
	short		flag;
	float		t_buf;
	float		t_min;
	t_vector	par_buf;

	t_buf = INF;
	t_min = INF;
	flag = 0;
	object->dir = v_normalize(object->dir);
	if (sphere_cross(*object, ray, &t_buf) && t_buf < t_min)
	{
		t_min = t_buf;
		object->mini_type = O_SPHERE;
		flag = 1;
		*t = t_buf;
	}
	if (cyl_cross(*object, ray, &t_buf) && t_buf < t_min)
	{
		t_min = t_buf;
		object->mini_type = O_CYL;
		flag = 1;
		*t = t_buf;
	}
	par_buf = object->pos1;
	object->pos1 = object->pos1 + v_mult_d(v_normalize(object->dir), object->max);
	if (sphere_cross(*object, ray, &t_buf) && t_buf < t_min)
	{
		t_min = t_buf;
		object->mini_type = O_SPHERE;
		flag = 1;
		*t = t_buf;
	}
	else
		object->pos1 = par_buf;
	return(flag);
}
