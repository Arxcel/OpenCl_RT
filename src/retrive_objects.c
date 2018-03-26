/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrive_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:46:38 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/26 12:46:07 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static int			set_t_type(json_value *value)
{
	if (value->type != json_string)
		put_error("Not valid json type.");
	if (!ft_strcmp(value->u.string.ptr, ""))
		return (T_STD);
	else if (!ft_strcmp(value->u.string.ptr, "chessboard"))
		return (T_CHECK);
	else if (!ft_strcmp(value->u.string.ptr, "gradient"))
		return (T_GRAD1);
	else if (!ft_strcmp(value->u.string.ptr, "perlin"))
		return (T_GRAD2);
	else if (!ft_strcmp(value->u.string.ptr, "circle"))
		return (T_CIRC);
	else if (!ft_strcmp(value->u.string.ptr, "brick"))
		return (T_BRICK);
	else if (!ft_strcmp(value->u.string.ptr, "custom-1"))
		return (T_CUSTOM1);
	else if (!ft_strcmp(value->u.string.ptr, "custom-2"))
		return (T_CUSTOM2);
	else if (!ft_strcmp(value->u.string.ptr, "custom-3"))
		return (T_CUSTOM3);
	else if (!ft_strcmp(value->u.string.ptr, "custom-4"))
		return (T_CUSTOM4);
	return (put_error("Not valid texture type."));
}

static t_object		set_defaults(json_value *value)
{
	t_object	result;

	if (value->type != json_string)
		put_error("Not valid json type.");
	if (!ft_strcmp(value->u.string.ptr, "plane"))
		return (default_plane());
	else if (!ft_strcmp(value->u.string.ptr, "sphere"))
		return (default_sphere());
	else if (!ft_strcmp(value->u.string.ptr, "cylinder"))
		return (default_cylinder());
	else if (!ft_strcmp(value->u.string.ptr, "conus"))
		return (default_conus());
	result = get_obj_for_retrive(value);
	if (result.type > 0)
		return (result);
	put_error("Not valid object type.");
	return (default_error());
}

static void			get_object_info_single(t_object *o,
	char *n, struct _json_value *val)
{
	*o = !ft_strcmp(n, "type") ? set_defaults(val) : *o;
	o->dir = !ft_strcmp(n, "direction") ? get_n_vector(val) : o->dir;
	o->pos1 = !ft_strcmp(n, "pos1") ? get_vector(val) : o->pos1;
	o->color = !ft_strcmp(n, "color") ? get_color(val) : o->color;
	o->ior = !ft_strcmp(n, "ior") ? get_ior(val) : o->ior;
	o->refract = !ft_strcmp(n, "refract") ? get_refract(val) : o->refract;
	o->radius = !ft_strcmp(n, "radius") ? get_radius(val) : o->radius;
	o->specular = !ft_strcmp(n, "specular") ?
		get_specular(val) : o->specular;
	o->angle = !ft_strcmp(n, "angle") || !ft_strcmp(n, "size") ?
		get_number(val) : o->angle;
	o->reflect = !ft_strcmp(n, "reflect") ? get_reflect(val) : o->reflect;
	o->pos1 = !ft_strcmp(n, "pos1") ? get_vector(val) : o->pos1;
	o->pos2 = !ft_strcmp(n, "pos2") ? get_vector(val) : o->pos2;
	o->pos3 = !ft_strcmp(n, "pos3") ? get_vector(val) : o->pos3;
	o->max = !ft_strcmp(n, "max") ? get_max(val) : o->max;
	o->min = !ft_strcmp(n, "min") ? get_number(val) : o->min;
	o->tex_id = !ft_strcmp(n, "pattern") ? set_t_type(val) : o->tex_id;
	o->tex_scale = !ft_strcmp(n, "pattern_scale") ?
		get_tex_scale(val) : o->tex_scale;
	o->tex_angle = !ft_strcmp(n, "tex_angle") ?
		get_tex_angle(val) : o->tex_angle;
}

static void			get_object_info(json_value *value, t_object *o)
{
	unsigned int			x;
	char					*n;

	x = -1;
	while (++x < value->u.object.length)
	{
		n = value->u.object.values[x].name;
		get_object_info_single(o, n, value->u.object.values[x].value);
		if (o->type == -1)
			put_error("Not valid texture type.");
	}
}

void				process_scene_o(json_value *value, t_scene *s)
{
	int x;

	s->o_num = value->u.object.length + 1;
	s->object = (t_object*)ft_memalloc(sizeof(t_object) * s->o_num);
	ft_bzero(s->object, sizeof(s->object) * s->o_num);
	x = -1;
	while (++x < (s->o_num - 1))
	{
		get_object_info(value->u.array.values[x], &s->object[x]);
		if (s->object[x].type == O_TRIANGLE)
			create_triangle_norm(&s->object[x]);
		else if (s->object[x].type == O_CON)
			create_conus(&s->object[x]);
		else if (s->object[x].type == O_ELIPSOID)
			validate_elipsoid(&s->object[x]);
	}
}
