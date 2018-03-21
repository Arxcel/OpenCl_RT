/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:41:28 by anestor           #+#    #+#             */
/*   Updated: 2018/03/20 23:35:07 by anestor          ###   ########.fr       */
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
	texture = SDL_CreateTextureFromSurface(sdl->ren, surface);
	SDL_RenderCopy(sdl->ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	TTF_Quit();
}

static void	pre_render_background(t_main *m)
{
	SDL_RenderCopy(m->sdl.ren, m->ui.bg[LEFT_FRAME].textr,
						NULL, &m->ui.bg[LEFT_FRAME].rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.bg[RIGHT_FRAME].textr,
						NULL, &m->ui.bg[RIGHT_FRAME].rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.bg[LOGO].textr,
						NULL, &m->ui.bg[LOGO].rect);
	ui_render_corners(&m->ui, &m->sdl, m->ui.scene_place);
	ui_render_corners(&m->ui, &m->sdl, m->ui.bg[LEFT_FRAME].rect);
	ui_render_corners(&m->ui, &m->sdl, m->ui.bg[RIGHT_FRAME].rect);
	ui_render_lines(&m->ui, &m->sdl);
}

static void pre_render_buttons(t_main *m)
{
	int		i;

	i = 0;
	while (i != BTNS)
	{
		if (m->ui.btn[i].status == 1)
		{
			SDL_RenderCopy(m->sdl.ren, m->ui.btn[i].on,
								NULL, &m->ui.btn[i].rect);
		}
		else
		{
			SDL_RenderCopy(m->sdl.ren, m->ui.btn[i].off,
								NULL, &m->ui.btn[i].rect);
		}
		i++;
	}
}

static void	pre_render_rbutton(t_main *m)
{
	if (m->ui.rbtn.status == 0)
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.rbtn.a.textr,
								NULL, &m->ui.rbtn.rect);
	}
	else if (m->ui.rbtn.status == 1)
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.rbtn.b.textr,
								NULL, &m->ui.rbtn.rect);
	}
	else
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.rbtn.c.textr,
								NULL, &m->ui.rbtn.rect);
	}
}

static void	pre_render_sliders(t_main *m)
{
	SDL_RenderCopy(m->sdl.ren, m->ui.sldr[L_SCROLL].r1.textr,
								NULL, &m->ui.sldr[L_SCROLL].r1.rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.sldr[L_SCROLL].r2.textr,
								NULL, &m->ui.sldr[L_SCROLL].r2.rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.sldr[L_SCROLL].line.textr,
								NULL, &m->ui.sldr[L_SCROLL].line.rect);
}

void	render_scene_and_ui(t_main *m)
{
	ui_bg_rect_params(&m->ui, &m->sdl);
	ui_btn_rect_params(&m->ui);
	ui_rbtn_rect_params(&m->ui);
	ui_sliders_rect_params(&m->ui, &m->sdl);
	SDL_RenderCopy(m->sdl.ren, m->ui.bg[BACKGROUND].textr,
						NULL, &m->ui.bg[BACKGROUND].rect);
	re_draw(&m->cl, &m->sdl, &m->s);
	SDL_UpdateTexture(m->sdl.texture, NULL,
			m->sdl.img.pixels, m->sdl.img.w * sizeof(unsigned int));
	sdl_clear_image(&m->sdl.img);
	SDL_RenderCopy(m->sdl.ren, m->sdl.texture, NULL, &m->ui.scene_place);
	pre_render_background(m);
	pre_render_buttons(m);
	pre_render_rbutton(m);
	pre_render_sliders(m);
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
//	ui_rect_params(&m->ui, &m->sdl);
	ui_textures_init(&m->ui, &m->sdl);
	ui_buttons_init(&m->ui, &m->sdl);
	ui_sliders_init(&m->ui, &m->sdl);
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
//	ui_rect_params(&m->ui, &m->sdl);
	m->sdl.changes = 1;
}

void	ui_sliders_rect_params(t_ui *ui, t_sdl *sdl)
{
	int		y;
	int		l;

	y = R_SCENE_Y + RBTN_H + 5;
	l = sdl->win_h - R_SCENE_H_TRIM - RBTN_H - 5 - SCRL_SZ;
	ui->sldr[L_SCROLL].r1.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, y, SCRL_SZ, SCRL_SZ);
	ui->sldr[L_SCROLL].r2.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, y + l, SCRL_SZ, SCRL_SZ);
	ui->sldr[L_SCROLL].line.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, y + SCRL_SZ / 2, l, SCRL_SZ);
}

