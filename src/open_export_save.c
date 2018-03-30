/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_export_save.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:10:10 by anestor           #+#    #+#             */
/*   Updated: 2018/03/29 17:13:03 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	open_file(t_main *m)
{
	const char	*open;
	const char	*format[2] = { "*.rt", "*.json" };

	open = tinyfd_openFileDialog("", "", 2, format, NULL, 0);
	if (open == NULL)
		return ;
	delete_scene(&m->s);
	m->ui.scroll.first_step = 0;
	m->ui.list.active = 0;
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
	re_draw(&m->cl, &m->sdl, &m->s);
	surface = SDL_CreateRGBSurface(0, m->sdl.img.w, m->sdl.img.h,
															32, 0, 0, 0, 0);
	ft_memcpy(surface->pixels, m->sdl.img.pixels, surface->h * surface->pitch);
	IMG_SavePNG(surface, export);
	SDL_FreeSurface(surface);
}

void	save_as_file(t_main *m)
{
	const char	*save;
	const char	*format[1] = { "*.json" };
	int			fd;

	save = tinyfd_saveFileDialog("", "example.json", 1, format, NULL);
	if (save == NULL)
		return ;
	fd = open(save, O_RDWR | O_TRUNC | O_CREAT, 0644);
	save_function(fd, m);
	close(fd);
}
