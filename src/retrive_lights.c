/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrive_lights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:50:44 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/23 17:47:00 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static int		set_l_type(json_value *value)
{
	int err;
	int val;

	err = 0;
	val = -1;
	if (value->type != json_string)
		err = 1;
	if (!err && !ft_strcmp(value->u.string.ptr, "lamp"))
		val = L_LAMP;
	else if (!err && !ft_strcmp(value->u.string.ptr, "ambient"))
		val = L_AMBIENT;
	else if (!err && !ft_strcmp(value->u.string.ptr, "parallel"))
		val = L_PAR;
	else if (!err && !ft_strcmp(value->u.string.ptr, "area"))
		val = L_AREA;
	else
		err = 1;
	if (err)
		put_error("Not valid light type");
	return (val);
}

static void		get_light_info(json_value *value, t_light *l)
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
			l->type = set_l_type(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "position"))
			l->pos = get_vector(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "direction"))
			l->dir = get_vector(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "angle"))
			l->ang = get_number(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "color"))
			l->color = get_color(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "intensity"))
			l->intence = get_number(value->u.object.values[x].value);
	}
}

void			process_scene_l(json_value *value, t_scene *s)
{
	int x;

	s->l_num = value->u.object.length + 1;
	s->light = (t_light*)ft_memalloc(sizeof(t_light) * s->l_num);
	ft_bzero(s->light, sizeof(s->light));
	x = -1;
	while (++x < s->l_num - 1)
		get_light_info(value->u.array.values[x], &s->light[x]);
}
