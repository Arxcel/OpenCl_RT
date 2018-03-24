/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:37:12 by anestor           #+#    #+#             */
/*   Updated: 2018/03/24 17:51:56 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UI_H
# define FT_UI_H
# define RTN 2
# define BG_ITEMS 12
# define BTNS 19
# define SLDRS 1
# define O_SET 25
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
# define R_TEXT_H 20
# define R_TEXT_W 90
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
	int			active_n;
	int			active;
}				t_ui_lst;

typedef struct	s_ui_o_set
{
	t_ui_bg		name;
	t_ui_bg		data;
	float		*p;
	short		*sp;
	unsigned short *usp;
}				t_ui_o_set;

typedef	struct	s_ui
{
	SDL_Rect	scene_place;
	t_ui_bg		bg[BG_ITEMS];
	t_ui_btn	btn[BTNS];
	t_ui_rbtn	rbtn;
	t_ui_scrl	scroll;
	t_ui_lst	list;
	t_ui_o_set	o_set[O_SET];
}				t_ui;

enum			e_o_set
{
	E_COL_R = 0,
	E_COL_G = 1,
	E_COL_B = 2,
	E_DIR_X = 3,
	E_DIR_Y = 4,
	E_DIR_Z = 5,
	E_POS1_X = 6,
	E_POS1_Y = 7,
	E_POS1_Z = 8,
	E_POS2_X = 9,
	E_POS2_Y = 10,
	E_POS2_Z = 11,
	E_POS3_X = 12,
	E_POS3_Y = 13,
	E_POS3_Z = 14,
	E_RAD = 15,
	E_REFL = 16,
	E_REFR = 17,
	E_ANGL = 18,
	E_IOR = 18,
	E_MIN = 19,
	E_MAX = 20,
	E_SPECUL = 21,
	E_TEX_ID = 22,
	E_TEX_SCL = 23,
	E_TEX_ANG = 24
};

enum			e_l_set
{
	E_LCOL_R = 0,
	E_LCOL_G = 1,
	E_LCOL_B = 2,
	E_LPOS_X = 3,
	E_LPOS_Y = 4,
	E_LPOS_Z = 5,
	E_LPOS2_X = 6,
	E_LPOS2_Y = 7,
	E_LPOS2_Z = 8,
	E_LDIR_X = 9,
	E_LDIR_Y = 10,
	E_LDIR_Z = 11,
	E_LINTENCE = 12,
	E_LANGLE = 13
};

enum			e_c_set
{
	E_CPOS_X = 0,
	E_CPOS_Y = 1,
	E_CPOS_Z = 2,
	E_CDIR_X = 3,
	E_CDIR_Y = 4,
	E_CDIR_Z = 5,
	E_CROT_X = 6,
	E_CROT_Y = 7,
	E_CROT_Z = 8,
	E_CFOV = 9
};

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
	BTN_LIGHT3 = 17,
	BTN_LIGHT4 = 18
};

void			ui_scroll_init(t_ui *ui, t_sdl *sdl);
void			ui_buttons_init(t_ui *ui, t_sdl *sdl);
void			ui_textures_init(t_ui *ui, t_sdl *sdl);
void			ui_settings_init(t_ui *ui, t_sdl *sdl);

void			ui_render_corners(t_ui *ui, t_sdl *sdl, SDL_Rect place);
void			ui_render_lines(t_ui *ui, t_sdl *sdl);

void			texture_from_text(char *text, t_sdl *sdl, t_ui_bg *p);

/*
** move to libftSDL
*/

SDL_Rect		sdl_rect(int x, int y, int h, int w);
SDL_Texture		*sdl_texture_from_file(char *filename, SDL_Renderer *renderer);
void			sdl_recreate_img(t_img *img, size_t w, size_t h);
int				xy_in_rect(int x, int y, SDL_Rect rect);

#endif
