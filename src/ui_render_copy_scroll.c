/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_scroll.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:09:02 by anestor           #+#    #+#             */
/*   Updated: 2018/03/23 17:15:45 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_scroll_rect_pre(t_main *m, int *start, int *l, int *l_b)
{
	int		y;
	int		l2;
	int		point_h;

	y = R_SCENE_Y + RBTN_H + 5;
	*l = m->sdl.win_h - R_SCENE_H_TRIM - RBTN_H - 5 - SCRL_SZ;
	if (m->ui.rbtn.status == 0)
	{
		l2 = (m->s.o_num - 1) * L_TEXT_H;
		m->ui.scroll.steps = m->s.o_num - 1;
	}
	else if (m->ui.rbtn.status == 1)
	{
		l2 = (m->s.l_num - 1) * L_TEXT_H;
		m->ui.scroll.steps = m->s.l_num - 1;
	}
	else
	{
		l2 = (m->s.c_num - 1) * L_TEXT_H;
		m->ui.scroll.steps = m->s.c_num - 1;
	}
	*l_b = *l;
	point_h = *l / m->ui.scroll.steps;
	*start = y + m->ui.scroll.first_step * point_h;
	if (l2 > *l)
	{
		*l = (double)((double)(*l - *l % L_TEXT_H) / l2) * *l;
		*l += (*l_b - *l) % point_h;
	}
	if (m->ui.scroll.steps > *l_b / L_TEXT_H)
		m->ui.scroll.visible_steps = *l_b / L_TEXT_H;
	else
		m->ui.scroll.visible_steps = m->ui.scroll.steps;
	m->ui.scroll.possible_steps = *l_b / L_TEXT_H;
}

static void	ui_scroll_rect_params(t_main *m)
{
	int		start;
	int		l;
	int		l_b;
	int		y;

	y = R_SCENE_Y + RBTN_H + 5;
	ui_scroll_rect_pre(m, &start, &l, &l_b);
	m->ui.scroll.r1.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, start, SCRL_SZ, SCRL_SZ);
	m->ui.scroll.r2.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, start + l, SCRL_SZ, SCRL_SZ);
	m->ui.scroll.line.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, start + SCRL_SZ / 2, l, SCRL_SZ);
	m->ui.scroll.b_r1.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, y, SCRL_SZ, SCRL_SZ);
	m->ui.scroll.b_r2.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, y + l_b, SCRL_SZ, SCRL_SZ);
	m->ui.scroll.b_line.rect =
		sdl_rect(L_FRAME_W - SCRL_SZ / 2 - 1, y + SCRL_SZ / 2, l_b, SCRL_SZ);
}

void		render_copy_scroll(t_main *m)
{
	ui_scroll_rect_params(m);
	SDL_RenderCopy(m->sdl.ren, m->ui.scroll.b_r1.textr,
								NULL, &m->ui.scroll.b_r1.rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.scroll.b_r2.textr,
								NULL, &m->ui.scroll.b_r2.rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.scroll.b_line.textr,
								NULL, &m->ui.scroll.b_line.rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.scroll.r1.textr,
								NULL, &m->ui.scroll.r1.rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.scroll.r2.textr,
								NULL, &m->ui.scroll.r2.rect);
	SDL_RenderCopy(m->sdl.ren, m->ui.scroll.line.textr,
								NULL, &m->ui.scroll.line.rect);
}
