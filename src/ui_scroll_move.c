/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_scroll_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 02:59:34 by anestor           #+#    #+#             */
/*   Updated: 2018/03/26 03:01:52 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	scroll_move(int y, t_main *m)
{
	static int yy;

	if (m->ui.scroll.status)
	{
		if (yy < y)
		{
			m->ui.scroll.first_step += 1;
			yy = y;
		}
		else
		{
			m->ui.scroll.first_step -= 1;
			yy = y;
		}
		if (m->ui.scroll.first_step > m->ui.scroll.steps -
									m->ui.scroll.possible_steps)
			m->ui.scroll.first_step = m->ui.scroll.steps -
									m->ui.scroll.possible_steps;
		if (m->ui.scroll.first_step < 0)
			m->ui.scroll.first_step = 0;
		render_scene_and_ui(m);
	}
}

void	scroll_move_whell(int y, t_main *m)
{
	if (y > 0)
		m->ui.scroll.first_step -= 1;
	else
		m->ui.scroll.first_step += 1;
	if (m->ui.scroll.first_step > m->ui.scroll.steps -
								m->ui.scroll.possible_steps)
		m->ui.scroll.first_step = m->ui.scroll.steps -
								m->ui.scroll.possible_steps;
	if (m->ui.scroll.first_step < 0)
		m->ui.scroll.first_step = 0;
	render_scene_and_ui(m);
}
