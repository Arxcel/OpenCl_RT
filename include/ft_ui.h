/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:37:12 by anestor           #+#    #+#             */
/*   Updated: 2018/03/23 16:22:55 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UI_H
# define FT_UI_H
# define RTN 2
# define BG_ITEMS 12
# define BTNS 18
# define SLDRS 1
# define R_SCENE_X 218
# define R_SCENE_Y 95
# define R_SCENE_H_TRIM 100
# define R_SCENE_W_TRIM 400
# define L_FRAME_X 5
# define L_FRAME_Y 95
# define L_FRAME_W 208
# define R_FRAME_W 172
# define CRN_SZ 6
# define SCRL_SZ 12
# define BTN_ROW1_Y 5
# define BTN_ROW1_X 3
# define BTN_SIZE 40
# define RBTN_H 45
# define LOGO_H 67
# define LOGO_W 130
# define L_TEXT_H 30
# define RAD(x) (x * M_PI / 180.0)
# define DEG(x) (x * 180.0 / M_PI)

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

typedef struct	s_ui_rbtn
{
	SDL_Rect	rect;
	t_ui_bg		a;
	t_ui_bg		b;
	t_ui_bg		c;
	int			status;
}				t_ui_rbtn;

typedef struct	s_ui_scrl
{
	t_ui_bg		r1;
	t_ui_bg		r2;
	t_ui_bg		line;
	t_ui_bg		b_r1;
	t_ui_bg		b_r2;
	t_ui_bg		b_line;
	int			steps;
	int			visible_steps;
	int			possible_steps;
	int			first_step;
}				t_ui_scrl;

typedef struct	s_ui_lst
{
	SDL_Rect	rect;
	int			n;
}				t_ui_lst;

typedef	struct	s_ui
{
	SDL_Rect	scene_place;
	t_ui_bg		bg[BG_ITEMS];
	t_ui_btn	btn[BTNS];
	t_ui_rbtn	rbtn;
	t_ui_scrl	scroll;
	t_ui_lst	list;
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
	CO_DOT = 10,
	LOGO = 11
};

enum			e_btns
{
	OPEN = 0,
	SAVE = 1,
	SAVE_AS = 2,
	EXPORT = 3,
	PREV_CAM = 4,
	NEXT_CAM = 5,
	BTN_SPHERE = 6,
	BTN_CYLINDER = 7,
	BTN_CONUS = 8,
	BTN_PARABOLOID = 9,
	BTN_DISK = 10,
	BTN_PLANE = 11,
	BTN_TRIANGLE = 12,
	BTN_CUBE = 13,
	BTN_CAM = 14,
	BTN_LIGHT1 = 15,
	BTN_LIGHT2 = 16,
	BTN_LIGHT3 = 17
};

void			ui_scroll_init(t_ui *ui, t_sdl *sdl);
void			ui_buttons_init(t_ui *ui, t_sdl *sdl);
void			ui_textures_init(t_ui *ui, t_sdl *sdl);

void			ui_render_corners(t_ui *ui, t_sdl *sdl, SDL_Rect place);
void			ui_render_lines(t_ui *ui, t_sdl *sdl);

/*
** move to libftSDL
*/

SDL_Rect		sdl_rect(int x, int y, int h, int w);
SDL_Texture		*sdl_texture_from_file(char *filename, SDL_Renderer *renderer);
void			sdl_recreate_img(t_img *img, size_t w, size_t h);
int				xy_in_rect(int x, int y, SDL_Rect rect);

#endif
