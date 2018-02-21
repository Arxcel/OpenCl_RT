/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:57:16 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/23 19:36:49 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H
# include "ft_vector.h"
# include "ft_matrix.h"
# include "ft_scene.h"
//# include "../libft/include/ft_libftu.h"
# define INF				999999999999999999999999999999.9
# define MENU_WIDTH			0
# define IMG_WIDTH			1280
# define WIN_WIDTH			1280
# define WIN_HEIGHT			600
# define MSG(x)				ft_killer(x)

typedef struct				s_img
{
	void					*img;
	char					*ptr;
	int						bpp;
	int						size_line;
	int						endian;
}							t_img;
typedef struct				s_ray
{
	t_vector				p_hit;
	t_vector				n_hit;
	t_vector				dir;
	t_vector				orig;
}							t_ray;
typedef struct				s_mlx
{
	void					*mlx;
	void					*window;
	t_img					img;
	t_scene					scene;
}							t_mlx;
typedef struct				s_param
{
	t_mlx					*mlx;
	int						from;
	int						to;
}							t_param;
/*
**  Util functions
*/
float						ft_deg2rad(float deg);
short						solve_quadratic(const float *p,
											float *x0, float *x1);
unsigned int				set_rgb(t_vector c);
t_vector					get_color_percent(t_vector c);
void						ft_swap_d(float *d1, float *d2);
//void						find_cam_dir(t_camera *cam,
//										 const int i, const int j);
//unsigned int				ft_cast_ray(t_scene scene, unsigned int hit_color,
//												t_object *hit_object);
/*
**  Drawing functions
*/
unsigned int		ft_renderer(
		global t_object	*o,
		global t_light	*l,
		global t_camera *cam,
		int x, int y);
void						re_draw(t_mlx *mlx);
void						set_ui(t_mlx *mlx);
t_vector					ft_rotate(t_vector vector, t_vector angle);
/*
**  Check intersections
*/
void						get_surface_data(t_ray *ray,
											t_object object, float t);
int							check_object_type(t_object object,
												t_ray *ray, float *t);
short						sphere_cross(t_object sphere, t_vector
												orig, t_vector dir, float *t);
short						get_sphere_data(t_ray *temp, t_object sphere,
													float t);
short						cyl_cross(t_object cyl, t_vector orig,
												t_vector dir, float *t);
short						get_cyl_data(t_ray *ray, t_object con, float t);
short						con_cross(t_object cyl, t_vector orig,
									t_vector dir, float *t);
short						get_con_data(t_ray *ray, t_object con, float t);
short						plane_cross(t_object *p, t_ray *r, float *t);
short						get_plane_data(t_ray *ray,
											t_object plane, float t);
/*
**  Additional mlx functions
*/
void						new_image(t_mlx *mlx);
void						image_set_pixel(t_img *i, int x, int y, int color);
int							ft_killer(char *reason);
void						ft_mlx_init(char *title, t_mlx *mlx);
/*
**  Hook functions
*/
int							keyboard_hook(int key, t_mlx *mlx);
int							hook_mousemove(int x, int y, t_mlx *mlx);
int							hook_mouseup(int button, int x, int y, t_mlx *mlx);
int							hook_mousedown(int button,
											int x, int y, t_mlx *mlx);
/*
**  Hardcoded scenes
*/
void						choose_scene(t_scene *scene);
void						set_scene1(t_scene *scene);
void						set_scene2(t_scene *scene);
void						set_scene3(t_scene *scene);
void						set_scene4(t_scene *scene);
void						set_scene5(t_scene *scene);
void						set_scene6(t_scene *scene);
void						set_scene7(t_scene *scene);
#endif
