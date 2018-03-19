/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 00:23:34 by anestor           #+#    #+#             */
/*   Updated: 2018/03/20 00:33:14 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"
#ifndef RETINA

void				sdl_rinit(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
		MSG(SDL_GetError());
	if (!(sdl->win = SDL_CreateWindow("My SDL", SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED, sdl->win_w,
								sdl->win_h, SDL_WINDOW_SHOWN
									| SDL_WINDOW_RESIZABLE)))
		MSG(SDL_GetError());
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		MSG(SDL_GetError());
	if (!(sdl->texture = SDL_CreateTexture(sdl->ren,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STATIC,
								sdl->win_w, sdl->win_h)))
		MSG(SDL_GetError());
	SDL_SetRenderDrawColor(sdl->ren, 255, 255, 255, 255);
	SDL_RenderClear(sdl->ren);
	SDL_RenderPresent(sdl->ren);
	sdl->img = sdl_create_image(sdl->win_w, sdl->win_h);
	sdl->running = 1;
}

#endif
#ifdef RETINA

void				sdl_rinit(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
		MSG(SDL_GetError());
	if (!(sdl->win = SDL_CreateWindow("My SDL", SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED, sdl->win_w,
								sdl->win_h, SDL_WINDOW_SHOWN
					| SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI)))
		MSG(SDL_GetError());
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		MSG(SDL_GetError());
	if (!(sdl->texture = SDL_CreateTexture(sdl->ren,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STATIC,
								sdl->win_w, sdl->win_h)))
		MSG(SDL_GetError());
	SDL_SetRenderDrawColor(sdl->ren, 255, 255, 255, 255);
	SDL_RenderClear(sdl->ren);
	SDL_RenderPresent(sdl->ren);
	sdl->img = sdl_create_image(sdl->win_w, sdl->win_h);
	sdl->running = 1;
}

#endif
