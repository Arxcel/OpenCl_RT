/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:50:56 by anestor           #+#    #+#             */
/*   Updated: 2018/03/23 17:28:52 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void		rbtn_status(int x, int y, t_main *m)
{
	if (xy_in_rect(x, y, m->ui.rbtn.a.rect))
	{
		m->ui.rbtn.status = 0;
		m->ui.scroll.first_step = 0;
		m->ui.list.active = 0;
		render_scene_and_ui(m);
	}
	else if (xy_in_rect(x, y, m->ui.rbtn.b.rect))
	{
		m->ui.rbtn.status = 1;
		m->ui.scroll.first_step = 0;
		m->ui.list.active = 0;
		render_scene_and_ui(m);
	}
	else if (xy_in_rect(x, y, m->ui.rbtn.c.rect))
	{
		m->ui.rbtn.status = 2;
		m->ui.scroll.first_step = 0;
		m->ui.list.active = 0;
		render_scene_and_ui(m);
	}
}

static void		scroll_move(int x, int y, t_main *m)
{
	m->ui.scroll.first_step += (y * RTN - m->ui.scroll.line.rect.y)
																/ L_TEXT_H;
	if (m->ui.scroll.first_step > m->ui.scroll.steps -
								m->ui.scroll.possible_steps)
		m->ui.scroll.first_step = m->ui.scroll.steps -
								m->ui.scroll.possible_steps;
	if (m->ui.scroll.first_step < 0)
		m->ui.scroll.first_step = 0;
	render_scene_and_ui(m);
}

static void		choose_list_elem(int x, int y, t_main *m)
{
	int			i;
	SDL_Rect	rect;

	i = 0;
	while (i != m->ui.list.n)
	{
		rect.x = m->ui.list.rect.x;
		rect.y = m->ui.list.rect.y + i * L_TEXT_H * 2 + 10;
		rect.w = m->ui.list.rect.w;
		rect.h = m->ui.list.rect.h / m->ui.list.n;
		if (xy_in_rect(x, y, rect))
		{
			m->ui.list.active = i + 1 + m->ui.scroll.first_step;
			if (m->ui.list.active > m->ui.list.n)
				m->ui.list.active = 0;
			render_scene_and_ui(m);
			return ;
		}
		i++;
	}
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
	if (xy_in_rect(x, y, m->ui.list.rect))
		choose_list_elem(x, y, m);
	i = 0;
	while (i != O_SET)
	{
		if (xy_in_rect(x, y, m->ui.o_set[i].data.rect))
		{
			const char	*tmp;

			tmp = tinyfd_inputBox("", "Input value (dont work)", "");
			/*
			if (tmp != NULL)
			{
				m->s.object[m->ui.list.active].color[0] = atof(tmp);
				re_draw(&m->cl, &m->sdl, &m->s);
				set_filter(&m->ae);
				render_scene_and_ui(m);
			}
			*/
		}
		i++;
	}
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
