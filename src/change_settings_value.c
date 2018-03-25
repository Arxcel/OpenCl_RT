/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_settings_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:07:00 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 17:09:16 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

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
