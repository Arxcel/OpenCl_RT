/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_background.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:08:30 by anestor           #+#    #+#             */
/*   Updated: 2018/03/28 11:28:57 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_bg_rect_params(t_ui *ui, t_sdl *sdl)
{
	ui->bg[LEFT_FRAME].rect = sdl_rect(5, R_SCENE_Y + RBTN_H + 5,
				sdl->win_h - R_SCENE_Y - 5 - RBTN_H - 5, L_FRAME_W);
	ui->bg[RIGHT_FRAME].rect = sdl_rect(sdl->win_w - R_FRAME_W - 5,
				R_SCENE_Y, sdl->win_h - R_SCENE_Y - 5, R_FRAME_W);
	ui->bg[LOGO].rect = sdl_rect(sdl->win_w - (LOGO_W + 10),
				5, LOGO_H, LOGO_W);
	ui->bg[SET_1].rect = sdl_rect(sdl->win_w - R_FRAME_W, L_FRAME_Y + 5,
				40, 160);
	ui->bg[SET_2].rect = sdl_rect(sdl->win_w - R_FRAME_W, L_FRAME_Y + 5,
				40, 160);
	ui->bg[SET_3].rect = sdl_rect(sdl->win_w - R_FRAME_W, L_FRAME_Y + 5,
				40, 160);
}

void		render_copy_background(t_main *m)
{
	ui_bg_rect_params(&m->ui, &m->sdl);
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
