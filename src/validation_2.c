/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:16:24 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/26 11:47:01 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

float	get_max(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret < 0)
		put_error("Not valid object max value.");
	return (ret);
}

float	get_tex_scale(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret < 0)
		put_error("Not valid object texture scale value.");
	return (ret);
}

float	get_tex_angle(json_value *value)
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

float	get_specular(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret < 0)
		put_error("Not valid object specular value.");
	return (ret);
}

float	get_fov(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret < 1 || ret > 100)
		put_error("Not valid camera fov value.");
	return (ret);
}
