/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:01:54 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/29 17:10:38 by vkozlov          ###   ########.fr       */
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
	else if (key == SDLK_SPACE)
	{
		m->s.cam_trans.pos = (t_vector){0, 0, 4};
		m->s.cam_trans.rot = (t_vector){0, 0, 0};
	}
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
				|| key == SDLK_q || key == SDLK_e || key == SDLK_SPACE)
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
}

void				sdl_loop(t_main *m)
{
	while (m->sdl.running)
	{
		sdl_hook(m);
		if (m->sdl.changes)
		{
			re_draw(&m->cl, &m->sdl, &m->s);
			render_scene_and_ui(m);
			m->sdl.changes = 0;
		}
	}
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
			scroll_move(m->sdl.e.motion.y, m);
		else if (m->sdl.e.type == SDL_MOUSEWHEEL)
			scroll_move_whell(m->sdl.e.wheel.y, m);
	}
}
