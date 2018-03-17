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
	else if (object.type == O_TRIANGLE)
		get_triangle_data(ray, object, t);
}

int		check_object_type(t_object object, t_ray *ray, float *t)
{
	if (object.type == O_SPHERE)
		return (sphere_cross(object, ray, t));
	else if (object.type == O_CYL)
		return (cyl_cross(object, ray, t));
	else if (object.type == O_CON)
		return (con_cross(object, ray, t));
	else if (object.type == O_PLANE)
		return (plane_cross(&object, ray, t));
	else if (object.type == O_DISK)
		return (disk_cross(&object, ray, t));
	else if (object.type == O_TRIANGLE)
		return (triangle_cross(&object, ray, t));
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
			if (ray->n_hit[0])
				ray->in_figure = ray->n_hit[0];
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
		if (!(f && shader_distance < distance && lt > 0))
		{
			light_intensity = lt * l[i].intence;
			// Блики
			if (h.specular > 0)
			{
				glare = v_mult_d(ray.n_hit, 2 * lt) - light.dir;
				gt = v_dot(glare, -ray.dir);
				if (gt > 0)
				{
					if (h.specular <= 2)
						corel = 0.04;
					else if (h.specular <= 10)
						corel = 0.08;
					else if (h.specular <= 50)
						corel = 0.1;
					else if (h.specular <= 250)
						corel = 0.15;
					else if (h.specular <= 1250)
						corel = 0.2;
					else
						corel = 1;
					light_intensity += light_intensity * native_powr(gt, h.specular) * corel;
				}
			}
		}
		if (v_dot(-ray.dir, ray.n_hit) > 0)
			ret_col += light_intensity;
	}
	return (ret_col);
}

static void				reflect_ray(t_ray *r)//t_vector n, t_vector dir, t_vector p)
{
	r->dir = r->dir - v_mult_d(r->n_hit, 2 * v_dot(r->n_hit, r->dir));
	r->orig = r->p_hit + v_mult_d(r->n_hit, BIAS);
}

// static t_ray				refract(t_vector n, t_vector dir, t_vector ior)
// {
// 	float cosi;
// 	float etai;
// 	float etat;
// 	float eta;
// 	float k;

// 	cosi = v_dot(dir, n);
// 	etai = 1;
// 	etat = ior;
// 	if (cosi < 0)
// 	{
// 		cosi = -cosi;
// 		eta = etai / etat;
// 	}
// 	else 
// 	{
// 		n = -n;
// 		eta = etat / etai; 
// 	}
// 	k = 1 - eta * eta * (1 - cosi * cosi);
//     return (k < 0 ? 0 : eta * I + (eta * cosi - native_sqrt(k)) * n); 
// }

static t_vector		ft_cast_ray(
						__global t_object	*o,
						__global t_light	*l,
						t_ray				*r,
						t_object *hit_object)
{
	float			t;
	int				i;
	t_vector		light;
	float			reflect;
	t_vector		reflect_color;

	light = (t_vector){0, 0, 0};
	i = -1;
	while (++i < MAX_ITER)
	{
	    if (!ft_trace(o, l, &t, hit_object, r))
			return ((t_vector){0, 0, 0});
		get_surface_data(r, *hit_object, t);
		r->n_hit = v_dot(r->n_hit, r->dir) < 0 ? r->n_hit : -r->n_hit;
		light += v_mult_d(hit_object->color, get_light(o, l, *hit_object, *r));
		reflect = hit_object->reflect;
		if (!reflect)
			continue ;
		reflect_ray(r);
		reflect_color = v_mult_d(hit_object->color, get_light(o, l, *hit_object, *r));
		light += v_mult_d(light, (1 - reflect)) + v_mult_d(reflect_color, reflect);
	}
	return (light);
}

static t_ray			find_cam_dir(__global t_camera    *cam, const int *iter)
{
	float scale;
	float x;
	float y;
	t_ray ray;

	scale = native_tan(ft_deg2rad(cam->fov * 0.5));
	x = (2 * (iter[1] + 0.5) / (float)IMG_WIDTH - 1) * (IMG_WIDTH / (float)WIN_HEIGHT) * scale;
	y = (1 - 2 * (iter[0] + 0.5) / (float)WIN_HEIGHT) * scale;
	cam->dir = (t_vector){x, y, -1};
	cam->dir = ft_rotate(cam->dir, cam->rot);
	ray.dir = v_normalize(cam->dir);
	ray.orig = cam->pos;
	return (ray);
}

unsigned int	ft_renderer(
				__global t_object	*o,
				__global t_light	*l,
				__global t_camera	*cam,
				int					x,
				int					y)
{
    int				iter[2];
	t_vector		res;
    t_object		hit_object;
	t_ray			ray;

	iter[0] = y;
	iter[1] = x;
    ray = find_cam_dir(cam, iter);
	res = ft_cast_ray(o, l, &ray, &hit_object);
    return (set_rgb(res));
}
