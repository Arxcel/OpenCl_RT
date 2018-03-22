/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:41:28 by anestor           #+#    #+#             */
/*   Updated: 2018/03/22 16:57:30 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void		sdl_put_text(char *text, int x, int y, t_sdl *sdl)
{
	SDL_Texture	*texture;
	SDL_Surface	*surface;
	TTF_Font	*font;
	SDL_Color	color;
	SDL_Rect	rect;

	TTF_Init();
	font = TTF_OpenFont("open-sans/OpenSans-Regular.ttf", 40);
	color.r = 30;
	color.g = 30;
	color.b = 30;
	if (font == NULL)
		return ;
	surface = TTF_RenderText_Solid(font, text, color);
	rect.w = surface->w;
	rect.h = surface->h;
	rect.x = x;
	rect.y = y;
	printf("rect.h %d\n", rect.h);
	texture = SDL_CreateTextureFromSurface(sdl->ren, surface);
	SDL_RenderCopy(sdl->ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	TTF_Quit();
}

void	render_scene_and_ui(t_main *m)
{
	m->ui.scene_place = sdl_rect(R_SCENE_X, R_SCENE_Y,
												m->sdl.img.h, m->sdl.img.w);
	m->ui.bg[BACKGROUND].rect = sdl_rect(0, 0, m->sdl.win_h, m->sdl.win_w);
	SDL_RenderCopy(m->sdl.ren, m->ui.bg[BACKGROUND].textr,
						NULL, &m->ui.bg[BACKGROUND].rect);
	set_filter(m);
	SDL_UpdateTexture(m->sdl.texture, NULL,
			m->sdl.img.pixels, m->sdl.img.w * sizeof(unsigned int));
	//sdl_clear_image(&m->sdl.img);
	SDL_RenderCopy(m->sdl.ren, m->sdl.texture, NULL, &m->ui.scene_place);
	render_copy_background(m);
	render_copy_buttons(m);
	render_copy_rbutton(m);
	render_copy_scroll(m);
	render_copy_list(m);
	for (int i = 0; i != m->s.o_num; i++)
	{
		sdl_put_text(ft_strjoin("elem #", ft_itoa(i + 1)), 50, 310 + i * 60, &m->sdl);
	}
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
	SDL_SetWindowMinimumSize(m->sdl.win, 800, 600);
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
}
