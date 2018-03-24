/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctors_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:28:14 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/24 22:22:22 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

t_object			default_triangle(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_TRIANGLE;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 0;
	result.refract = 0;
	result.reflect = 0.1;
	result.ior = 0.5;
	result.pos1 = (t_vector){0, 0, 0};
	result.pos2 = (t_vector){1, 0, -1};
	result.pos3 = (t_vector){-1, 0, -1};
	return (result);
}

t_object			default_disk(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_DISK;
	result.color = (t_vector){0.6, 0.6, 0.6};
	result.specular = 2;
	result.refract = 0;
	result.reflect = 0.1;
	result.ior = 0.5;
	result.pos1 = (t_vector){0, 0, 0};
	result.dir = (t_vector){0, 1, 0};
	result.radius = 1;
	return (result);
}

t_object			default_square(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_SQUARE;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 0;
	result.refract = 0;
	result.reflect = 0.1;
	result.ior = 0.5;
	result.pos1 = (t_vector){-0.5, 0.5, -1};
	result.pos2 = (t_vector){0.5, -0.5, -1};
	result.dir = (t_vector){0, 0, 1};
	result.min = 1;
	return (result);
}

t_object			default_cube(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_CUBE;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 0;
	result.refract = 0;
	result.reflect = 0.1;
	result.ior = 0.5;
	result.pos1 = (t_vector){-1, 1, -20};
	result.pos2 = (t_vector){1, 1, -18};
	result.dir = (t_vector){0, 2, 0};
	result.min = 1;
	return (result);
}

t_object			default_capsula(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_CAPSULA;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 0;
	result.refract = 0;
	result.reflect = 0.1;
	result.ior = 0.5;
	result.pos1 = (t_vector){0, 0, 0};
	result.dir = (t_vector){0, 1, 0};
	result.max = 2;
	result.radius = 1;
	return (result);
}

t_object			default_error(void)
{
	t_object		result;

	result.type = -1;
	return (result);
}
