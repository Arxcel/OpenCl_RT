/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:41:28 by anestor           #+#    #+#             */
/*   Updated: 2018/03/24 19:38:06 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	render_scene_and_ui(t_main *m)
{
	m->ui.scene_place = sdl_rect(R_SCENE_X, R_SCENE_Y,
												m->sdl.img.h, m->sdl.img.w);
	m->ui.bg[BACKGROUND].rect = sdl_rect(0, 0, m->sdl.win_h, m->sdl.win_w);
	SDL_RenderCopy(m->sdl.ren, m->ui.bg[BACKGROUND].textr,
						NULL, &m->ui.bg[BACKGROUND].rect);
	SDL_UpdateTexture(m->sdl.texture, NULL,
			m->sdl.img.pixels, m->sdl.img.w * sizeof(unsigned int));
	//sdl_clear_image(&m->sdl.img);
	SDL_RenderCopy(m->sdl.ren, m->sdl.texture, NULL, &m->ui.scene_place);
	render_copy_background(m);
	render_copy_buttons(m);
	render_copy_rbutton(m);
	render_copy_scroll(m);
	render_copy_list(m);
	render_copy_settings(m);
	SDL_RenderPresent(m->sdl.ren);
}

void	ui_and_sdl_init(t_main *m)
{
	m->cl.work_dim[0] = WIN_W - R_SCENE_W_TRIM;
	m->cl.work_dim[1] = WIN_H - R_SCENE_H_TRIM;
	m->sdl.win_w = WIN_W;
	m->sdl.win_h = WIN_H;
	sdl_rinit(&m->sdl);
	sdl_recreate_img(&m->sdl.img, m->sdl.win_w - R_SCENE_W_TRIM,
									m->sdl.win_h - R_SCENE_H_TRIM);
	SDL_DestroyTexture(m->sdl.texture);
	m->sdl.texture = SDL_CreateTexture(m->sdl.ren,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STATIC,
								m->sdl.win_w - R_SCENE_W_TRIM,
								m->sdl.win_h - R_SCENE_H_TRIM);
	ui_textures_init(&m->ui, &m->sdl);
	ui_buttons_init(&m->ui, &m->sdl);
	ui_scroll_init(&m->ui, &m->sdl);
	ui_settings_init(&m->ui, &m->sdl);
	SDL_SetWindowMinimumSize(m->sdl.win, 800, 670);
}

void	window_resized_event(t_main *m)
{
	m->sdl.win_w = m->sdl.e.window.data1;
	m->sdl.win_h = m->sdl.e.window.data2;
	m->cl.work_dim[0] = m->sdl.win_w - R_SCENE_W_TRIM;
	m->cl.work_dim[1] = m->sdl.win_h - R_SCENE_H_TRIM;
	sdl_recreate_img(&m->sdl.img, m->sdl.win_w - R_SCENE_W_TRIM,
									m->sdl.win_h - R_SCENE_H_TRIM);
	SDL_DestroyTexture(m->sdl.texture);
	m->sdl.texture = SDL_CreateTexture(m->sdl.ren,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STATIC,
								m->sdl.win_w - R_SCENE_W_TRIM,
								m->sdl.win_h - R_SCENE_H_TRIM);
	m->sdl.changes = 1;
	m->ui.scroll.first_step = 0;
}
