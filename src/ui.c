/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:41:28 by anestor           #+#    #+#             */
/*   Updated: 2018/03/15 22:29:02 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	render_scene_and_ui(t_main *m)
{
	t_img	tmp;

	re_draw(&m->cl, &m->sdl, &m->s);
	SDL_UpdateTexture(m->sdl.texture, &m->ui.scene_rect,
			m->sdl.img.pixels, m->sdl.img.w * sizeof(unsigned int));
	sdl_clear_image(&m->sdl.img);
	SDL_RenderCopy(m->sdl.ren, m->sdl.texture, NULL, NULL);	

	SDL_Texture *texture_test_2 = SDL_CreateTexture(m->sdl.ren,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STATIC,
								m->sdl.win_w, m->sdl.win_h);
	tmp = sdl_create_image(m->sdl.win_w, m->sdl.win_h);
//	ft_memset(tmp.pixels, 50, m->sdl.win_w * m->sdl.win_h * sizeof(unsigned int));
//	SDL_UpdateTexture(m->sdl.texture, &m->ui.frame_rect,	
//			tmp.pixels, m->sdl.win_w * sizeof(unsigned int));
//	ft_memdel((void **)&tmp.pixels);

	t_xy	i;
	i.y = 0;
	while (i.y != m->sdl.win_h)
	{
		i.x = 0;
		while (i.x != m->sdl.win_w)
		{
			if (!(i.y > 100 && i.x > 100 && i.y < m->sdl.win_h - 100 && i.x < m->sdl.win_w - 100))
				sdl_pixel_put(&tmp, i.x, i.y, 0x000000FF);
			i.x++;
		}
		i.y++;
	}
	//SDL_UpdateTexture(m->sdl.texture, &m->ui.frame_rect,
	//		tmp.pixels, m->sdl.win_w * sizeof(unsigned int));
	SDL_UpdateTexture(texture_test_2, &m->ui.frame_rect,
			tmp.pixels, m->sdl.win_w * sizeof(unsigned int));
	ft_memdel((void **)&tmp.pixels);

	SDL_Surface *img_test = IMG_Load("test.png");
	SDL_Texture *texture_test = SDL_CreateTextureFromSurface(m->sdl.ren, img_test);
	SDL_RenderCopy(m->sdl.ren, texture_test, NULL, NULL);

	//SDL_RenderCopy(m->sdl.ren, texture_test_2, NULL, NULL);
	//SDL_RenderCopy(m->sdl.ren, m->sdl.texture, NULL, NULL);
	SDL_RenderPresent(m->sdl.ren);
}

void	test_draw_square(t_img *img, int x, int y, int color)
{
	t_xy	i;

	i.y = 0;
	while (i.y != y)
	{
		i.x = 0;
		while (i.x != x)
		{
			sdl_pixel_put(img, i.x, i.y, color);
			i.x++;
		}
		i.y++;
	}
}

void	sdl_recreate_img(t_img *img, size_t w, size_t h)
{
	ft_memdel((void**)&img->pixels);
	*img = sdl_create_image(w, h);
}

void	window_resized_event(t_main *m)
{
	m->sdl.win_w = m->sdl.e.window.data1;
	m->sdl.win_h = m->sdl.e.window.data2;
	m->cl.work_dim[0] = m->sdl.win_w - R_SCENE_W_TRIM;
	m->cl.work_dim[1] = m->sdl.win_h - R_SCENE_H_TRIM;
	sdl_recreate_img(&m->sdl.img, m->sdl.win_w - R_SCENE_W_TRIM,
									m->sdl.win_h - R_SCENE_H_TRIM);
	SDL_DestroyTexture(m->sdl.texture);
	m->sdl.texture = SDL_CreateTexture(m->sdl.ren,
								SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STATIC,
								m->sdl.win_w,
								m->sdl.win_h);
	ui_rect_params(&m->ui, &m->sdl);
	m->sdl.changes = 1;
}

void	ui_rect_params(t_ui *ui, t_sdl *sdl)
{
	ui->frame_rect.x = 0;
	ui->frame_rect.y = 0;
	ui->frame_rect.h = sdl->win_h;
	ui->frame_rect.w = sdl->win_w;
	ui->scene_rect.x = R_SCENE_X;
	ui->scene_rect.y = R_SCENE_Y;
	ui->scene_rect.h = sdl->img.h;
	ui->scene_rect.w = sdl->img.w;
}
/*
** move to libftSDL
*/

void	sdl_put_image_rect(t_sdl *sdl, t_img *img, SDL_Rect *src, SDL_Rect *dst)
{
	SDL_UpdateTexture(sdl->texture, NULL,
			img->pixels, img->w * sizeof(unsigned int));
	sdl_clear_image(img);
	SDL_RenderCopy(sdl->ren, sdl->texture, src, dst);
	//SDL_RenderPresent(sdl->ren);
}
