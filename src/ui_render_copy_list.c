/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:57:48 by anestor           #+#    #+#             */
/*   Updated: 2018/03/22 18:54:28 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void		sdl_put_text(char *text, int x, int y, t_sdl *sdl)
{
	SDL_Texture	*texture;
	SDL_Surface	*surface;
	TTF_Font	*font;
	SDL_Color	color;
	SDL_Rect	rect;

	TTF_Init();
	font = TTF_OpenFont("open-sans/OpenSans-Regular.ttf", 40);
	color.r = 30;
	color.g = 30;
	color.b = 30;
	if (font == NULL)
		return ;
	surface = TTF_RenderText_Solid(font, text, color);
	rect.w = surface->w;
	rect.h = surface->h;
	rect.x = x;
	rect.y = y;
	printf("rect.h %d\n", rect.h);
	texture = SDL_CreateTextureFromSurface(sdl->ren, surface);
	SDL_RenderCopy(sdl->ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	TTF_Quit();
}

void		render_copy_list(t_main *m)
{
	int		i;
	m->ui.list.rect = sdl_rect(50, 320,
			m->ui.scroll.steps * L_TEXT_H, L_FRAME_W - 10);
	if (m->ui.rbtn.status == 0)
		m->ui.list.n = m->s.o_num;
	else if (m->ui.rbtn.status == 1)
		m->ui.list.n = m->s.l_num;
	else
		m->ui.list.n = m->s.c_num;
	int k = m->ui.scroll.first_step;
	i = k;
	while (i != m->ui.scroll.visible_steps + k)
	{
		sdl_put_text(ft_strjoin("elem #", ft_itoa(i + 1)), 50, 320 + (i - k) * 60, &m->sdl);
		i++;
	}
}
