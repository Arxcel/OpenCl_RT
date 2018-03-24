/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrive_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:04:06 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/23 16:53:36 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

float		get_number(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	return (ret);
}

t_vector	get_vector(json_value *value)
{
	t_vector	v;
	int			length;
	int			x;

	v = (t_vector){0, 0, 0};
	if (value == NULL)
		put_error("No value for vector.");
	if ((length = value->u.array.length) != 3)
		put_error("Wrong vector length.");
	x = -1;
	while (++x < length)
		v[x] = get_number(value->u.array.values[x]);
	return (v);
}

t_vector	get_n_vector(json_value *value)
{
	t_vector	v;
	int			length;
	int			x;

	v = (t_vector){0, 0, 0};
	if (value == NULL)
		put_error("No value for object direction.");
	if ((length = value->u.array.length) != 3)
		put_error("Wrong vector length for object direction.");
	x = -1;
	while (++x < length)
		v[x] = get_number(value->u.array.values[x]);
	v = v_normalize(v);
	return (v);
}

t_vector	get_color(json_value *value)
{
	t_vector	v;
	int			length;
	int			x;

	v = (t_vector){0, 0, 0};
	if (value == NULL)
		put_error("No value for vector.");
	if ((length = value->u.array.length) != 3)
		put_error("Wrong vector length.");
	x = -1;
	while (++x < length)
	{
		v[x] = get_number(value->u.array.values[x]);
		if (v[x] > 1 || v[x] < 0)
			put_error("The color intensity can not\
			be more than 1 or less than 0.");
	}
	return (v);
}
