/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:58:27 by anestor           #+#    #+#             */
/*   Updated: 2018/03/29 17:12:09 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void		open_save_etc(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.btn[OPEN].rect)
								&& m->ui.btn[OPEN].status)
		open_file(m);
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
		m->s.cam++;
		if (m->s.cam >= m->s.c_num - 2)
			m->s.cam = m->s.c_num - 2;
		re_draw(&m->cl, &m->sdl, &m->s);
	}
	else if (xy_in_rect(x, y, m->ui.btn[PREV_CAM].rect)
								&& m->ui.btn[PREV_CAM].status)
	{
		m->s.cam--;
		if (m->s.cam <= 0)
			m->s.cam = 0;
		re_draw(&m->cl, &m->sdl, &m->s);
	}
}

void			mouse_up(int x, int y, t_main *m)
{
	int		i;

	create_shapes(x, y, m);
	open_save_etc(x, y, m);
	cam_switch(x, y, m);
	i = -1;
	while (++i != BTNS)
		if (m->ui.btn[i].status == 1)
		{
			m->ui.btn[i].status = 0;
			render_scene_and_ui(m);
		}
	m->ui.scroll.status = 0;
	m->ui.scene_status = 0;
}
