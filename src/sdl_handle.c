/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:01:54 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/03 17:02:57 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void			key_down(int key, t_sdl *sdl)
{
	if (key == SDLK_ESCAPE)
		sdl->running = 0;
}

void				sdl_loop(t_sdl *sdl)
{
	while (sdl->running)
		sdl_hook(sdl);
}

void				sdl_hook(t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->e) != 0)
	{
		if (sdl->e.type == SDL_QUIT)
			sdl->running = 0;
		else if (sdl->e.type == SDL_KEYDOWN)
			key_down(sdl->e.key.keysym.sym, sdl);
	}
}