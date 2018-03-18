/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:37:12 by anestor           #+#    #+#             */
/*   Updated: 2018/03/18 15:39:00 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UI_H
# define FT_UI_H
# define R_SCENE_X 218
# define R_SCENE_Y 85
# define R_SCENE_H_TRIM 90
# define R_SCENE_W_TRIM 400
# define L_FRAME_X 5
# define L_FRAME_Y 85
# define L_FRAME_W 208
# define R_FRAME_W 172
# define CRN_SZ 6

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_ui_tex
{
	SDL_Rect	rect;
	SDL_Texture	*textr;
}				t_ui_tex;

typedef struct	s_back_tex
{
	t_ui_tex	bg;
	t_ui_tex	l_frm;
	t_ui_tex	r_frm;
	t_ui_tex	lt_cor;
	t_ui_tex	lb_cor;
	t_ui_tex	rt_cor;
	t_ui_tex	rb_cor;
	t_ui_tex	bl_dot;
	t_ui_tex	dg_dot;
	t_ui_tex	lg_dot;
	t_ui_tex	co_dot;
}				t_back_tex;

typedef	struct	s_ui
{
	SDL_Rect	scene_place;
	t_back_tex	back;
}				t_ui;

void	ui_textures_init(t_ui *ui, t_sdl *sdl);
void	ui_rect_params(t_ui *ui, t_sdl *sdl);
void	ui_render_corners(t_ui *ui, t_sdl *sdl, SDL_Rect place);
void	ui_render_lines(t_ui *ui, t_sdl *sdl);

/*
** move to libftSDL
*/

SDL_Rect	sdl_rect(int x, int y, int h, int w);
SDL_Texture	*sdl_texture_from_file(char *filename, SDL_Renderer *renderer);
void		sdl_recreate_img(t_img *img, size_t w, size_t h);

#endif
