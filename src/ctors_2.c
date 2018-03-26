/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctors_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:28:14 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/26 12:01:48 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

t_object			default_triangle(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_TRIANGLE;
	result.color = (t_vector){0.7, 0.7, 0.7};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 1, 0};
	result.pos2 = (t_vector){10, 0, -10};
	result.pos3 = (t_vector){-10, 0, -10};
	create_triangle_norm(&result);
	return (result);
}

t_object			default_disk(void)
{
	t_object		result;

	ft_bzero(&result, sizeof(t_object));
	result.type = O_DISK;
	result.color = (t_vector){0.6, 0.6, 0.6};
	result.specular = 1;
	result.refract = 0;
	result.reflect = 0;
	result.pos1 = (t_vector){0, 0, 0};
	result.dir = (t_vector){0, 1, 0};
	result.radius = 2;
	return (result);
}

t_object			default_error(void)
{
	t_object		result;

	result.type = -1;
	return (result);
}
