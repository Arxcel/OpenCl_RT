/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:01:54 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/26 02:50:26 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void			pos_camera(int key, t_main *m)
{
	if (key == SDLK_w)
		m->s.cam_trans.pos[2] -= 0.3512;
	else if (key == SDLK_s)
		m->s.cam_trans.pos[2] += 0.3512;
	else if (key == SDLK_a)
		m->s.cam_trans.pos[0] -= 0.3512;
	else if (key == SDLK_d)
		m->s.cam_trans.pos[0] += 0.3512;
	else if (key == SDLK_q)
		m->s.cam_trans.pos[1] += 0.3512;
	else if (key == SDLK_e)
		m->s.cam_trans.pos[1] -= 0.3512;
}

static void			rot_camera(int key, t_main *m)
{
	if (key == SDLK_i)
		m->s.cam_trans.rot[0] += 5;
	else if (key == SDLK_k)
		m->s.cam_trans.rot[0] -= 5;
	else if (key == SDLK_j)
		m->s.cam_trans.rot[1] += 5;
	else if (key == SDLK_l)
		m->s.cam_trans.rot[1] -= 5;
	else if (key == SDLK_u)
		m->s.cam_trans.rot[2] += 5;
	else if (key == SDLK_o)
		m->s.cam_trans.rot[2] -= 5;
}

static void			key_down(int key, t_main *m)
{
	if (key == SDLK_ESCAPE)
		m->sdl.running = 0;
	else if (key == SDLK_w || key == SDLK_s || key == SDLK_a || key == SDLK_d
				|| key == SDLK_q || key == SDLK_e)
	{
		pos_camera(key, m);
		m->sdl.changes = 1;
	}
	else if (key == SDLK_i || key == SDLK_k || key == SDLK_j || key == SDLK_l
				|| key == SDLK_u || key == SDLK_o)
	{
		rot_camera(key, m);
		m->sdl.changes = 1;
	}
	else if (key == SDLK_z)
	{
		open_file(m);
	}
	else if (key == SDLK_KP_1 || key == SDLK_KP_2 || key == SDLK_KP_3 ||
		key == SDLK_KP_4 || key == SDLK_KP_5 || key == SDLK_KP_6 ||
		key == SDLK_KP_PLUS || key == SDLK_KP_MINUS || key == SDLK_KP_MULTIPLY
			|| key == SDLK_KP_0)
		filter_key(key, m);
}

void				sdl_loop(t_main *m)
{
	while (m->sdl.running)
	{
		sdl_hook(m);
		if (m->sdl.changes)
		{
			re_draw(&m->cl, &m->sdl, &m->s);
			set_filter(&m->ae);
			render_scene_and_ui(m);
			m->sdl.changes = 0;
		}
	}
}

static void		scroll_move(int x, int y, t_main *m)
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

static void		scroll_move_whell(int x, int y, t_main *m)
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

void				sdl_hook(t_main *m)
{
	while (SDL_PollEvent(&m->sdl.e) != 0)
	{
		if (m->sdl.e.type == SDL_QUIT)
			m->sdl.running = 0;
		else if (m->sdl.e.type == SDL_WINDOWEVENT)
		{
			if (m->sdl.e.window.event == SDL_WINDOWEVENT_RESIZED)
				window_resized_event(m);
		}
		else if (m->sdl.e.type == SDL_KEYDOWN)
			key_down(m->sdl.e.key.keysym.sym, m);
		else if (m->sdl.e.type == SDL_MOUSEBUTTONDOWN)
			mouse_down(m->sdl.e.button.x, m->sdl.e.button.y, m);
		else if (m->sdl.e.type == SDL_MOUSEBUTTONUP)
			mouse_up(m->sdl.e.button.x, m->sdl.e.button.y, m);
		else if (m->sdl.e.type == SDL_MOUSEMOTION)
			scroll_move(m->sdl.e.motion.x, m->sdl.e.motion.y, m);
		else if (m->sdl.e.type == SDL_MOUSEWHEEL)
			scroll_move_whell(m->sdl.e.wheel.x, m->sdl.e.wheel.y, m);
	}
}
