/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:32:12 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/19 19:28:48 by afarapon         ###   ########.fr       */
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
# define AE_SEPIA		1
# define AE_TOON		2
# define AE_M_BLUR		3
# define AE_STEREO		4
# define AE_SMOOTH		5

typedef struct		s_main
{
	t_scene	s;
	t_ui	ui;
	t_cl	cl;
	t_sdl	sdl;
	short	after_effect;
	// t_scene	s;
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

void				ui_and_sdl_init(t_main *m);
void				window_resized_event(t_main *m);
void				render_scene_and_ui(t_main *m);
void				set_filter(t_main *main);
//int					xy_in_rect(int x, int y, SDL_Rect rect);

#endif
