/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctors_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:57:46 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/26 12:01:56 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

t_object			default_square(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_SQUARE;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){-0.5, 0.5, -1};
	result.pos2 = (t_vector){0.5, -0.5, -1};
	result.dir = (t_vector){0, 0, 1};
	return (result);
}

t_object			default_elipsoid(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_ELIPSOID;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 0, 0};
	result.dir = (t_vector){0, 1, 0};
	result.radius = 1.1;
	result.angle = 1;
	return (result);
}

t_object			default_capsula(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_CAPSULA;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 0, 0};
	result.dir = (t_vector){0, 1, 0};
	result.max = 2;
	result.radius = 1;
	return (result);
}

t_object			default_barbell(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_BARBELL;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 0, 0};
	result.dir = (t_vector){0, 1, 0};
	result.max = 2;
	result.radius = 1;
	return (result);
}

t_object			default_cddisk(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_CDDISK;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 0, 0};
	result.dir = (t_vector){0, 0, 1};
	result.min = 0.2;
	result.radius = 1;
	return (result);
}
