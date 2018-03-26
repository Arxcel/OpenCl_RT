/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:32:12 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/26 13:15:05 by vkozlov          ###   ########.fr       */
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
# include "lib_ae.h"
# define WIN_W			1280
# define WIN_H			670
# define MAX_ITER		5

typedef struct		s_main
{
	t_scene	s;
	t_ui	ui;
	t_cl	cl;
	t_sdl	sdl;
	t_ae	ae;
}					t_main;

void				sdl_hook(t_main *m);
void				sdl_loop(t_main *m);
char				*set_flags(const char *path);
void				get_scene(const char *filepath, t_scene *s);
int					put_error(const char *err_text);
void				process_value(json_value *value, t_scene *s);
void				re_draw(t_cl *cl, t_sdl *sdl, t_scene *s);
void				move_camera(t_scene *s);
float				ft_deg2rad(float deg);
void				create_triangle_norm(t_object *obj);
void				create_conus(t_object *obj);
void				delete_scene(t_scene *s);
float				perlin2d(float x, float y, float freq, int depth);
/*
** OPEN EXPORT SAVE
*/

char				*read_object_type(int i, t_main *m);
char				*read_light_type(int i, t_main *m);
char				*read_camera_type(int i, t_main *m);
char				*read_pattern_type(int i, t_main *m);
void				save_function(int fd, t_main *m);
void				export_file(t_main *m);
void				open_file(t_main *m);
void				save_as_file(t_main *m);

/*
** mouse hooks
*/

void				mouse_down(int x, int y, t_main *m);
void				mouse_up(int x, int y, t_main *m);

/*
** ui and render
*/

void				render_copy_background(t_main *m);
void				render_copy_buttons(t_main *m);
void				render_copy_rbutton(t_main *m);
void				render_copy_scroll(t_main *m);
void				render_copy_list(t_main *m);
void				render_copy_settings(t_main *m);
void				sdl_rinit(t_sdl *sdl);
void				ui_and_sdl_init(t_main *m);
void				window_resized_event(t_main *m);
void				render_scene_and_ui(t_main *m);
void				change_settings_value(int x, int y, t_main *m);
SDL_Color			sdl_text_color(t_main *m, int i);
void				ui_o_settings_rebuild(t_main *m);
void				ui_l_settings_rebuild(t_main *m);
void				ui_c_settings_rebuild(t_main *m);
void				scroll_move(int y, t_main *m);
void				scroll_move_whell(int y, t_main *m);
void				mouse_scene_rot(int x, int y, t_main *m);

/*
** for After effects
*/

void				make_dependencies(t_main *m);
void				filter_key(int key, t_main *m);
void				get_scene_textures(t_main *m);
int					flush_effects(t_ae *ae);
void				add_effect(t_ae *ae, int val);

/*
** CTORS
*/

t_object			default_sphere(void);
t_object			default_cylinder(void);
t_object			default_conus(void);
t_object			default_plane(void);
t_object			default_paraboloid(void);
t_object			default_triangle(void);
t_object			default_disk(void);
t_object			default_square(void);
t_object			default_capsula(void);
t_object			default_barbell(void);
t_object			default_error(void);
t_light				default_ambient(void);
t_light				default_area(void);
t_light				default_lamp(void);
t_light				default_parallel(void);
t_light				default_light(void);
t_camera			default_camera(void);
t_object			default_elipsoid(void);
t_object			default_cddisk(void);
t_object			default_ring(void);

/*
** READ DATA FROM JSON TO OBJECTS/LIGHTS/CAMERAS
*/

void				process_scene_o(json_value *value, t_scene *s);
void				process_scene_l(json_value *value, t_scene *s);
void				process_scene_c(json_value *value, t_scene *s);

/*
** UTILS AND VALIDATION FOR PREV BLOCK
*/

t_vector			get_color(json_value *value);
t_vector			get_n_vector(json_value *value);
t_vector			get_vector(json_value *value);
float				get_number(json_value *value);
float				get_max(json_value *value);
float				get_tex_scale(json_value *value);
float				get_tex_angle(json_value *value);
float				get_specular(json_value *value);
float				get_ior(json_value *value);
float				get_refract(json_value *value);
float				get_reflect(json_value *value);
float				get_radius(json_value *value);
float				get_intensity(json_value *value);
float				get_fov(json_value *value);
t_object			get_obj_for_retrive(json_value *value);

/*
** CREATE SHAPES FROM UI
*/

void				create_shapes(int x, int y, t_main *m);
void				validate_elipsoid(t_object *object);

#endif
