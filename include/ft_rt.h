/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:32:12 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/18 18:24:16 by afarapon         ###   ########.fr       */
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
# define WIN_W			1600
# define WIN_H			900
# define MAX_ITER		10000

typedef struct		s_main
{
	t_ui	ui;
	t_cl	cl;
	t_sdl	sdl;
	t_scene	s;
}					t_main;

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

/*
** anestor
*/

void				ui_and_sdl_init(t_main *m);
void				window_resized_event(t_main *m);
void				render_scene_and_ui(t_main *m);

#endif
