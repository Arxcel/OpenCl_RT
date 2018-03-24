/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_textures_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:02:44 by anestor           #+#    #+#             */
/*   Updated: 2018/03/24 19:17:19 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

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

void	ui_scroll_init(t_ui *ui, t_sdl *sdl)
{
	ui->scroll.r1.textr =
		sdl_texture_from_file("textures/contrast_disk.png", sdl->ren);
	ui->scroll.r2.textr = ui->scroll.r1.textr;
	ui->scroll.line.textr =
		sdl_texture_from_file("textures/contrast_dot.png", sdl->ren);
	ui->scroll.b_r1.textr =
		sdl_texture_from_file("textures/black_disk.png", sdl->ren);
	ui->scroll.b_r2.textr = ui->scroll.b_r1.textr;
	ui->scroll.b_line.textr =
		sdl_texture_from_file("textures/black_dot.png", sdl->ren);
}

void		texture_from_text(char *text, t_sdl *sdl, t_ui_bg *p) //move from here
{
	SDL_Surface	*surface;
	SDL_Color	color;
	TTF_Font	*font;

	TTF_Init();
	font = TTF_OpenFont("open-sans/OpenSans-Regular.ttf", 25);
	if (font == NULL)
		return ;
	color.r = 200;
	color.g = 200;
	color.b = 200;
	surface = TTF_RenderText_Solid(font, text, color);
	p->rect = sdl_rect(0, 0, surface->h / 2, surface->w / 2);
	p->textr = SDL_CreateTextureFromSurface(sdl->ren, surface);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
	TTF_Quit();
}
