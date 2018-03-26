/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings_min_max_values.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:23:31 by anestor           #+#    #+#             */
/*   Updated: 2018/03/26 15:47:46 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	check_o_set_sub(t_main *m)
{
	int		i;

	i = 3;
	while (i != 15)
	{
		(m->ui.o_set[i].p[0] < -5000) ? m->ui.o_set[i].p[0] = -5000 : 0;
		(m->ui.o_set[i].p[1] < -5000) ? m->ui.o_set[i].p[1] = -5000 : 0;
		(m->ui.o_set[i].p[2] < -5000) ? m->ui.o_set[i].p[2] = -5000 : 0;
		(m->ui.o_set[i].p[0] > 5000) ? m->ui.o_set[i].p[0] = 5000 : 0;
		(m->ui.o_set[i].p[1] > 5000) ? m->ui.o_set[i].p[1] = 5000 : 0;
		(m->ui.o_set[i].p[2] > 5000) ? m->ui.o_set[i].p[2] = 5000 : 0;
		i = i + 3;
	}
	(*m->ui.o_set[E_SPECUL].usp < 0) ? *m->ui.o_set[E_SPECUL].usp = 0 : 0;
	(*m->ui.o_set[E_SPECUL].usp > 15000)
		? *m->ui.o_set[E_SPECUL].usp = 15000 : 0;
	(*m->ui.o_set[E_TEX_SCL].usp < 0) ? *m->ui.o_set[E_TEX_SCL].usp = 0 : 0;
	(*m->ui.o_set[E_TEX_SCL].usp > 1000)
		? *m->ui.o_set[E_TEX_SCL].usp = 1000 : 0;
	(*m->ui.o_set[E_TEX_ANG].sp < 0) ? *m->ui.o_set[E_TEX_ANG].sp = 0 : 0;
	(*m->ui.o_set[E_TEX_ANG].sp > 360)
		? *m->ui.o_set[E_TEX_ANG].sp = 360 : 0;
}

void		check_o_settings_min_max_values(t_main *m)
{
	(m->ui.o_set[0].p[0] < 0) ? m->ui.o_set[0].p[0] = 0 : 0;
	(m->ui.o_set[0].p[1] < 0) ? m->ui.o_set[0].p[1] = 0 : 0;
	(m->ui.o_set[0].p[2] < 0) ? m->ui.o_set[0].p[2] = 0 : 0;
	(m->ui.o_set[0].p[0] > 1) ? m->ui.o_set[0].p[0] = 1 : 0;
	(m->ui.o_set[0].p[1] > 1) ? m->ui.o_set[0].p[1] = 1 : 0;
	(m->ui.o_set[0].p[2] > 1) ? m->ui.o_set[0].p[2] = 1 : 0;
	(*m->ui.o_set[E_REFL].p < 0) ? *m->ui.o_set[E_REFL].p = 0 : 0;
	(*m->ui.o_set[E_REFL].p > 1) ? *m->ui.o_set[E_REFL].p = 1 : 0;
	(*m->ui.o_set[E_REFR].p < 0) ? *m->ui.o_set[E_REFR].p = 0 : 0;
	(*m->ui.o_set[E_REFR].p > 1) ? *m->ui.o_set[E_REFR].p = 1 : 0;
	(*m->ui.o_set[E_TEX_ID].usp < 0) ? *m->ui.o_set[E_TEX_ID].usp = 0 : 0;
	(*m->ui.o_set[E_TEX_ID].usp > 9) ? *m->ui.o_set[E_TEX_ID].usp = 9 : 0;
	(*m->ui.o_set[E_MIN].p < -5000) ? *m->ui.o_set[E_MIN].p = -5000 : 0;
	(*m->ui.o_set[E_MIN].p > 5000) ? *m->ui.o_set[E_MIN].p = 5000 : 0;
	(*m->ui.o_set[E_MAX].p < -5000) ? *m->ui.o_set[E_MAX].p = -5000 : 0;
	(*m->ui.o_set[E_MAX].p > 5000) ? *m->ui.o_set[E_MAX].p = 5000 : 0;
	(*m->ui.o_set[E_RAD].p < -1000) ? *m->ui.o_set[E_RAD].p = -1000 : 0;
	(*m->ui.o_set[E_RAD].p > 1000) ? *m->ui.o_set[E_RAD].p = 1000 : 0;
	(*m->ui.o_set[E_IOR].p < 0.5) ? *m->ui.o_set[E_IOR].p = 0.5 : 0;
	(*m->ui.o_set[E_IOR].p > 2) ? *m->ui.o_set[E_IOR].p = 2 : 0;
	(*m->ui.o_set[E_ANGL].p < 0) ? *m->ui.o_set[E_ANGL].p = 0 : 0;
	(*m->ui.o_set[E_ANGL].p > 360) ? *m->ui.o_set[E_ANGL].p = 360 : 0;
	check_o_set_sub(m);
}

void		check_l_settings_min_max_values(t_main *m)
{
	int		i;

	(m->ui.l_set[0].p[0] < 0) ? m->ui.l_set[0].p[0] = 0 : 0;
	(m->ui.l_set[0].p[1] < 0) ? m->ui.l_set[0].p[1] = 0 : 0;
	(m->ui.l_set[0].p[2] < 0) ? m->ui.l_set[0].p[2] = 0 : 0;
	(m->ui.l_set[0].p[0] > 1) ? m->ui.l_set[0].p[0] = 1 : 0;
	(m->ui.l_set[0].p[1] > 1) ? m->ui.l_set[0].p[1] = 1 : 0;
	(m->ui.l_set[0].p[2] > 1) ? m->ui.l_set[0].p[2] = 1 : 0;
	i = 3;
	while (i != 12)
	{
		(m->ui.l_set[i].p[0] < -5000) ? m->ui.l_set[i].p[0] = -5000 : 0;
		(m->ui.l_set[i].p[1] < -5000) ? m->ui.l_set[i].p[1] = -5000 : 0;
		(m->ui.l_set[i].p[2] < -5000) ? m->ui.l_set[i].p[2] = -5000 : 0;
		(m->ui.l_set[i].p[0] > 5000) ? m->ui.l_set[i].p[0] = 5000 : 0;
		(m->ui.l_set[i].p[1] > 5000) ? m->ui.l_set[i].p[1] = 5000 : 0;
		(m->ui.l_set[i].p[2] > 5000) ? m->ui.l_set[i].p[2] = 5000 : 0;
		i = i + 3;
	}
	(*m->ui.l_set[E_LINTENCE].p < 0) ? *m->ui.l_set[E_LINTENCE].p = 0 : 0;
	(*m->ui.l_set[E_LINTENCE].p > 100) ? *m->ui.l_set[E_LINTENCE].p = 100 : 0;
	(*m->ui.l_set[E_LANGLE].p < 0) ? *m->ui.l_set[E_LANGLE].p = 0 : 0;
	(*m->ui.l_set[E_LANGLE].p > 360) ? *m->ui.l_set[E_LANGLE].p = 360 : 0;
}

void		check_c_settings_min_max_values(t_main *m)
{
	int		i;

	i = 0;
	while (i != 9)
	{
		(m->ui.c_set[i].p[0] < -5000) ? m->ui.c_set[i].p[0] = -5000 : 0;
		(m->ui.c_set[i].p[1] < -5000) ? m->ui.c_set[i].p[1] = -5000 : 0;
		(m->ui.c_set[i].p[2] < -5000) ? m->ui.c_set[i].p[2] = -5000 : 0;
		(m->ui.c_set[i].p[0] > 5000) ? m->ui.c_set[i].p[0] = 5000 : 0;
		(m->ui.c_set[i].p[1] > 5000) ? m->ui.c_set[i].p[1] = 5000 : 0;
		(m->ui.c_set[i].p[2] > 5000) ? m->ui.c_set[i].p[2] = 5000 : 0;
		i = i + 3;
	}
	(*m->ui.c_set[E_CFOV].p < 0) ? *m->ui.c_set[E_CFOV].p = 0 : 0;
	(*m->ui.c_set[E_CFOV].p > 150) ? *m->ui.c_set[E_CFOV].p = 150 : 0;
}
