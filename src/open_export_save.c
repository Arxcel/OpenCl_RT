/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_export_save.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:10:10 by anestor           #+#    #+#             */
/*   Updated: 2018/03/19 15:50:57 by anestor          ###   ########.fr       */
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
	sdl_clear_image(&m->sdl.img);
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

void	save_as_file(t_main *m)
{
	const char	*save;
	const char	*format[1] = { "*.rt" };

	save = tinyfd_saveFileDialog("", "example.rt", 1, format, NULL);
	if (save == NULL)
		return ;
	(void)m;
	tinyfd_messageBox(
			"Error",
			"Not yet! We need JSON SAVE US function!",
			"ok",
			"error",
			1);
	/*
	** save JSON code here
	*/
}
