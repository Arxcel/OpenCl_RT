/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:57:16 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/26 11:40:39 by vkozlov          ###   ########.fr       */
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
# ifndef INF
#  define INF 999999999999999999999999999999.9f
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
short						solve_quadratic(const float *p, float *x0, float *x1);
unsigned int				set_rgb(t_vector c);
t_matrix33					v_rot2(float angle);
t_vector					get_rgb(unsigned int c);
t_vector					set_light(t_vector obj_color, t_vector light);
/*
**  Drawing functions
*/
unsigned int				ft_renderer(
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
							global unsigned int *tex4,
							global unsigned int *perlin);
t_vector					ft_rotate(t_vector vector, t_vector angle);

t_vector							calc_light(__global t_object	*o,
									__global t_light	*l,
									t_object h, t_ray *r,
									t_vector	*bias,
									global unsigned int *tex1,
									global unsigned int *tex2,
									global unsigned int *tex3,
									global unsigned int *tex4,
									global unsigned int *perlin);
/*
**  Check intersections
*/
t_vector					get_object_color(
							t_object	*o,
							t_ray *r,
							global unsigned int *tex1,
							global unsigned int *tex2,
							global unsigned int *tex3,
							global unsigned int *tex4,
							global unsigned int *perlin);
short						sphere_cross(t_object sphere, t_ray *r, float *t);
short						cyl_cross(t_object cyl, t_ray *r, float *t);
short						con_cross(t_object cyl, t_ray *r, float *t);
short						plane_cross(t_object *p, t_ray *r, float *t);
short						disk_cross(t_object *d, t_ray *r, float *t);
short						cddisk_cross(t_object *d, t_ray *r, float *t);
short						triangle_cross(t_object *p, t_ray *r, float *t);
short						square_cross(t_object *p, t_ray *r, float *t);
short						par_cross(t_object sh, t_ray *ray, float *t);
short						cube_cross(t_object *p, t_ray *r, float *t);
short						capsula_cross(t_object *p, t_ray *r, float *t);
short						barbell_cross(t_object *object, t_ray *ray, float *t);

void						get_surface_data(t_ray *ray, t_object object, float t);
int							check_object_type(t_object *object, t_ray *ray, float *t);
short						get_sphere_data(t_ray *temp, t_object sphere, float t);
short						get_cyl_data(t_ray *ray, t_object con, float t);
short						get_con_data(t_ray *ray, t_object con, float t);
short						get_plane_data(t_ray *ray, t_object plane, float t);
short						get_disk_data(t_ray *ray, t_object disk, float t);
short						get_cddisk_data(t_ray *ray, t_object disk, float t);
short						get_triangle_data(t_ray *ray, t_object plane, float t);
short						get_par_data(t_ray *ray, t_object sh, float t);
short						get_square_data(t_ray *ray, t_object square, float t);
short						get_elipsoid_data(t_ray *ray, t_object elips, float t);
short						cross_elipsoid(t_object elips, t_ray *r, float *t);

#endif
