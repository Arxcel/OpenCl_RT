/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:50:56 by anestor           #+#    #+#             */
/*   Updated: 2018/03/22 16:56:12 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void		rbtn_status(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.rbtn.a.rect))
	{
		m->ui.rbtn.status = 0;
		m->ui.scroll.first_step = 0;
		render_scene_and_ui(m);
	}
	else if (xy_in_rect(x, y, m->ui.rbtn.b.rect))
	{
		m->ui.rbtn.status = 1;
		m->ui.scroll.first_step = 0;
		render_scene_and_ui(m);
	}
	else if (xy_in_rect(x, y, m->ui.rbtn.c.rect))
	{
		m->ui.rbtn.status = 2;
		m->ui.scroll.first_step = 0;
		render_scene_and_ui(m);
	}
}

static void		scroll_move(int x, int y, t_main *m)
{
	m->ui.scroll.first_step += (y * RTN - m->ui.scroll.line.rect.y)
																/ L_TEXT_H;
	if (m->ui.scroll.first_step < 0)
		m->ui.scroll.first_step = 0;
	if (m->ui.scroll.first_step > m->ui.scroll.steps - m->ui.scroll.line_steps)
		m->ui.scroll.first_step = m->ui.scroll.steps - m->ui.scroll.line_steps;
	render_scene_and_ui(m);
}

void			mouse_down(int x, int y, t_main *m)
{
	int		i;

	i = 0;
	while (i != BTNS)
	{
		if (xy_in_rect(x, y, m->ui.btn[i].rect))
		{
			m->ui.btn[i].status = 1;
			render_scene_and_ui(m);
		}
		i++;
	}
	rbtn_status(x, y, m);
	if (xy_in_rect(x, y, m->ui.scroll.b_line.rect))
		scroll_move(x, y, m);
}

static void		open_save_etc(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.btn[OPEN].rect)
								&& m->ui.btn[OPEN].status)
		open_file(m);
	else if (xy_in_rect(x, y, m->ui.btn[SAVE].rect)
								&& m->ui.btn[SAVE].status)
		save_file(m);
	else if (xy_in_rect(x, y, m->ui.btn[SAVE_AS].rect)
								&& m->ui.btn[SAVE_AS].status)
		save_as_file(m);
	else if (xy_in_rect(x, y, m->ui.btn[EXPORT].rect)
								&& m->ui.btn[EXPORT].status)
		export_file(m);
}

void			mouse_up(int x, int y, t_main *m)
{
	int		i;

	open_save_etc(x, y, m);
	i = -1;
	while (++i != BTNS)
		if (m->ui.btn[i].status == 1)
		{
			m->ui.btn[i].status = 0;
			render_scene_and_ui(m);
		}
}
