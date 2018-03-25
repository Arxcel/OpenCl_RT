/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:57:48 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 01:05:46 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static char	*make_text(t_main *m, int i)
{
	char	*text;

	text = ft_strnew(20);
	if (m->ui.rbtn.status == 0)
	{
		(m->s.object[i].type == 1) ? ft_memcpy(text, "sphere", 6) : 0;
		(m->s.object[i].type == 2) ? ft_memcpy(text, "conus", 5) : 0;
		(m->s.object[i].type == 3) ? ft_memcpy(text, "plane", 5) : 0;
		(m->s.object[i].type == 4) ? ft_memcpy(text, "cylinder", 8) : 0;
		(m->s.object[i].type == 5) ? ft_memcpy(text, "disk", 4) : 0;
		(m->s.object[i].type == 6) ? ft_memcpy(text, "triangle", 8) : 0;
		(m->s.object[i].type == 7) ? ft_memcpy(text, "paraboloid", 10) : 0;
		(m->s.object[i].type == 8) ? ft_memcpy(text, "squere", 6) : 0;
	}
	else if (m->ui.rbtn.status == 1)
	{
		(m->s.light[i].type == 1) ? ft_memcpy(text, "parallel", 8) : 0;
		(m->s.light[i].type == 2) ? ft_memcpy(text, "lamp", 4) : 0;
		(m->s.light[i].type == 3) ? ft_memcpy(text, "ambient", 7) : 0;
		(m->s.light[i].type == 4) ? ft_memcpy(text, "area", 4) : 0;
	}
	else
		(m->s.camera[i].type == 1) ? ft_memcpy(text, "common", 6) : 0;
	return (text);
}

static char	*add_text_id(char *text, int i)
{
	char	*id;

	id = ft_itoa(i + 1);
	ft_strcat(text, " | id: ");
	ft_strcat(text, id);
	ft_memdel((void **)&id);
	return (text);
}

static SDL_Color	sdl_color(t_main *m, int i)
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

static void	make_and_put_text(t_main *m, int x, int y, int i)
{
	SDL_Texture	*texture;
	SDL_Surface	*surface;
	TTF_Font	*font;
	SDL_Rect	rect;
	char		*text;

	TTF_Init();
	font = TTF_OpenFont("open-sans/OpenSans-Regular.ttf", 40);
	if (font == NULL)
		return ;
	text = make_text(m, i);
	if (i == 0 && m->ui.rbtn.status == 2)
		ft_memcpy(text, "main cam", 8);
	text = add_text_id(text, i);
	surface = TTF_RenderText_Solid(font, text, sdl_color(m, i));
	ft_memdel((void **)&text);
	rect = sdl_rect(x, y, surface->h / 2, surface->w / 2);
	texture = SDL_CreateTextureFromSurface(m->sdl.ren, surface);
	SDL_RenderCopy(m->sdl.ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	TTF_Quit();
}

void		render_copy_list(t_main *m)
{
	int		i;
	m->ui.list.rect = sdl_rect(15, 160,
			m->ui.scroll.steps * L_TEXT_H, L_FRAME_W - L_TEXT_H);
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
		make_and_put_text(m, 15, 160 + (i - k) * L_TEXT_H, i);
		i++;
	}
}
