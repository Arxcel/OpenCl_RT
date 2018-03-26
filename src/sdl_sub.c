/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:56:20 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 20:12:45 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void		sdl_recreate_img(t_img *img, size_t w, size_t h)
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

int			xy_in_rect(int x, int y, SDL_Rect rect)
{
	x = x * RTN;
	y = y * RTN;
	if (x >= rect.x && y >= rect.y &&
			x <= rect.x + rect.w && y <= rect.y + rect.h)
		return (1);
	return (0);
}

SDL_Color	sdl_text_color(t_main *m, int i)
{
	SDL_Color	temp;

	if (m->ui.list.active == i + 1)
	{
		temp.r = 200;
		temp.g = 200;
		temp.b = 200;
	}
	else
	{
		temp.r = 30;
		temp.g = 30;
		temp.b = 30;
	}
	return (temp);
}
