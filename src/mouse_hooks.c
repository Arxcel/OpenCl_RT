/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:50:56 by anestor           #+#    #+#             */
/*   Updated: 2018/03/18 22:52:25 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void			mouse_down(int x, int y, t_main *m)
{
	if (x > 10 && x < 50 && y > 10 & y < 50)
		m->ui.btn[OPEN].status = 1;
	else if (x > 60 && y > 10 && x < 100 && y < 50)
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
	if (x > 10 && x < 50 && y > 10 & y < 50)
		open_file(m);
	else if (x > 60 && y > 10 && x < 100 && y < 50)
		export_file(m);
}
