/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrive_cameras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:02:37 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/24 11:28:50 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static t_camera		default_camera(void)
{
	t_camera		result;

	ft_bzero(&result, sizeof(t_camera));
	result.type = 1;
	result.pos = (t_vector){0, 0, 4};
	result.rot = (t_vector){0, 0, 0};
	result.fov = 50;
	result.dir = (t_vector){0, 0, -1};
	return (result);
}

static int			set_c_type(json_value *value, t_camera *c)
{
	int err;
	int val;

	err = 0;
	val = -1;
	if (value->type != json_string)
		err = 1;
	if (!err && !ft_strcmp(value->u.string.ptr, "common"))
	{
		*c = default_camera();
		val = 1;
	}
	else
		err = 1;
	if (err)
		put_error("Not valid camera type");
	return (val);
}

static void			get_camera_info(json_value *value, t_camera *c)
{
	int length;
	int x;

	if (value == NULL)
		return ;
	length = value->u.object.length;
	x = -1;
	while (++x < length)
	{
		if (!ft_strcmp(value->u.object.values[x].name, "type"))
			c->type = set_c_type(value->u.object.values[x].value, c);
		if (!ft_strcmp(value->u.object.values[x].name, "position"))
			c->pos = get_vector(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "field_of_view"))
			c->fov = get_number(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "rotation"))
			c->rot = get_vector(value->u.object.values[x].value);
	}
}

void				process_scene_c(json_value *value, t_scene *s)
{
	int x;

	s->c_num = value->u.object.length + 1;
	s->camera = (t_camera*)ft_memalloc(sizeof(t_camera) * s->c_num);
	ft_bzero(s->camera, sizeof(s->camera));
	x = -1;
	while (++x < s->c_num - 1)
	{
		get_camera_info(value->u.array.values[x], &s->camera[x]);
		if (s->camera[x].fov <= 0 || s->camera[x].type == -1)
			put_error("Not valid camera");
	}
	s->cam_base.pos = s->camera[x - 1].pos;
	s->cam_base.rot = s->camera[x - 1].rot;
}
