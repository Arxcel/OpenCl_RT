/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:58:27 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 17:04:58 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

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

static void		cam_switch(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.btn[NEXT_CAM].rect)
								&& m->ui.btn[NEXT_CAM].status)
	{
		m->s.cam = (m->s.cam + 1) % (m->s.c_num - 1);
		re_draw(&m->cl, &m->sdl, &m->s);
		set_filter(&m->ae);
	}
	else if (xy_in_rect(x, y, m->ui.btn[PREV_CAM].rect)
								&& m->ui.btn[PREV_CAM].status)
	{
		if (m->s.cam > 0)
			m->s.cam -= 1;
		if (m->s.cam == 0)
			m->s.cam = m->s.c_num - 2;
		re_draw(&m->cl, &m->sdl, &m->s);
		set_filter(&m->ae);
	}
}

static void		effects_manip_sub(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.btn[BTN_PLUS].rect)
			&& m->ae.after_effect && m->ui.btn[BTN_PLUS].status)
		m->ae.coeficient += 30;
	else if (xy_in_rect(x, y, m->ui.btn[BTN_MINUS].rect)
			&& m->ae.coeficient && m->ui.btn[BTN_MINUS].status)
		m->ae.coeficient -= 30;
	else if (xy_in_rect(x, y, m->ui.btn[BTN_ZERO].rect)
			&& m->ui.btn[BTN_ZERO].status && (m->ae.coeficient = 1))
		flush_effects(&m->ae);
	else if (xy_in_rect(x, y, m->ui.btn[BTN_ONE].rect)
			&& m->ui.btn[BTN_ONE].status && (m->sdl.changes = 1))
		m->ae.after_effect ^= 1;
}

static void		effects_manipulation(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.btn[BTN_AE1].rect) && m->ui.btn[BTN_AE1].status)
		add_effect(&m->ae, 0);
	else if (xy_in_rect(x, y, m->ui.btn[BTN_AE2].rect)
								&& m->ui.btn[BTN_AE2].status)
		add_effect(&m->ae, 1);
	else if (xy_in_rect(x, y, m->ui.btn[BTN_AE3].rect)
								&& m->ui.btn[BTN_AE3].status)
		add_effect(&m->ae, 2);
	else if (xy_in_rect(x, y, m->ui.btn[BTN_AE4].rect)
								&& m->ui.btn[BTN_AE4].status)
		add_effect(&m->ae, 3);
	else if (xy_in_rect(x, y, m->ui.btn[BTN_AE5].rect)
								&& m->ui.btn[BTN_AE5].status)
		add_effect(&m->ae, 4);
	else if (xy_in_rect(x, y, m->ui.btn[BTN_AE6].rect)
								&& m->ui.btn[BTN_AE6].status)
		add_effect(&m->ae, 5);
	else
		effects_manip_sub(x, y, m);
	if (m->ae.after_effect & 1)
		m->sdl.changes = 1;
}

void			mouse_up(int x, int y, t_main *m)
{
	int		i;

	create_shapes(x, y, m);
	open_save_etc(x, y, m);
	effects_manipulation(x, y, m);
	cam_switch(x, y, m);
	i = -1;
	while (++i != BTNS)
		if (m->ui.btn[i].status == 1)
		{
			m->ui.btn[i].status = 0;
			render_scene_and_ui(m);
		}
}
