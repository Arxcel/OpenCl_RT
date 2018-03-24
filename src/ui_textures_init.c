/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_textures_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:02:44 by anestor           #+#    #+#             */
/*   Updated: 2018/03/23 21:16:13 by anestor          ###   ########.fr       */
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

void	ui_settings_init(t_ui *ui, t_sdl *sdl)
{
	texture_from_text("Color RED:", sdl, &ui->o_set[E_COL_R].name);
	texture_from_text("Color GREEN:", sdl, &ui->o_set[E_COL_G].name);
	texture_from_text("Color BLUE:", sdl, &ui->o_set[E_COL_B].name);
	texture_from_text("Dir X:", sdl, &ui->o_set[E_DIR_X].name);
	texture_from_text("Dir Y:", sdl, &ui->o_set[E_DIR_Y].name);
	texture_from_text("Dir Z:", sdl, &ui->o_set[E_DIR_Z].name);
	texture_from_text("Pos1 X:", sdl, &ui->o_set[E_POS1_X].name);
	texture_from_text("Pos1 Y:", sdl, &ui->o_set[E_POS1_Y].name);
	texture_from_text("Pos1 Z:", sdl, &ui->o_set[E_POS1_Z].name);
	texture_from_text("Pos2 X:", sdl, &ui->o_set[E_POS2_X].name);
	texture_from_text("Pos2 Y:", sdl, &ui->o_set[E_POS2_Y].name);
	texture_from_text("Pos2 Z:", sdl, &ui->o_set[E_POS2_Z].name);
	texture_from_text("Pos3 X:", sdl, &ui->o_set[E_POS3_X].name);
	texture_from_text("Pos3 Y:", sdl, &ui->o_set[E_POS3_Y].name);
	texture_from_text("Pos3 Z:", sdl, &ui->o_set[E_POS3_Z].name);
}

/*
static SDL_Texture	*texture_from_text(char *text, t_sdl *sdl)
{
	SDL_Texture	*texture;
	SDL_Surface	*surface;
	SDL_Color	color;
	TTF_Font	*font;

	TTF_Init();
	font = TTF_OpenFont("open-sans/OpenSans-Regular.ttf", 15);
	if (font == NULL)
		return (NULL);
	color.r = 200;
	color.g = 200;
	color.b = 200;
	surface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(sdl->ren, surface);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
	TTF_Quit();
	return (texture);
}

void	ui_settings_init(t_ui *ui, t_sdl *sdl)
{
	ui->o_set[COL_R].name.textr =
		texture_from_text("Color RED        ", sdl);
	ui->o_set[COL_G].name.textr =
		texture_from_text("Color GREEN      ", sdl);
	ui->o_set[COL_B].name.textr =
		texture_from_text("Color BLUE       ", sdl);
}
*/
