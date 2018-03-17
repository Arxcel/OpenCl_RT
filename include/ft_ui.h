/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:37:12 by anestor           #+#    #+#             */
/*   Updated: 2018/03/15 22:30:43 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UI_H
# define FT_UI_H
# define R_SCENE_X 220
# define R_SCENE_Y 87
# define R_SCENE_H_TRIM 90
# define R_SCENE_W_TRIM 400

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef	struct	s_ui
{
	t_img		img;
	SDL_Rect	scene_rect;
	SDL_Rect	frame_rect;
}				t_ui;


//void	test_draw_square(t_img *img, int x, int y, int color);


void	ui_rect_params(t_ui *ui, t_sdl *sdl);

//void	window_resized_event(t_main *m);

/*
** move to libftSDL
*/

void	sdl_recreate_img(t_img *img, size_t w, size_t h);
void	sdl_put_image_rect(t_sdl *sdl, t_img *img, SDL_Rect *src, SDL_Rect *dst);

#endif
