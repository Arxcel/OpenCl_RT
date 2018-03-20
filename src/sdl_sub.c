/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:56:20 by anestor           #+#    #+#             */
/*   Updated: 2018/03/20 00:25:48 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	sdl_recreate_img(t_img *img, size_t w, size_t h)
{
	ft_memdel((void**)&img->pixels);
	*img = sdl_create_image(w, h);
}

SDL_Rect	sdl_rect(int x, int y, int h, int w)
{
	SDL_Rect	tmp;

	tmp.x = x * RTN;
	tmp.y = y * RTN;
	tmp.h = h * RTN;
	tmp.w = w * RTN;
	return (tmp);
}

SDL_Texture	*sdl_texture_from_file(char *filename, SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	SDL_Texture	*tmp;

	surface = IMG_Load(filename);
	tmp = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return (tmp);
}

int		xy_in_rect(int x, int y, SDL_Rect rect)
{
	x = x * RTN;
	y = y * RTN;
	if (x >= rect.x && y >= rect.y &&
			x <= rect.x + rect.w && y <= rect.y + rect.h)
		return (1);
	return (0);
}
