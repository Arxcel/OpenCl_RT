/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrive_lights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:50:44 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/23 16:51:37 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void		set_l_type(json_value *value, t_light *l)
{
	if (value->type != json_string)
		put_error("Not valid light type");
	if (!ft_strcmp(value->u.string.ptr, "lamp"))
		*l = default_lamp();
	else if (!ft_strcmp(value->u.string.ptr, "ambient"))
		*l = default_ambient();
	else if (!ft_strcmp(value->u.string.ptr, "parallel"))
		*l = default_parallel();
	else if (!ft_strcmp(value->u.string.ptr, "area"))
		*l = default_area();
	else
		put_error("Not valid light type");
}

static void		get_light_info(json_value *value, t_light *l)
{
	int		length;
	int		x;

	if (value == NULL)
		return ;
	length = value->u.object.length;
	x = -1;
	while (++x < length)
	{
		if (!ft_strcmp(value->u.object.values[x].name, "type"))
			set_l_type(value->u.object.values[x].value, l);
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
		if (l->type == -1 || l->intence < 0)
			put_error("Not valid light type/intensity");
	}
}

void			process_scene_l(json_value *value, t_scene *s)
{
	int x;

	s->l_num = value->u.object.length + 1;
	s->light = (t_light*)ft_memalloc(sizeof(t_light) * s->l_num);
	ft_bzero(s->light, sizeof(s->light));
	x = -1;
	while (++x < (s->l_num - 1))
	{
		get_light_info(value->u.array.values[x], &s->light[x]);
		if (s->light[x].type == -1)
		{
			x--;
			s->l_num--;
		}
	}
}
