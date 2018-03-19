/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:41:28 by anestor           #+#    #+#             */
/*   Updated: 2018/03/19 16:21:20 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	render_scene_and_ui(t_main *m)
{
	SDL_RenderCopy(m->sdl.ren, m->ui.back.bg.textr, NULL, &m->ui.back.bg.rect);
	re_draw(&m->cl, &m->sdl, &m->s);
	set_filter(m);
	SDL_UpdateTexture(m->sdl.texture, NULL,
			m->sdl.img.pixels, m->sdl.img.w * sizeof(unsigned int));
	sdl_clear_image(&m->sdl.img);
	SDL_RenderCopy(m->sdl.ren, m->sdl.texture, NULL, &m->ui.scene_place);
	SDL_RenderCopy(m->sdl.ren, m->ui.back.l_frm.textr, NULL, &m->ui.back.l_frm.rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.back.r_frm.textr, NULL, &m->ui.back.r_frm.rect);
	ui_render_corners(&m->ui, &m->sdl, m->ui.scene_place);
	ui_render_corners(&m->ui, &m->sdl, m->ui.back.l_frm.rect);
	ui_render_corners(&m->ui, &m->sdl, m->ui.back.r_frm.rect);
	ui_render_lines(&m->ui, &m->sdl);
	SDL_RenderPresent(m->sdl.ren);
}

void	sdl_recreate_img(t_img *img, size_t w, size_t h)
{
	ft_memdel((void**)&img->pixels);
	*img = sdl_create_image(w, h);
}

void	ui_and_sdl_init(t_main *m)
{
	m->cl.work_dim[0] = WIN_W - R_SCENE_W_TRIM;
	m->cl.work_dim[1] = WIN_H - R_SCENE_H_TRIM;
	m->sdl.win_w = WIN_W;
	m->sdl.win_h = WIN_H;
	m->after_effect = AE_SEPIA;
	sdl_init(&m->sdl);
	sdl_recreate_img(&m->sdl.img, m->sdl.win_w - R_SCENE_W_TRIM, m->sdl.win_h - R_SCENE_H_TRIM);
	SDL_DestroyTexture(m->sdl.texture);
	m->sdl.texture = SDL_CreateTexture(m->sdl.ren,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STATIC,
								m->sdl.win_w - R_SCENE_W_TRIM,
								m->sdl.win_h - R_SCENE_H_TRIM);
	ui_rect_params(&m->ui, &m->sdl);
	ui_textures_init(&m->ui, &m->sdl);
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
	ui_rect_params(&m->ui, &m->sdl);
	m->sdl.changes = 1;
}

void	ui_rect_params(t_ui *ui, t_sdl *sdl)
{
	ui->scene_place = sdl_rect(R_SCENE_X, R_SCENE_Y, sdl->img.h, sdl->img.w);
	ui->back.bg.rect = sdl_rect(0, 0, sdl->win_h, sdl->win_w);
	ui->back.l_frm.rect = sdl_rect(5, R_SCENE_Y,
				sdl->win_h - R_SCENE_Y - 5, L_FRAME_W);
	ui->back.r_frm.rect = sdl_rect(sdl->win_w - R_FRAME_W - 5, R_SCENE_Y,
				sdl->win_h - R_SCENE_Y - 5, R_FRAME_W);
}

static void	ui_corner_rect_params(t_ui *ui, SDL_Rect place)
{
	ui->back.lt_cor.rect =
		sdl_rect(place.x, place.y, CRN_SZ, CRN_SZ);
	ui->back.lb_cor.rect =
		sdl_rect(place.x, place.y + place.h - CRN_SZ, CRN_SZ, CRN_SZ);
	ui->back.rt_cor.rect =
		sdl_rect(place.x + place.w - CRN_SZ, place.y, CRN_SZ, CRN_SZ);
	ui->back.rb_cor.rect =
		sdl_rect(place.x + place.w - CRN_SZ, place.y + place.h - CRN_SZ,
														CRN_SZ, CRN_SZ);
}

void	ui_render_corners(t_ui *ui, t_sdl *sdl, SDL_Rect place)
{
	ui_corner_rect_params(ui, place);
	SDL_RenderCopy(sdl->ren, ui->back.lt_cor.textr,
							NULL, &ui->back.lt_cor.rect);
	SDL_RenderCopy(sdl->ren, ui->back.lb_cor.textr,
							NULL, &ui->back.lb_cor.rect);
	SDL_RenderCopy(sdl->ren, ui->back.rt_cor.textr,
							NULL, &ui->back.rt_cor.rect);
	SDL_RenderCopy(sdl->ren, ui->back.rb_cor.textr,
							NULL, &ui->back.rb_cor.rect);
}

static void ui_lines_rect_params(t_ui *ui, t_sdl *sdl)
{
	ui->back.bl_dot.rect =
		sdl_rect(L_FRAME_X + 5, L_FRAME_Y + 45, 1, L_FRAME_W - 10);
	ui->back.lg_dot.rect =
		sdl_rect(sdl->win_w - R_FRAME_W, L_FRAME_Y + 45, 1, R_FRAME_W - 10);
	ui->back.co_dot.rect =
		sdl_rect(5, R_SCENE_Y - 5, 1, sdl->win_w - 10);
}

void	ui_render_lines(t_ui *ui, t_sdl *sdl)
{
	ui_lines_rect_params(ui, sdl);
	SDL_RenderCopy(sdl->ren, ui->back.bl_dot.textr,
							NULL, &ui->back.bl_dot.rect);
	SDL_RenderCopy(sdl->ren, ui->back.lg_dot.textr,
							NULL, &ui->back.lg_dot.rect);
	SDL_RenderCopy(sdl->ren, ui->back.co_dot.textr,
							NULL, &ui->back.co_dot.rect);
}

/*
** move to libftSDL
*/

SDL_Rect	sdl_rect(int x, int y, int h, int w)
{
	SDL_Rect	tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.h = h;
	tmp.w = w;
	return (tmp);
}

SDL_Texture	*sdl_texture_from_file(char *filename, SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	SDL_Texture	*tmp;

	surface = IMG_Load(filename);
	tmp = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return (tmp);
}

void	ui_textures_init(t_ui *ui, t_sdl *sdl)
{
	ui->back.bg.textr =
		sdl_texture_from_file("textures/background.png", sdl->ren);
	ui->back.l_frm.textr =
		sdl_texture_from_file("textures/left_frame.png", sdl->ren);
	ui->back.r_frm.textr =
		sdl_texture_from_file("textures/right_frame.png", sdl->ren);
	ui->back.lt_cor.textr =
		sdl_texture_from_file("textures/left_top_corner.png", sdl->ren);
	ui->back.lb_cor.textr =
		sdl_texture_from_file("textures/left_bot_corner.png", sdl->ren);
	ui->back.rt_cor.textr =
		sdl_texture_from_file("textures/right_top_corner.png", sdl->ren);
	ui->back.rb_cor.textr =
		sdl_texture_from_file("textures/right_bot_corner.png", sdl->ren);
	ui->back.bl_dot.textr =
		sdl_texture_from_file("textures/black_dot.png", sdl->ren);
	ui->back.dg_dot.textr =
		sdl_texture_from_file("textures/dark_grey_dot.png", sdl->ren);
	ui->back.lg_dot.textr =
		sdl_texture_from_file("textures/light_grey_dot.png", sdl->ren);
	ui->back.co_dot.textr =
		sdl_texture_from_file("textures/contrast_dot.png", sdl->ren);
}
