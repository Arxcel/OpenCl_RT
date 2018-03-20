/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_lines_and_corners.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:07:35 by anestor           #+#    #+#             */
/*   Updated: 2018/03/20 15:04:25 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_corner_rect_params(t_ui *ui, SDL_Rect place)
{
	ui->bg[LT_CORNER].rect =
		sdl_rect(place.x, place.y, CRN_SZ, CRN_SZ);
	ui->bg[LB_CORNER].rect =
		sdl_rect(place.x, place.y + place.h - CRN_SZ, CRN_SZ, CRN_SZ);
	ui->bg[RT_CORNER].rect =
		sdl_rect(place.x + place.w - CRN_SZ, place.y, CRN_SZ, CRN_SZ);
	ui->bg[RB_CORNER].rect =
		sdl_rect(place.x + place.w - CRN_SZ, place.y + place.h - CRN_SZ,
														CRN_SZ, CRN_SZ);
}

void		ui_render_corners(t_ui *ui, t_sdl *sdl, SDL_Rect place)
{
	ui_corner_rect_params(ui, place);
	SDL_RenderCopy(sdl->ren, ui->bg[LT_CORNER].textr,
							NULL, &ui->bg[LT_CORNER].rect);
	SDL_RenderCopy(sdl->ren, ui->bg[LB_CORNER].textr,
							NULL, &ui->bg[LB_CORNER].rect);
	SDL_RenderCopy(sdl->ren, ui->bg[RT_CORNER].textr,
							NULL, &ui->bg[RT_CORNER].rect);
	SDL_RenderCopy(sdl->ren, ui->bg[RB_CORNER].textr,
							NULL, &ui->bg[RB_CORNER].rect);
}

static void	ui_lines_rect_params(t_ui *ui, t_sdl *sdl)
{
	ui->bg[BL_DOT].rect =
		sdl_rect(L_FRAME_X + 5, L_FRAME_Y + 45, 1, L_FRAME_W - 10);
	ui->bg[LG_DOT].rect =
		sdl_rect(sdl->win_w - R_FRAME_W, L_FRAME_Y + 45, 1, R_FRAME_W - 10);
	ui->bg[DG_DOT].rect =
		sdl_rect(5, BTN_ROW1_Y + BTN_SIZE, 1, sdl->win_w  - LOGO_W - 25);
	ui->bg[CO_DOT].rect =
		sdl_rect(5, R_SCENE_Y - 5, 1, sdl->win_w - 10);
}

void		ui_render_lines(t_ui *ui, t_sdl *sdl)
{
	ui_lines_rect_params(ui, sdl);
	SDL_RenderCopy(sdl->ren, ui->bg[BL_DOT].textr,
							NULL, &ui->bg[BL_DOT].rect);
	SDL_RenderCopy(sdl->ren, ui->bg[LG_DOT].textr,
							NULL, &ui->bg[LG_DOT].rect);
	SDL_RenderCopy(sdl->ren, ui->bg[CO_DOT].textr,
							NULL, &ui->bg[CO_DOT].rect);
	SDL_RenderCopy(sdl->ren, ui->bg[DG_DOT].textr,
							NULL, &ui->bg[DG_DOT].rect);
}
