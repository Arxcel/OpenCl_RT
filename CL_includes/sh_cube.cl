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

short				cube_cross(t_object *p, t_ray *r, float *t)
{
    t_vector    p11;
    t_vector    p22;
    t_vector    p33;
    t_vector    p44;
    t_vector    p4;
    float       t_min;

    p4 = p->pos3 + v_mult_d(p->pos1 - p->pos2, v_length(p->pos1 - p->pos2));
    p11 = p->pos1 + v_mult_d(p->dir, p->min);
    p->pos1 = p4;
    p->pos2 = p->pos1;
    p->pos3 = p11;
    printf("%f, %f, %f\n", p11[0], p11[1], p11[2]);
    t_min = square_cross(p, r, t);
    return (t_min);
}

short				get_cube_data(t_ray *ray, t_object square, float t)
{
	ray->p_hit = ray->orig + v_mult_d(ray->dir, t);
	ray->n_hit = square.dir;
	return (1);
}