/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:50:56 by anestor           #+#    #+#             */
/*   Updated: 2018/03/19 15:36:18 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void			mouse_down(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.btn[OPEN].rect))
		m->ui.btn[OPEN].status = 1;
	else if (xy_in_rect(x, y, m->ui.btn[SAVE].rect))
		m->ui.btn[SAVE].status = 1;
	else if (xy_in_rect(x, y, m->ui.btn[SAVE_AS].rect))
		m->ui.btn[SAVE_AS].status = 1;
	else if (xy_in_rect(x, y, m->ui.btn[EXPORT].rect))
		m->ui.btn[EXPORT].status = 1;
	render_scene_and_ui(m);
}

void			mouse_up(int x, int y, t_main *m)
{
	int		i;

	i = 0;
	while (i != BTNS)
		m->ui.btn[i++].status = 0;
	render_scene_and_ui(m);
	if (xy_in_rect(x, y, m->ui.btn[OPEN].rect))
		open_file(m);
	else if (xy_in_rect(x, y, m->ui.btn[SAVE].rect))
		save_file(m);
	else if (xy_in_rect(x, y, m->ui.btn[SAVE_AS].rect))
		save_as_file(m);
	else if (xy_in_rect(x, y, m->ui.btn[EXPORT].rect))
		export_file(m);
}
