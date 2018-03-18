/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:52:10 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/18 14:54:54 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void			create_triangle_norm(t_object *obj)
{
	t_vector a;
	t_vector b;
	t_vector c;

	if(v_is_eq(obj->p1, obj->p2) || v_is_eq(obj->p1, obj->p3) ||
		v_is_eq(obj->p3, obj->p2))
		put_error("Not valid triangle");
	a = obj->p2 - obj->p1;
	b = obj->p3 - obj->p1;
	c = v_cross(a, b);
	obj->dir = v_normalize(c);
}

void			create_conus(t_object *obj)
{
	float		tmp;

	tmp = tan(ft_deg2rad(obj->angle / 2));
	obj->angle = tmp;
}
