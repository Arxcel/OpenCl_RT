/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrive_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:46:38 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/23 15:10:59 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static int		set_t_type(json_value *value)
{
	int err;
	int val;

	err = 0;
	val = -1;
	if (value->type != json_string)
		err = 1;
	if (!err && !ft_strcmp(value->u.string.ptr, "chessboard"))
		val = T_CHECK;
	else if (!err && !ft_strcmp(value->u.string.ptr, "gradient-1"))
		val = T_GRAD1;
	else if (!err && !ft_strcmp(value->u.string.ptr, "gradient-2"))
		val = T_GRAD2;
	else if (!err && !ft_strcmp(value->u.string.ptr, "circle"))
		val = T_CIRC;
	else if (!err && !ft_strcmp(value->u.string.ptr, "brick"))
		val = T_BRICK;
	else
		err = 1;
	if (err)
		put_error("Not valid texture type.");
	return (val);
}

static t_object		set_defaults(json_value *value)
{
	if (value->type != json_string)
		return (default_error());
	if (!ft_strcmp(value->u.string.ptr, "plane"))
		return (default_plane());
	else if (!ft_strcmp(value->u.string.ptr, "sphere"))
		return (default_sphere());
	else if (!ft_strcmp(value->u.string.ptr, "cylinder"))
		return (default_cylinder());
	else if (!ft_strcmp(value->u.string.ptr, "conus"))
		return (default_conus());
	else if (!ft_strcmp(value->u.string.ptr, "disk"))
		return (default_disk());
	else if (!ft_strcmp(value->u.string.ptr, "triangle"))
		return (default_triangle());
	else if (!ft_strcmp(value->u.string.ptr, "paraboloid"))
		return (default_paraboloid());
	else if (!ft_strcmp(value->u.string.ptr, "square"))
		return (default_square());
	return (default_error());
}

static void		get_object_info_single(t_object *o,
	char *n, struct _json_value *val)
{
	*o = !ft_strcmp(n, "type") ? set_defaults(val) : *o;
	o->dir = !ft_strcmp(n, "direction") ? get_n_vector(val) : o->dir;
	o->pos1 = !ft_strcmp(n, "pos1") ? get_vector(val) : o->pos1;
	o->color = !ft_strcmp(n, "color") ? get_color(val) : o->color;
	o->ior = !ft_strcmp(n, "ior") ? get_number(val) : o->ior;
	o->refract = !ft_strcmp(n, "refract") ? get_number(val) : o->refract;
	o->radius = !ft_strcmp(n, "radius") ? get_number(val) : o->radius;
	o->specular = !ft_strcmp(n, "specular") ? get_number(val) : o->specular;
	o->angle = !ft_strcmp(n, "angle") ? get_number(val) : o->angle;
	o->reflect = !ft_strcmp(n, "reflect") ? get_number(val) : o->reflect;
	o->pos1 = !ft_strcmp(n, "pos1") ? get_vector(val) : o->pos1;
	o->pos2 = !ft_strcmp(n, "pos2") ? get_vector(val) : o->pos2;
	o->pos3 = !ft_strcmp(n, "pos3") ? get_vector(val) : o->pos3;
	o->max = !ft_strcmp(n, "max") ? get_number(val) : o->max;
	o->min = !ft_strcmp(n, "min") ? get_number(val) : o->min;
	o->tex_id = !ft_strcmp(n, "pattern") ? set_t_type(val) : o->tex_id;
	o->tex_scale = !ft_strcmp(n, "pattern_scale") ? get_number(val) : o->tex_scale;;
}

static void		get_object_info(json_value *value, t_object *o)
{
	unsigned int			x;
	char					*n;
	struct _json_value		*val;

	x = -1;
	while (++x < value->u.object.length)
	{
		n = value->u.object.values[x].name;
		val = value->u.object.values[x].value;
		get_object_info_single(o, n, val);
		if (o->type == -1 && write(2, "Not valid object type.\n", 23))
			break ;
	}
}

void			process_scene_o(json_value *value, t_scene *s)
{
	int x;

	s->o_num = value->u.object.length + 1;
	s->object = (t_object*)ft_memalloc(sizeof(t_object) * s->o_num);
	ft_bzero(s->object, sizeof(s->object));
	x = -1;
	while (++x < (s->o_num - 1))
	{
		get_object_info(value->u.array.values[x], &s->object[x]);
		if (s->object[x].type == -1)
		{
			x--;
			s->o_num--;
			continue ;
		}
		if (s->object[x].type == O_TRIANGLE)
			create_triangle_norm(&s->object[x]);
		if (s->object[x].type == O_SQUARE)
			create_triangle_norm(&s->object[x]);
		else if (s->object[x].type == O_CON)
			create_conus(&s->object[x]);
	}
}
