/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_rbutton.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:09:19 by anestor           #+#    #+#             */
/*   Updated: 2018/03/22 14:19:08 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_rbtn_rect_params(t_ui *ui)
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

void		render_copy_rbutton(t_main *m)
{
	ui_rbtn_rect_params(&m->ui);
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