void	ui_rbtn_rect_params(t_ui *ui)
{
	ui->rbtn.rect =
		sdl_rect(5, R_SCENE_Y, RBTN_H, L_FRAME_W);
	ui->rbtn.a.rect =
		sdl_rect(5, R_SCENE_Y, RBTN_H, L_FRAME_W / 3);
	ui->rbtn.b.rect =
		sdl_rect(5 + L_FRAME_W / 3, R_SCENE_Y, RBTN_H, L_FRAME_W / 3);
	ui->rbtn.c.rect =
		sdl_rect(5 + (L_FRAME_W / 3) * 2, R_SCENE_Y, RBTN_H, L_FRAME_W / 3);
}

void	ui_btn_rect_params(t_ui *ui)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = BTN_ROW1_X;
	y = BTN_ROW1_Y;
	while (i != BTNS)
	{
		ui->btn[i].rect = sdl_rect(x, y, BTN_SIZE, BTN_SIZE);
		x += BTN_ROW1_X + BTN_SIZE;
		i++;
		if (i == 4 || i == 14 || i == 15)
			x += 15;
		if (i == 6)
		{
			y += BTN_ROW1_Y + BTN_SIZE;
			x = BTN_ROW1_X;
		}
	}
}

void	ui_bg_rect_params(t_ui *ui, t_sdl *sdl)
{
	ui->scene_place = sdl_rect(R_SCENE_X, R_SCENE_Y, sdl->img.h, sdl->img.w);
	ui->bg[BACKGROUND].rect = sdl_rect(0, 0, sdl->win_h, sdl->win_w);
	ui->bg[LEFT_FRAME].rect = sdl_rect(5, R_SCENE_Y + RBTN_H + 5,
				sdl->win_h - R_SCENE_Y - 5 - RBTN_H - 5, L_FRAME_W);
	ui->bg[RIGHT_FRAME].rect = sdl_rect(sdl->win_w - R_FRAME_W - 5,
				R_SCENE_Y, sdl->win_h - R_SCENE_Y - 5, R_FRAME_W);
	ui->bg[LOGO].rect = sdl_rect(sdl->win_w - (LOGO_W + 10),
				5, LOGO_H, LOGO_W);
}

void	ui_textures_init(t_ui *ui, t_sdl *sdl)
{
	ui->bg[BACKGROUND].textr =
		sdl_texture_from_file("textures/background.png", sdl->ren);
	ui->bg[LEFT_FRAME].textr =
		sdl_texture_from_file("textures/left_frame.png", sdl->ren);
	ui->bg[RIGHT_FRAME].textr =
		sdl_texture_from_file("textures/right_frame.png", sdl->ren);
	ui->bg[LT_CORNER].textr =
		sdl_texture_from_file("textures/left_top_corner.png", sdl->ren);
	ui->bg[LB_CORNER].textr =
		sdl_texture_from_file("textures/left_bot_corner.png", sdl->ren);
	ui->bg[RT_CORNER].textr =
		sdl_texture_from_file("textures/right_top_corner.png", sdl->ren);
	ui->bg[RB_CORNER].textr =
		sdl_texture_from_file("textures/right_bot_corner.png", sdl->ren);
	ui->bg[BL_DOT].textr =
		sdl_texture_from_file("textures/black_dot.png", sdl->ren);
	ui->bg[DG_DOT].textr =
		sdl_texture_from_file("textures/dark_grey_dot.png", sdl->ren);
	ui->bg[LG_DOT].textr =
		sdl_texture_from_file("textures/light_grey_dot.png", sdl->ren);
	ui->bg[CO_DOT].textr =
		sdl_texture_from_file("textures/contrast_dot.png", sdl->ren);
	ui->bg[LOGO].textr =
		sdl_texture_from_file("textures/logo.png", sdl->ren);
}

void	ui_sliders_init(t_ui *ui, t_sdl *sdl)
{
	ui->sldr[L_SCROLL].r1.textr = 
		sdl_texture_from_file("textures/contrast_disk.png", sdl->ren);
	ui->sldr[L_SCROLL].r2.textr = 
		sdl_texture_from_file("textures/contrast_disk.png", sdl->ren);
	ui->sldr[L_SCROLL].line.textr = 
		sdl_texture_from_file("textures/contrast_dot.png", sdl->ren);
}
