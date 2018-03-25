/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:50:56 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 01:09:51 by anestor          ###   ########.fr       */
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

void			check_o_settings_min_max_values(t_main *m, int i)
{
	if (m->ui.o_set[0].p[0] < 0)
		m->ui.o_set[0].p[0] = 0;
	if (m->ui.o_set[0].p[1] < 0)
		m->ui.o_set[0].p[1] = 0;
	if (m->ui.o_set[0].p[2] < 0)
		m->ui.o_set[0].p[2] = 0;
	if (m->ui.o_set[0].p[0] > 1)
		m->ui.o_set[0].p[0] = 1;
	if (m->ui.o_set[0].p[1] > 1)
		m->ui.o_set[0].p[1] = 1;
	if (m->ui.o_set[0].p[2] > 1)
		m->ui.o_set[0].p[2] = 1;
	if (*m->ui.o_set[E_REFL].p < 0)
	   *m->ui.o_set[E_REFL].p = 0;
	if (*m->ui.o_set[E_REFL].p > 1)
	   *m->ui.o_set[E_REFL].p = 1;
	if (*m->ui.o_set[E_REFR].p < 0)
	   *m->ui.o_set[E_REFR].p = 0;
	if (*m->ui.o_set[E_REFR].p > 1)
	   *m->ui.o_set[E_REFR].p = 1;
	if (*m->ui.o_set[E_TEX_ID].usp < 0)
	   *m->ui.o_set[E_TEX_ID].usp = 0;
	if (*m->ui.o_set[E_TEX_ID].usp > 9)
	   *m->ui.o_set[E_TEX_ID].usp = 9;
}

void			change_o_settings_value(t_main *m, int i)
{
	const char	*tmp;

	tmp = tinyfd_inputBox("", "Input value", "0");
	if (tmp != NULL)
	{
		if (i == 0 || i == 3 || i == 6 || i == 9 || i == 12)
			m->ui.o_set[i].p[0] = atof(tmp);
		else if (i == 1 || i == 4 || i == 7 || i == 10 || i == 13)
			m->ui.o_set[i].p[1] = atof(tmp);
		else if (i == 2 || i == 5 || i == 8 || i == 11 || i == 14)
			m->ui.o_set[i].p[2] = atof(tmp);
		else if (i >= 15 && i < 21)
			*m->ui.o_set[i].p = atof(tmp);
		else if (i >= 21 && i < 24)
			*m->ui.o_set[i].usp = ft_atoi(tmp);
		else if (i == 24)
			*m->ui.o_set[i].sp = ft_atoi(tmp);
		check_o_settings_min_max_values(m, i);
		re_draw(&m->cl, &m->sdl, &m->s);
		set_filter(&m->ae);
		render_scene_and_ui(m);
	}
}

void			check_l_settings_min_max_values(t_main *m, int i)
{
	if (m->ui.l_set[0].p[0] < 0)
		m->ui.l_set[0].p[0] = 0;
	if (m->ui.l_set[0].p[1] < 0)
		m->ui.l_set[0].p[1] = 0;
	if (m->ui.l_set[0].p[2] < 0)
		m->ui.l_set[0].p[2] = 0;
	if (m->ui.l_set[0].p[0] > 1)
		m->ui.l_set[0].p[0] = 1;
	if (m->ui.l_set[0].p[1] > 1)
		m->ui.l_set[0].p[1] = 1;
	if (m->ui.l_set[0].p[2] > 1)
		m->ui.l_set[0].p[2] = 1;
}

void			change_l_settings_value(t_main *m, int i)
{
	const char	*tmp;

	tmp = tinyfd_inputBox("", "Input value", "0");
	if (tmp != NULL)
	{
		if (i == 0 || i == 3 || i == 6 || i == 9)
			m->ui.l_set[i].p[0] = atof(tmp);
		else if (i == 1 || i == 4 || i == 7 || i == 10)
			m->ui.l_set[i].p[1] = atof(tmp);
		else if (i == 2 || i == 5 || i == 8 || i == 11)
			m->ui.l_set[i].p[2] = atof(tmp);
		else if (i >= 12 && i < 14)
			*m->ui.l_set[i].p = atof(tmp);
		check_l_settings_min_max_values(m, i);
		re_draw(&m->cl, &m->sdl, &m->s);
		set_filter(&m->ae);
		render_scene_and_ui(m);
	}
}

void			change_c_settings_value(t_main *m, int i)
{
	const char	*tmp;

	tmp = tinyfd_inputBox("", "Input value", "0");
	if (tmp != NULL)
	{
		if (i == 0 || i == 3 || i == 6)
			m->ui.c_set[i].p[0] = atof(tmp);
		else if (i == 1 || i == 4 || i == 7)
			m->ui.c_set[i].p[1] = atof(tmp);
		else if (i == 2 || i == 5 || i == 8)
			m->ui.c_set[i].p[2] = atof(tmp);
		else if (i == 9)
			*m->ui.c_set[i].p = atof(tmp);
		re_draw(&m->cl, &m->sdl, &m->s);
		set_filter(&m->ae);
		render_scene_and_ui(m);
	}
}

void			change_settings_value(int x, int y, t_main *m)
{
	int		i;

	i = 0;
	if (m->ui.rbtn.status == 0)
		while (i != O_SET)
		{
			if (xy_in_rect(x, y, m->ui.o_set[i].data.rect))
				change_o_settings_value(m, i);
			i++;
		}
	else if (m->ui.rbtn.status == 1)
		while (i != LI_SET)
		{
			if (xy_in_rect(x, y, m->ui.l_set[i].data.rect))
				change_l_settings_value(m, i);
			i++;
		}
	else if (m->ui.rbtn.status == 2)
		while (i != CA_SET)
		{
			if (xy_in_rect(x, y, m->ui.c_set[i].data.rect))
				change_c_settings_value(m, i);
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
	change_settings_value(x, y, m);
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
}
