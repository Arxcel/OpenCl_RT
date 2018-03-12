/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:20:15 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/12 14:20:51 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	move_camera(t_scene *s)
{
	s->camera->pos = s->cam_base.pos + s->cam_trans.pos;
	s->camera->rot = s->cam_base.rot + s->cam_trans.rot;
}
