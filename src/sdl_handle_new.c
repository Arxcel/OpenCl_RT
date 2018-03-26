/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_handle_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:52:43 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/26 12:53:56 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void				mouse_scene_rot(int x, int y, t_main *m)
{
	if (m->ui.scene_status)
	{
		if (y < (int)(R_SCENE_Y + m->sdl.img.h / 2))
			m->s.cam_trans.rot[0] += 2.5;
		else
			m->s.cam_trans.rot[0] -= 2.5;
		if (x < (int)(R_SCENE_X + m->sdl.img.w / 2))
			m->s.cam_trans.rot[1] += 2.5;
		else
			m->s.cam_trans.rot[1] -= 2.5;
		m->sdl.changes = 1;
	}
}
