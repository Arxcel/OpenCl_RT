/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_export_save.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:10:10 by anestor           #+#    #+#             */
/*   Updated: 2018/03/23 02:34:56 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	open_file(t_main *m)
{
	const char	*open;
	const char	*format[1] = { "*.rt" };

	open = tinyfd_openFileDialog("", "", 1, format, NULL, 0);
	if (open == NULL)
		return ;
	delete_scene(&m->s);
	m->ui.scroll.first_step = 0;
	ft_memset(&m->s.cam_trans.pos, 0, sizeof(t_vector));
	ft_memset(&m->s.cam_trans.rot, 0, sizeof(t_vector));
	get_scene(open, &m->s);
	re_draw(&m->cl, &m->sdl, &m->s);
	render_scene_and_ui(m);
}

void	export_file(t_main *m)
{
	const char	*export;
	const char	*format[1] = { "*.png" };
	SDL_Surface *surface;

	export = tinyfd_saveFileDialog("", "export.png", 1, format, NULL);
	if (export == NULL)
		return ;
	surface = SDL_CreateRGBSurface(0, m->sdl.img.w, m->sdl.img.h,
															32, 0, 0, 0, 0);
	ft_memcpy(surface->pixels, m->sdl.img.pixels, surface->h * surface->pitch);
	IMG_SavePNG(surface, export);
	SDL_FreeSurface(surface);
}

void	save_file(t_main *m)
{
	(void)m;
	tinyfd_messageBox(
			"Error",
			"Not yet! We need JSON SAVE function!",
			"ok",
			"error",
			1);
	/*
	** save JSON code here
	*/
}

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


static void	save_function(int fd, t_main *m)
{
	int		i;
	char	*type;

	dprintf(fd, "{\n\t\"objects\": [\n");
	i = 0;
	while (i != m->s.o_num - 1)
	{
		dprintf(fd, "\t{\n");
		type = read_object_type(i, m);
		dprintf(fd, "\t\t\t\"type\": \"%s\",\n", type);
		ft_memdel((void **)&type);
		dprintf(fd, "\t\t\t\"color\": [%f, %f, %f],\n",
			m->s.object[i].color[0], m->s.object[i].color[1], 
			m->s.object[i].color[2]);
		dprintf(fd, "\t\t\t\"direction\": [%f, %f, %f],\n",
			m->s.object[i].dir[0], m->s.object[i].dir[1], 
			m->s.object[i].dir[2]);
		dprintf(fd, "\t\t\t\"pos1\": [%f, %f, %f],\n",
			m->s.object[i].pos1[0], m->s.object[i].pos1[1], 
			m->s.object[i].pos1[2]);
	//	dprintf(fd, "\t\t\t\"pos2\": [%f, %f, %f],\n",
	//		m->s.object[i].pos2[0], m->s.object[i].pos2[1], 
	//		m->s.object[i].pos2[2]);
	//	dprintf(fd, "\t\t\t\"pos3\": [%f, %f, %f],\n",
	//		m->s.object[i].pos3[0], m->s.object[i].pos3[1], 
	//		m->s.object[i].pos3[2]);
		dprintf(fd, "\t\t\t\"radius\": %f,\n", m->s.object[i].radius);
		dprintf(fd, "\t\t\t\"angle\": %f,\n", m->s.object[i].angle);
		dprintf(fd, "\t\t\t\"reflect\": %f,\n", m->s.object[i].reflect);
		dprintf(fd, "\t\t\t\"refract\": %f,\n", m->s.object[i].refract);
		dprintf(fd, "\t\t\t\"specular\": %d,\n", m->s.object[i].specular);
		dprintf(fd, "\t\t\t\"ior\": %f,\n", m->s.object[i].ior);
		dprintf(fd, "\t\t\t\"min\": %f,\n", m->s.object[i].min);
		dprintf(fd, "\t\t\t\"max\": %f,\n", m->s.object[i].max);
	//	dprintf(fd, "\t\t\t\"pattern_scale\": %d,\n", m->s.object[i].t_scale);
	//	dprintf(fd, "\t\t\t\"pattern\": %d,\n", m->s.object[i].t_id);
		dprintf(fd, "\t\t},\n");
		i++;
	}
	dprintf(fd, "\t],\n");
	dprintf(fd, "\t\"lights\": [\n");
	i = 0;
	while (i != m->s.l_num - 1)
	{
		dprintf(fd, "\t{\n");
		type = read_light_type(i, m);
		dprintf(fd, "\t\t\t\"type\": \"%s\",\n", type);
		ft_memdel((void **)&type);
		dprintf(fd, "\t\t\t\"color\": [%f, %f, %f],\n",
			m->s.light[i].color[0], m->s.light[i].color[1],
			m->s.light[i].color[2]);
		dprintf(fd, "\t\t\t\"direction\": [%f, %f, %f],\n",
			m->s.light[i].dir[0], m->s.light[i].dir[1],
			m->s.light[i].dir[2]);
		dprintf(fd, "\t\t\t\"position\": [%f, %f, %f],\n",
			m->s.light[i].pos[0], m->s.light[i].pos[1],
			m->s.light[i].pos[2]);
	//	dprintf(fd, "\t\t\t\"pos2\": [%f, %f, %f],\n",
	//		m->s.light[i].pos2[0], m->s.light[i].pos2[1],
	//		m->s.light[i].pos2[2]);
		dprintf(fd, "\t\t\t\"intensity\": %f,\n", m->s.light[i].intence);
		dprintf(fd, "\t\t\t\"angle\": %f,\n", m->s.light[i].ang);
		dprintf(fd, "\t\t},\n");
		i++;
	}
	dprintf(fd, "\t],\n");
	dprintf(fd, "\t\"cameras\": [\n");
	i = 0;
	while (i != m->s.c_num - 1)
	{
		dprintf(fd, "\t{\n");
		type = read_camera_type(i, m);
		dprintf(fd, "\t\t\t\"type\": \"%s\",\n", type);
		ft_memdel((void **)&type);
		dprintf(fd, "\t\t\t\"direction\": [%f, %f, %f],\n",
			m->s.camera[i].dir[0], m->s.camera[i].dir[1],
			m->s.camera[i].dir[2]);
		dprintf(fd, "\t\t\t\"position\": [%f, %f, %f],\n",
			m->s.camera[i].pos[0], m->s.camera[i].pos[1],
			m->s.camera[i].pos[2]);
		dprintf(fd, "\t\t\t\"rotation\": [%f, %f, %f],\n",
			m->s.camera[i].rot[0], m->s.camera[i].rot[1],
			m->s.camera[i].rot[2]);
		dprintf(fd, "\t\t\t\"field_of_view\": %f,\n", m->s.camera[i].fov);
		dprintf(fd, "\t\t},\n");
		i++;
	}
	dprintf(fd, "\t]\n}");
}

void	save_as_file(t_main *m)
{
	const char	*save;
	const char	*format[1] = { "*.rt" };
	int			fd;

	save = tinyfd_saveFileDialog("", "example.rt", 1, format, NULL);
	if (save == NULL)
		return ;
	(void)m;
	fd = open(save, O_RDWR | O_TRUNC | O_CREAT, 0644);
	save_function(fd, m);
	close(fd);
	/*
	tinyfd_messageBox(
			"Error",
			"Not yet! We need JSON SAVE US function!",
			"ok",
			"error",
			1);
			*/
	/*
	** save JSON code here
	*/
}
