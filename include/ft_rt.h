/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:32:12 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/21 16:45:00 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RT_H
# define FT_RT_H
# include <stdio.h>
# include <time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "json.h"
# include "my_cl.h"
# include "ft_mymath.h"
# include "ft_sdl.h"
# include "ft_libftu.h"
# include "ft_scene.h"
# include "ft_ui.h"
# include "tinyfiledialogs.h"
# define WIN_W			1280
# define WIN_H			600
# define MAX_ITER		5
# define AE_SEPIA		0x1
# define AE_TOON		0x2
# define AE_M_BLUR		0x4
# define AE_SMOOTH		0x8
# define AE_CONTR		0x10
# define AE_SHARPNESS	0x20

typedef struct		s_main
{
	t_scene	s;
	t_ui	ui;
	t_cl	cl;
	t_sdl	sdl;
	short	after_effect;
	short	coeficient;
}					t_main;

typedef struct		s_rgb
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	alpha;
}					t_rgb;

typedef union		u_color
{
	unsigned int	col;
	struct s_rgb	argb;
}					t_color;

void				sdl_hook(t_main *m);
void				sdl_loop(t_main *m);
char				*set_flags(const char *path);
void				get_scene(const char *filepath, t_scene *s);
void				put_error(const char *err_text);
void				process_value(json_value *value, t_scene *s);
void				re_draw(t_cl *cl, t_sdl *sdl, t_scene *s);
void				move_camera(t_scene *s);
float				ft_deg2rad(float deg);
void				create_triangle_norm(t_object *obj);
void				create_conus(t_object *obj);
void				delete_scene(t_scene *s);

/*
** open export save
*/

void				export_file(t_main *m);
void				open_file(t_main *m);
void				save_file(t_main *m);
void				save_as_file(t_main *m);

/*
** mouse hooks
*/

void				mouse_down(int x, int y, t_main *m);
void				mouse_up(int x, int y, t_main *m);

/*
** ui and render
*/

void				sdl_rinit(t_sdl *sdl);
void				ui_and_sdl_init(t_main *m);
void				window_resized_event(t_main *m);
void				render_scene_and_ui(t_main *m);
//int					xy_in_rect(int x, int y, SDL_Rect rect);

/*
** image after effect
*/

unsigned char		clamp_rgb(int color);
void				set_filter(t_main *main);
unsigned int		set_smooth(t_main *main, size_t x, size_t y, unsigned int *in);
void				set_sepia(t_main *main, unsigned int *out);
unsigned int		**get_matrix(t_main *main, size_t x, size_t y,
	unsigned int *in);
unsigned int		ae_calc_matrix(unsigned int **m,
		unsigned int coef);
void				free_matrix(unsigned int **m);
t_rgb				get_color_rgb(int col);
void				set_contrast(t_main *main, unsigned int *out);
void				set_blur(t_main *main, unsigned int **in_out, size_t count);
void				ae_test_blur(t_main *main, unsigned int **in, size_t size);
unsigned int		set_test_blur(t_main *main, unsigned int *in, size_t x, size_t y);
unsigned int		set_sharpness(t_main *main, size_t x, size_t y, unsigned int *in);
void				ae_sharpness(t_main *main, unsigned int **in_out, size_t count);

#endif
