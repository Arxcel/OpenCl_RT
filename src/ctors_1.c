/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctors_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:26:18 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/24 17:42:01 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

t_object			default_sphere(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_SPHERE;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 0, 0};
	result.radius = 1;
	return (result);
}

t_object			default_cylinder(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_CYL;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 0, 0};
	result.radius = 1;
	result.dir = (t_vector){0, 1, 0};
	return (result);
}

t_object			default_conus(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_CON;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, -1, 0};
	result.dir = (t_vector){0, 1, 0};
	result.angle = 45;
	create_conus(&result);
	return (result);
}

t_object			default_plane(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_PLANE;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 0, 0};
	result.dir = (t_vector){0, 1, 0};
	return (result);
}

t_object			default_paraboloid(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_PARABOLOID;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.dir = (t_vector){0, 1, 0};
	result.radius = 1;
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	return (result);
}
