/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:58:32 by anestor           #+#    #+#             */
/*   Updated: 2018/03/23 16:27:01 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

char		*read_object_type(int i, t_main *m)
{
	int		t;

	t = m->s.object[i].type;
	if (t == 1)
		return (ft_strdup("sphere"));
	if (t == 2)
		return (ft_strdup("conus"));
	if (t == 3)
		return (ft_strdup("plane"));
	if (t == 4)
		return (ft_strdup("cylinder"));
	if (t == 5)
		return (ft_strdup("disk"));
	if (t == 6)
		return (ft_strdup("triangle"));
	if (t == 7)
		return (ft_strdup("paraboloid"));
	if (t == 8)
		return (ft_strdup("square"));
	return (ft_strdup(""));
}

char		*read_light_type(int i, t_main *m)
{
	int		t;

	t = m->s.light[i].type;
	if (t == 1)
		return (ft_strdup("parallel"));
	if (t == 2)
		return (ft_strdup("lamp"));
	if (t == 3)
		return (ft_strdup("ambient"));
	if (t == 4)
		return (ft_strdup("area"));
	return (ft_strdup(""));
}

char		*read_camera_type(int i, t_main *m)
{
	int		t;

	t = m->s.camera[i].type;
	if (t == 1)
		return (ft_strdup("common"));
	return (ft_strdup(""));
}

char		*read_pattern_type(int i, t_main *m)
{
	int		t;

	t = m->s.object[i].tex_id;
	if (t == 2)
		return (ft_strdup("chessboard"));
	if (t == 3)
		return (ft_strdup("gradient-1"));
	if (t == 4)
		return (ft_strdup("gradient-2"));
	if (t == 5)
		return (ft_strdup("circle"));
	if (t == 6)
		return (ft_strdup("brick"));
	if (t == 7)
		return (ft_strdup("custom-1"));
	if (t == 8)
		return (ft_strdup("custom-2"));
	if (t == 9)
		return (ft_strdup("custom-3"));
	if (t == 10)
		return (ft_strdup("custom-4"));
	return (ft_strdup(""));
}

static void	dprintf_obj(int fd, t_main *m, int i, char *type)
{
	dprintf(fd, "\t{\n\t\t\t\"type\": \"%s\",\n", type);
	ft_memdel((void **)&type);
	dprintf(fd, "\t\t\t\"color\": [%f, %f, %f],\n",
	m->s.object[i].color[0], m->s.object[i].color[1], m->s.object[i].color[2]);
	dprintf(fd, "\t\t\t\"direction\": [%f, %f, %f],\n",
	m->s.object[i].dir[0], m->s.object[i].dir[1], m->s.object[i].dir[2]);
	dprintf(fd, "\t\t\t\"pos1\": [%f, %f, %f],\n",
	m->s.object[i].pos1[0], m->s.object[i].pos1[1], m->s.object[i].pos1[2]);
	dprintf(fd, "\t\t\t\"pos2\": [%f, %f, %f],\n",
	m->s.object[i].pos2[0], m->s.object[i].pos2[1], m->s.object[i].pos2[2]);
	dprintf(fd, "\t\t\t\"pos3\": [%f, %f, %f],\n",
	m->s.object[i].pos3[0], m->s.object[i].pos3[1], m->s.object[i].pos3[2]);
	dprintf(fd, "\t\t\t\"radius\": %f,\n", m->s.object[i].radius);
	dprintf(fd, "\t\t\t\"angle\": %f,\n", DEG(2 * atan(m->s.object[i].angle)));
	dprintf(fd, "\t\t\t\"reflect\": %f,\n", m->s.object[i].reflect);
	dprintf(fd, "\t\t\t\"refract\": %f,\n", m->s.object[i].refract);
	dprintf(fd, "\t\t\t\"specular\": %d,\n", m->s.object[i].specular);
	dprintf(fd, "\t\t\t\"ior\": %f,\n", m->s.object[i].ior);
	dprintf(fd, "\t\t\t\"min\": %f,\n", m->s.object[i].min);
	dprintf(fd, "\t\t\t\"max\": %f,\n", m->s.object[i].max);
	dprintf(fd, "\t\t\t\"pattern_scale\": %d,\n", m->s.object[i].tex_scale);
	dprintf(fd, "\t\t\t\"tex_angle\": %d,\n", m->s.object[i].tex_angle);
}

static void	dprintf_light(int fd, t_main *m, int i, char *type)
{
	dprintf(fd, "\t{\n");
	dprintf(fd, "\t\t\t\"type\": \"%s\",\n", type);
	ft_memdel((void **)&type);
	dprintf(fd, "\t\t\t\"color\": [%f, %f, %f],\n",
	m->s.light[i].color[0], m->s.light[i].color[1], m->s.light[i].color[2]);
	dprintf(fd, "\t\t\t\"direction\": [%f, %f, %f],\n",
	m->s.light[i].dir[0], m->s.light[i].dir[1], m->s.light[i].dir[2]);
	dprintf(fd, "\t\t\t\"position\": [%f, %f, %f],\n",
	m->s.light[i].pos[0], m->s.light[i].pos[1], m->s.light[i].pos[2]);
	dprintf(fd, "\t\t\t\"pos2\": [%f, %f, %f],\n",
	m->s.light[i].pos2[0], m->s.light[i].pos2[1], m->s.light[i].pos2[2]);
	dprintf(fd, "\t\t\t\"intensity\": %f,\n", m->s.light[i].intence);
	dprintf(fd, "\t\t\t\"angle\": %f,\n", m->s.light[i].ang);
	dprintf(fd, "\t\t},\n");
}

static void	dprintf_cam(int fd, t_main *m, int i, char *type)
{
	dprintf(fd, "\t{\n");
	dprintf(fd, "\t\t\t\"type\": \"%s\",\n", type);
	ft_memdel((void **)&type);
	dprintf(fd, "\t\t\t\"direction\": [%f, %f, %f],\n",
	m->s.camera[i].dir[0], m->s.camera[i].dir[1], m->s.camera[i].dir[2]);
	dprintf(fd, "\t\t\t\"position\": [%f, %f, %f],\n",
	m->s.camera[i].pos[0], m->s.camera[i].pos[1], m->s.camera[i].pos[2]);
	dprintf(fd, "\t\t\t\"rotation\": [%f, %f, %f],\n",
	m->s.camera[i].rot[0], m->s.camera[i].rot[1], m->s.camera[i].rot[2]);
	dprintf(fd, "\t\t\t\"field_of_view\": %f,\n", m->s.camera[i].fov);
	dprintf(fd, "\t\t},\n");
}

void		save_function(int fd, t_main *m)
{
	int		i;
	char	*type;

	dprintf(fd, "{\n\t\"objects\": [\n");
	i = -1;
	while (++i != m->s.o_num - 1)
	{
		dprintf_obj(fd, m, i, read_object_type(i, m));
		type = read_pattern_type(i, m);
		if (type[0] != '\0')
			dprintf(fd, "\t\t\t\"pattern\": \"%s\",\n", type);
		dprintf(fd, "\t\t},\n");
		ft_memdel((void **)&type);
	}
	dprintf(fd, "\t],\n");
	dprintf(fd, "\t\"lights\": [\n");
	i = -1;
	while (++i != m->s.l_num - 1)
		dprintf_light(fd, m, i, read_light_type(i, m));
	dprintf(fd, "\t],\n");
	dprintf(fd, "\t\"cameras\": [\n");
	i = -1;
	while (++i != m->s.c_num - 1)
		dprintf_cam(fd, m, i, read_camera_type(i, m));
	dprintf(fd, "\t]\n}");
}
