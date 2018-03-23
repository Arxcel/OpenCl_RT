/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:57:16 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/23 14:28:35 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H
# include "ft_vector.h"
# include "ft_matrix.h"
# include "ft_scene.h"
# ifndef M_PI
#  define M_PI 3.14159265359f
# endif

typedef struct				s_ray
{
	t_vector2				tex;
	t_vector				p_hit;
	t_vector				n_hit;
	t_vector				dir;
	t_vector				orig;
}							t_ray;

/*
**  Util functions
*/
float						ft_deg2rad(float deg);
short						solve_quadratic(const float *p, float *x0, float *x1);
unsigned int				set_rgb(t_vector c);
t_matrix33					v_rot2(double angle);
float						Noise_2d(float x, float y);
t_vector					get_rgb(unsigned int c);
/*
**  Drawing functions
*/
unsigned int		ft_renderer(
		global t_object	*o,
		global t_light	*l,
		global t_camera *cam,
		int x,
		int y,
		size_t img_w,
		size_t img_h,
		global unsigned int *tex1,
		global unsigned int *tex2,
		global unsigned int *tex3,
		global unsigned int *tex4);
t_vector					ft_rotate(t_vector vector, t_vector angle);

float						calc_light(__global t_object	*o,
									__global t_light	*l,
									t_object h, t_ray *r);
/*
**  Check intersections
*/
short						sphere_cross(t_object sphere, t_ray *r, float *t);
short						cyl_cross(t_object cyl, t_ray *r, float *t);
short						con_cross(t_object cyl, t_ray *r, float *t);
short						plane_cross(t_object *p, t_ray *r, float *t);
short						disk_cross(t_object *d, t_ray *r, float *t);
short						triangle_cross(t_object *p, t_ray *r, float *t);
short						square_cross(t_object *p, t_ray *r, float *t);
short						par_cross(t_object sh, t_ray *ray, float *t);

void						get_surface_data(t_ray *ray, t_object object, float t);
int							check_object_type(t_object object, t_ray *ray, float *t);
short						get_sphere_data(t_ray *temp, t_object sphere, float t);
short						get_cyl_data(t_ray *ray, t_object con, float t);
short						get_con_data(t_ray *ray, t_object con, float t);
short						get_plane_data(t_ray *ray, t_object plane, float t);
short						get_disk_data(t_ray *ray, t_object disk, float t);
short						get_triangle_data(t_ray *ray, t_object plane, float t);
short						get_par_data(t_ray *ray, t_object sh, float t);
t_vector					get_object_color(t_object	*o,
														t_ray *r,
														global unsigned int *tex1,
														global unsigned int *tex2,
														global unsigned int *tex3,
														global unsigned int *tex4);
short						get_square_data(t_ray *ray, t_object square, float t);
#endif
