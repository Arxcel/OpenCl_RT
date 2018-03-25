/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:37:12 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 21:44:36 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UI_H
# define FT_UI_H
# define RTN 2
# define BG_ITEMS 15
# define BTNS 30
# define SLDRS 1
# define O_SET 25
# define LI_SET 14
# define CA_SET 10
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
# define TEXTURE_ON(x, y) ui->btn[x].on = sdl_texture_from_file(y, sdl->ren);
# define TEXTURE_OFF(x, y) ui->btn[x].off = sdl_texture_from_file(y, sdl->ren);

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_ui_bg
{
	SDL_Rect		rect;
	SDL_Texture		*textr;
}					t_ui_bg;

typedef struct		s_ui_btn
{
	SDL_Rect		rect;
	SDL_Texture		*on;
	SDL_Texture		*off;
	int				status;
}					t_ui_btn;

typedef struct		s_ui_rbtn
{
	SDL_Rect		rect;
	t_ui_bg			a;
	t_ui_bg			b;
	t_ui_bg			c;
	int				status;
}					t_ui_rbtn;

typedef struct		s_ui_scrl
{
	t_ui_bg			r1;
	t_ui_bg			r2;
	t_ui_bg			line;
	t_ui_bg			b_r1;
	t_ui_bg			b_r2;
	t_ui_bg			b_line;
	int				steps;
	int				visible_steps;
	int				possible_steps;
	int				first_step;
}					t_ui_scrl;

typedef struct		s_ui_lst
{
	SDL_Rect		rect;
	int				n;
	int				active_n;
	int				active;
}					t_ui_lst;

typedef struct		s_ui_set
{
	t_ui_bg			name;
	t_ui_bg			data;
	float			*p;
	short			*sp;
	unsigned short	*usp;
}					t_ui_set;

typedef	struct		s_ui
{
	SDL_Rect		scene_place;
	t_ui_bg			bg[BG_ITEMS];
	t_ui_btn		btn[BTNS];
	t_ui_rbtn		rbtn;
	t_ui_scrl		scroll;
	t_ui_lst		list;
	t_ui_set		o_set[O_SET];
	t_ui_set		l_set[LI_SET];
	t_ui_set		c_set[CA_SET];
}					t_ui;

enum				e_o_set
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

enum				e_l_set
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

enum				e_c_set
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

enum				e_bg
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
	LOGO = 11,
	SET_1 = 12,
	SET_2 = 13,
	SET_3 = 14
};

enum				e_btns
{
	OPEN = 0,
	SAVE_AS = 1,
	EXPORT = 2,
	PREV_CAM = 3,
	NEXT_CAM = 4,
	BTN_AE1 = 5,
	BTN_AE2 = 6,
	BTN_AE3 = 7,
	BTN_AE4 = 8,
	BTN_AE5 = 9,
	BTN_AE6 = 10,
	BTN_PLUS = 11,
	BTN_MINUS = 12,
	BTN_ZERO = 13,
	BTN_ONE = 14,
	BTN_SPHERE = 15,
	BTN_CYLINDER = 16,
	BTN_CONUS = 17,
	BTN_PARABOLOID = 18,
	BTN_DISK = 19,
	BTN_PLANE = 20,
	BTN_TRIANGLE = 21,
	BTN_SQUARE = 22,
	BTN_CAPS = 23,
	BTN_BARB = 24,
	BTN_CAM = 25,
	BTN_LIGHT1 = 26,
	BTN_LIGHT2 = 27,
	BTN_LIGHT3 = 28,
	BTN_LIGHT4 = 29
};

void				ui_scroll_init(t_ui *ui, t_sdl *sdl);
void				ui_buttons_init(t_ui *ui, t_sdl *sdl);
void				ui_textures_init(t_ui *ui, t_sdl *sdl);
void				ui_settings_init(t_ui *ui, t_sdl *sdl);
void				ui_render_corners(t_ui *ui, t_sdl *sdl, SDL_Rect place);
void				ui_render_lines(t_ui *ui, t_sdl *sdl);
void				texture_from_text(char *text, t_sdl *sdl, t_ui_bg *p);

/*
** move to libftSDL
*/

SDL_Rect			sdl_rect(int x, int y, int h, int w);
SDL_Texture			*sdl_texture_from_file(char *filename,
													SDL_Renderer *renderer);
void				sdl_recreate_img(t_img *img, size_t w, size_t h);
int					xy_in_rect(int x, int y, SDL_Rect rect);

#endif
