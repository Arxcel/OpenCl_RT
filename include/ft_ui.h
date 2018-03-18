/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:37:12 by anestor           #+#    #+#             */
/*   Updated: 2018/03/18 21:11:25 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UI_H
# define FT_UI_H
# define BG_ITEMS 11
# define BTNS 2
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

typedef struct	s_ui_bg
{
	SDL_Rect	rect;
	SDL_Texture	*textr;
}				t_ui_bg;

typedef struct	s_ui_btn
{
	SDL_Rect	rect;
	SDL_Texture	*on;
	SDL_Texture	*off;
	int			status;
}				t_ui_btn;

typedef	struct	s_ui
{
	SDL_Rect	scene_place;
	t_ui_bg		bg[BG_ITEMS];
	t_ui_btn	btn[BTNS];
}				t_ui;

enum			e_bg
{
	BACKGROUND = 0,
	LEFT_FRAME = 1,
	RIGHT_FRAME = 2,
	LT_CORNER = 3,
	LB_CORNER = 4,
	RT_CORNER = 5,
	RB_CORNER = 6,
	BL_DOT = 7,
	DG_DOT = 8,
	LG_DOT = 9,
	CO_DOT = 10
};

enum			e_btns
{
	OPEN = 0,
	EXPORT = 1
};

void			ui_buttons_init(t_ui *ui, t_sdl *sdl);
void			ui_textures_init(t_ui *ui, t_sdl *sdl);
void			ui_bg_rect_params(t_ui *ui, t_sdl *sdl);
void			ui_btn_rect_params(t_ui *ui, t_sdl *sdl);
void			ui_render_corners(t_ui *ui, t_sdl *sdl, SDL_Rect place);
void			ui_render_lines(t_ui *ui, t_sdl *sdl);

/*
** move to libftSDL
*/

SDL_Rect		sdl_rect(int x, int y, int h, int w);
SDL_Texture		*sdl_texture_from_file(char *filename, SDL_Renderer *renderer);
void			sdl_recreate_img(t_img *img, size_t w, size_t h);

#endif
