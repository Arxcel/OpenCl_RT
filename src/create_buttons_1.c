/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buttons_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:40:24 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/25 19:51:02 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void		light_array_realloc(t_main *m, t_light new_object)
{
	t_light		*new_array;
	size_t		i;

	new_array = (t_light*)malloc(sizeof(t_light) * (m->s.l_num + 1));
	ft_bzero(new_array, sizeof(t_light) * (m->s.l_num + 1));
	i = 0;
	m->s.light[m->s.l_num - 1] = new_object;
	while (i < m->s.l_num)
	{
		new_array[i] = m->s.light[i];
		i++;
	}
	new_array[i].type = 0;
	m->s.l_num++;
	free(m->s.light);
	m->s.light = new_array;
	m->sdl.changes = 1;
}

static void		camera_array_realloc(t_main *m, t_camera new_object)
{
	t_camera	*new_array;
	size_t		i;

	new_array = (t_camera*)malloc(sizeof(t_camera) * (m->s.c_num + 1));
	ft_bzero(new_array, sizeof(t_camera) * (m->s.c_num + 1));
	i = 0;
	m->s.camera[m->s.c_num - 1] = new_object;
	while (i < m->s.c_num)
	{
		new_array[i] = m->s.camera[i];
		i++;
	}
	new_array[i].type = 0;
	m->s.c_num++;
	free(m->s.camera);
	m->s.camera = new_array;
	m->sdl.changes = 1;
}

static void		object_array_realloc(t_main *m, t_object new_object)
{
	t_object	*new_array;
	size_t		i;

	new_array = (t_object*)malloc(sizeof(t_object) * (m->s.o_num + 1));
	ft_bzero(new_array, sizeof(t_object) * (m->s.o_num + 1));
	i = 0;
	m->s.object[m->s.o_num - 1] = new_object;
	while (i < m->s.o_num)
	{
		new_array[i] = m->s.object[i];
		i++;
	}
	new_array[i].type = 0;
	m->s.o_num++;
	free(m->s.object);
	m->s.object = new_array;
	m->sdl.changes = 1;
}

static void		create_shapes_2(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.btn[BTN_CAM].rect)
								&& m->ui.btn[BTN_CAM].status)
		camera_array_realloc(m, default_camera());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_LIGHT1].rect)
								&& m->ui.btn[BTN_LIGHT1].status)
		light_array_realloc(m, default_lamp());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_LIGHT2].rect)
								&& m->ui.btn[BTN_LIGHT2].status)
		light_array_realloc(m, default_area());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_LIGHT3].rect)
								&& m->ui.btn[BTN_LIGHT3].status)
		light_array_realloc(m, default_parallel());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_LIGHT4].rect)
								&& m->ui.btn[BTN_LIGHT4].status)
		light_array_realloc(m, default_ambient());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_SQUARE].rect)
								&& m->ui.btn[BTN_SQUARE].status)
		object_array_realloc(m, default_square());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_CAPS].rect)
								&& m->ui.btn[BTN_CAPS].status)
		object_array_realloc(m, default_capsula());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_BARB].rect)
								&& m->ui.btn[BTN_BARB].status)
		object_array_realloc(m, default_barbell());
}

void			create_shapes(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.btn[BTN_SPHERE].rect)
								&& m->ui.btn[BTN_SPHERE].status)
		object_array_realloc(m, default_sphere());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_CYLINDER].rect)
								&& m->ui.btn[BTN_CYLINDER].status)
		object_array_realloc(m, default_cylinder());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_CONUS].rect)
								&& m->ui.btn[BTN_CONUS].status)
		object_array_realloc(m, default_conus());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_PARABOLOID].rect)
								&& m->ui.btn[BTN_PARABOLOID].status)
		object_array_realloc(m, default_paraboloid());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_DISK].rect)
								&& m->ui.btn[BTN_DISK].status)
		object_array_realloc(m, default_disk());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_PLANE].rect)
								&& m->ui.btn[BTN_PLANE].status)
		object_array_realloc(m, default_plane());
	else if (xy_in_rect(x, y, m->ui.btn[BTN_TRIANGLE].rect)
								&& m->ui.btn[BTN_TRIANGLE].status)
		object_array_realloc(m, default_triangle());
	else
		create_shapes_2(x, y, m);
}
