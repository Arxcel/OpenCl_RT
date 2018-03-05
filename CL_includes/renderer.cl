/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:44:26 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/24 13:08:21 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void	get_surface_data(t_ray *ray, t_object object, float t)
{
	if (object.type == O_SPHERE)
		get_sphere_data(ray, object, t);
	else if (object.type == O_CYL)
		get_cyl_data(ray, object, t);
	else if (object.type == O_CON)
		get_con_data(ray, object, t);
	else if (object.type == O_PLANE)
		get_plane_data(ray, object, t);
}

int		check_object_type(t_object object, t_ray *ray, float *t)
{
	if (object.type == O_SPHERE)
		return (sphere_cross(object, ray->orig, ray->dir, t));
	if (object.type == O_CYL)
		return (cyl_cross(object, ray->orig, ray->dir, t));
	if (object.type == O_CON)
		return (con_cross(object, ray->orig, ray->dir, t));
	if (object.type == O_PLANE)
		return (plane_cross(&object, ray, t));
	return (0);
}

static int				ft_trace(__global t_object	*o,
								__global t_light	*l,
								__global t_camera	*cam,
								float *t_near,
								t_object *hit_object, t_ray *ray)
{
	float	t;
	int		i;
	int		flag;
	int		check;
	float	z_buf;

	i = 0;
	flag = 0;
	z_buf = INF;
	while (o[i].type)
	{
		check = check_object_type(o[i], ray, &t);
		if (check && t < z_buf)
		{
			*t_near = t;
			z_buf = t;
			*hit_object = o[i];
			flag = 1;
		}
		i++;
	}
	return (flag);
}

static t_vector			get_color(__global t_object	*o,
									__global t_light	*l,
									__global t_camera	*cam,
									t_object h,
									t_ray ray, t_vector hit_color)
{
	float			lt;
	t_vector		col;
	t_ray			light;
	t_object		shader;
	int				i;
	float			distance;
	int				f;
	float			shader_distance;

	i = -1;
	while (l[++i].type)
	{
		light.dir = v_normalize(l[i].pos - ray.p_hit);
		light.orig = ray.p_hit + v_mult_d(ray.n_hit, cam->bias);
		lt = v_dot(ray.n_hit, light.dir);
		f = ft_trace(o, l, cam, &shader_distance, &shader, &light);
		distance = v_length(l[i].pos - ray.p_hit);
		if (f && shader_distance < distance)
			col = v_mult_d(h.color, 0.101);
		else
		{
			col = v_mult_d(h.color, lt + 0.101) + v_mult_d(h.color, 0.101);
			col[0] += (0.8 - h.color[0]) * pow(lt, h.shape) * 0.9;
			col[1] += (0.8 - h.color[1]) * pow(lt, h.shape) * 0.9;
			col[2] += (0.8 - h.color[2]) * pow(lt, h.shape) * 0.9;
		}
		hit_color += col;
	}
	return (hit_color);
}

static void				find_cam_dir(__global t_camera    *cam, const int *iter)
{
    float scale;
    float x;
    float y;
    
    scale = native_tan(ft_deg2rad(cam->fov * 0.5));
    x = (2 * (iter[1] + 0.5) / (float)IMG_WIDTH - 1) *
    (IMG_WIDTH / (float)WIN_HEIGHT) * scale;
    y = (1 - 2 * (iter[0] + 0.5) / (float)WIN_HEIGHT) * scale;
    cam->dir = (t_vector){x, y, -1};
    cam->dir = ft_rotate(cam->dir, cam->rot);
    cam->dir = v_normalize(cam->dir);
}

static unsigned int		ft_cast_ray(
								__global t_object	*o,
								__global t_light	*l,
								__global t_camera	*cam,
								unsigned int hit_color,
								t_object *hit_object)
{
    t_ray			ray;
    float			t;
    t_vector		light;
    
    ray.dir = cam->dir;
    ray.orig = cam->pos;
    if (ft_trace(o , l, cam, &t, hit_object, &ray))
    {
        get_surface_data(&ray, *hit_object, t);
        light = get_color(o, l, cam, *hit_object, ray, (t_vector){0, 0, 0});
        hit_color = set_rgb(light);
    }
    return (hit_color);
}

unsigned int		ft_renderer(
        __global t_object	*o,
        __global t_light	*l,
        __global t_camera	*cam,
        int					x,
        int					y
)
{
    int				iter[2];
    unsigned int	z_color;
    t_object		hit_object;

	iter[0] = y;
	iter[1] = x;
    find_cam_dir(cam, iter);
    z_color = ft_cast_ray(o, l, cam, 0, &hit_object);
    return (z_color);
}
