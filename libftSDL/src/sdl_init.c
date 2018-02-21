/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:42:04 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/21 19:00:40 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void				sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
		MSG(SDL_GetError());
	if (!(sdl->win = SDL_CreateWindow("My SDL", SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED, sdl->win_w,
								sdl->win_h, SDL_WINDOW_SHOWN)))
		MSG(SDL_GetError());
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		MSG(SDL_GetError());
	if (!(sdl->texture = SDL_CreateTexture(sdl->ren,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STREAMING,
								sdl->win_w, sdl->win_h)))
		MSG(SDL_GetError());
	SDL_SetRenderDrawColor(sdl->ren, 0, 0, 0, 0xFF);
	SDL_RenderClear(sdl->ren);
	SDL_RenderPresent(sdl->ren);
	sdl->img = sdl_create_image(sdl->win_w, sdl->win_h);
	sdl->running = 1;
}
