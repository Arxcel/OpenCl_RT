/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:15:31 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 17:43:52 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

float				ft_deg2rad(float deg)
{
	return (deg * M_PI / 180);
}

int					flush_effects(t_ae *ae)
{
	int				i;

	i = -1;
	while (++i < 15)
		ae->effects[i] = -1;
	return (1);
}

static void			add_effect(t_ae *ae, int val)
{
	int				i;

	i = 0;
	while (ae->effects[i] != -1 && i < 15)
		i++;
	if (i < 15 && val >= 0 && val <= 5)
		ae->effects[i] = val;
}

void				make_dependencies(t_main *m)
{
	int				i;

	i = -1;
	m->ae.h = &m->sdl.img.h;
	m->ae.w = &m->sdl.img.w;
	m->ae.pixels = &m->sdl.img.pixels;
	flush_effects(&m->ae);
}

void				filter_key(int key, t_main *m)
{
	if (key == SDLK_KP_1)
		add_effect(&m->ae, 0);
	else if (key == SDLK_KP_2)
		add_effect(&m->ae, 1);
	else if (key == SDLK_KP_3)
		add_effect(&m->ae, 2);
	else if (key == SDLK_KP_4)
		add_effect(&m->ae, 3);
	else if (key == SDLK_KP_5)
		add_effect(&m->ae, 4);
	else if (key == SDLK_KP_6)
		add_effect(&m->ae, 5);
	else if (m->ae.after_effect && (key == SDLK_KP_PLUS || key == SDLK_KP_MINUS))
		m->ae.coeficient = key == SDLK_KP_PLUS ?
			m->ae.coeficient + 30 : m->ae.coeficient - 30;
	else if (key == SDLK_KP_0 && (m->ae.coeficient = 1))
		flush_effects(&m->ae);
	else if (key == SDLK_KP_MULTIPLY && (m->sdl.changes = 1))
		m->ae.after_effect ^= 1;
	if (m->ae.after_effect & 1)
		m->sdl.changes = 1;
}
