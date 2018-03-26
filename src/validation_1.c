/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:00:32 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/26 11:40:15 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

float	get_ior(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret < 0.5 || ret > 2.0)
		put_error("Not valid object ior value.");
	return (ret);
}

float	get_refract(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret < 0 || ret > 1)
		put_error("Not valid object refract value.");
	return (ret);
}

float	get_reflect(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret < 0 || ret > 1)
		put_error("Not valid object reflect value.");
	return (ret);
}

float	get_radius(json_value *value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret <= 0)
		put_error("Not valid object radius value.");
	return (ret);
}

float	get_intensity(json_value *value)
{
	float	ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	if (ret < 0)
		put_error("Not valid light intensity value.");
	return (ret);
}
