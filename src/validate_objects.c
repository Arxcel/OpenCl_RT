/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:52:10 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/25 17:04:03 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void			create_triangle_norm(t_object *obj)
{
	t_vector a;
	t_vector b;
	t_vector c;

	if (v_is_eq(obj->pos1, obj->pos2) || v_is_eq(obj->pos1, obj->pos3) ||
		v_is_eq(obj->pos3, obj->pos2))
		put_error("Not valid triangle");
	a = obj->pos2 - obj->pos1;
	b = obj->pos3 - obj->pos1;
	c = v_cross(a, b);
	obj->dir = v_normalize(c);
}

void			create_conus(t_object *obj)
{
	float		tmp;

	tmp = tan(ft_deg2rad(obj->angle / 2));
	obj->angle = tmp;
}

void			validate_elipsoid(t_object *object)
{
	if (object->angle >= object->radius)
		put_error("Not valid elipsoid");
}
