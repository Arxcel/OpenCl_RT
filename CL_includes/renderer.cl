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
	else if (object.type == O_DISK)
		get_disk_data(ray, object, t);
}

int		check_object_type(t_object object, t_ray *ray, float *t)
{
	if (object.type == O_SPHERE)
		return (sphere_cross(object, ray->orig, ray->dir, t));
	else if (object.type == O_CYL)
		return (cyl_cross(object, ray->orig, ray->dir, t));
	else if (object.type == O_CON)
		return (con_cross(object, ray->orig, ray->dir, t));
	else if (object.type == O_PLANE)
		return (plane_cross(&object, ray, t));
	else if (object.type == O_DISK)
		return (disk_cross(&object, ray, t));
	return (0);
}

static int				ft_trace(__global t_object	*o,
								__global t_light	*l,
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

static float			get_light(__global t_object	*o,
									__global t_light	*l,
									t_object h, t_ray ray)
{
	float			lt;
	float			gt;
	float			ret_col;
	t_ray			light;
	t_object		shader;
	int				i;
	float			distance;
	int				f;
	float			shader_distance;
	t_vector		glare;
	float			corel;
	float			light_intensity;

	i = -1;
	ret_col = 0;
	while (l[++i].type)
	{
		light.dir = l[i].pos - ray.p_hit;
		light.orig = ray.p_hit + v_mult_d(ray.n_hit, BIAS);
		distance = v_length(light.dir);
		light.dir = v_normalize(light.dir);
		lt = v_dot(ray.n_hit, light.dir);
		f = ft_trace(o, l, &shader_distance, &shader, &light);
		light_intensity = 0; 
		if (!(f && shader_distance < distance))
		{
			light_intensity = lt * l[i].intence;
			// Блики
			if (h.shape > 0)
			{
				glare = v_mult_d(ray.n_hit, 2 * lt) - light.dir;
				gt = v_dot(glare, - ray.dir);
				if (gt > 0)
				{
					if (h.shape <= 2)
						corel = 0.04;
					else if (h.shape <= 10)
						corel = 0.08;
					else if (h.shape <= 50)
						corel = 0.1;
					else if (h.shape <= 250)
						corel = 0.15;
					else if (h.shape <= 1250)
						corel = 0.2;
					else
						corel = 1;
					light_intensity += light_intensity * native_powr(gt, h.shape) * corel;
				}
			}
		}
		ret_col += light_intensity;
	}
	return (ret_col);
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

static t_vector				reflect_ray(t_vector n, t_vector dir)
{
	return (v_mult_d(n, 2 * v_dot(n, dir)) - dir);
}

static t_vector					ft_cast_ray(
								__global t_object	*o,
								__global t_light	*l,
								t_ray				*r,
								t_object *hit_object)
{
    float			t;
    t_vector		light;

	hit_object->reflect = 0;
	light = (t_vector){0, 0, 0};
    if (ft_trace(o, l, &t, hit_object, r))
    {
        get_surface_data(r, *hit_object, t);
        light = v_mult_d(hit_object->color, get_light(o, l, *hit_object, *r));
	}
	return (light);
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
    t_vector		z_color;
	t_vector		reflect_color;
	t_vector		res;
    t_object		hit_object;
	t_ray			ray;
	float			reflect;
	int				i;

	iter[0] = y;
	iter[1] = x;
    find_cam_dir(cam, iter);
	ray.dir = cam->dir;
    ray.orig = cam->pos;
    z_color = ft_cast_ray(o, l, &ray, &hit_object);
	res = z_color;
	i = -1;
	while (++i < MAX_ITER)
	{
		reflect = hit_object.reflect;
		if (!reflect)
			return (set_rgb(res));
		ray.dir = reflect_ray(ray.n_hit, -ray.dir);
		ray.orig = ray.p_hit + + v_mult_d(ray.n_hit, BIAS);
		reflect_color = ft_cast_ray(o, l, &ray, &hit_object);
		res = v_mult_d(res, (1 - reflect)) + v_mult_d(reflect_color, reflect);
	}
    return (set_rgb(res));
}
