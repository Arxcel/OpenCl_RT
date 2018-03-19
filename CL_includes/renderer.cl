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
	else if (object.type == O_PARABOLOID)
		get_par_data(ray, object, t);
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
	else if (object.type == O_PARABOLOID)
		return (par_cross(object, ray, t));
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

static t_vector			reflect_ray(const t_ray *r)
{
	return (v_normalize(r->dir - v_mult_d(r->n_hit, 2 * v_dot(r->n_hit, r->dir))));
}

static t_vector			refract_ray(t_ray *r, float refract_index)
{
	float cosi;
	float eta_air;
	float eta_material;
	float eta;
	float k;

	cosi = v_dot(r->dir, r->n_hit);
	eta_air = 1;
	eta_material = refract_index;
	if (cosi < 0)
	{
		cosi = -cosi;
		eta = eta_air / eta_material;
	}
	else 
	{
		r->n_hit = -r->n_hit;
		eta = eta_material / eta_air; 
	}
	k = 1 - eta * eta * (1 - cosi * cosi);
	return k < 0 ? (t_vector){0, 0, 0} : v_normalize(v_mult_d(r->dir, eta) + v_mult_d(r->n_hit, (eta * cosi - native_sqrt(k))));
}


static float	fresnel(t_vector dit, t_vector norm, float ior)
{
	float kr;
	float buf;
	float cosi;
	float etai;
	float etat;
	float sint;
	float cost;
	float Rs;
	float Rp;

	cosi = v_dot(dit, norm);
	if (cosi > 1)
		cosi = 1;
	else if (cosi < -1)
		cosi = -1;
	etai = 1;
	etat = ior;

	if (cosi > 0)
	{
		buf = etai;
		etai = etat;
		etat = buf;
	}
	sint = etai / etat * native_sqrt((1 - cosi * cosi) < 0 ? 0 : (1 - cosi * cosi));
	if (sint >= 1)
		kr = 1;
	else
	{
		cost = native_sqrt((1 - sint * sint) < 0 ? 0 : (1 - sint * sint));
		cosi = cosi < 0 ? -cosi : cosi;
		Rs = ((etat * cosi) - (etai * cost)) / ((etat * cosi) + (etai * cost));
		Rp = ((etai * cosi) - (etat * cost)) / ((etai * cosi) + (etat * cost));
		kr = (Rs * Rs + Rp * Rp) / 2;
	}
	return (kr);
}

static t_vector			ft_cast_ray(
						__global t_object	*o,
						__global t_light	*l,
						t_ray				*r,
						t_object *hit_object)
{
	int			depth;
	t_vector	reflection_color;
	t_vector	refraction_color;
	t_vector	object_color;
	t_vector	hit_color;
	float		mask;
	float		t;
	float		kr;
	t_vector	bias;

	depth = 0;
	mask = 1;
	hit_color = (t_vector){0,0,0}; 
	while (depth < MAX_ITER)
	{
		if (!ft_trace(o, l, &t, hit_object, r))
			break ;
		get_surface_data(r, *hit_object, t);
				r->n_hit = v_dot(r->n_hit, r->dir) < 0 ? r->n_hit : -r->n_hit;
		bias = v_mult_d(r->n_hit, BIAS);
		int outside;
		outside = v_dot(r->dir, r->n_hit) < 0 ? 1 : 0;
		object_color = v_mult_d(hit_object->color, calc_light(o, l, *hit_object, *r));
		if (!hit_object->reflect && !hit_object->refract)
		{
			hit_color += v_mult_d(hit_object->color, mask * calc_light(o, l, *hit_object, *r));
			break ;
		}
		else if (hit_object->refract)
		{	
			reflection_color = (t_vector){0, 0, 0};
			refraction_color = (t_vector){0, 0, 0};
			kr = fresnel(r->dir, r->n_hit, hit_object->refract);
			if (kr < 1)
			{
				r->dir = refract_ray(r, hit_object->refract);
				r->orig = outside ? r->p_hit - bias : r->p_hit + bias;
				refraction_color = hit_color;
				depth++;
				continue ;
			}
			r->dir = reflect_ray(r);
			r->orig = outside ? r->p_hit + bias : r->p_hit - bias;
			reflection_color += v_mult_d(hit_color, (1.0 - hit_object->reflect) * mask);
			mask *= hit_object->reflect;
			depth++;
			continue ;
			hit_color += v_mult_d(reflection_color, kr) + v_mult_d(refraction_color, (1 - kr)); 
		}
		else if (hit_object->reflect && !hit_object->refract)
		{
			r->dir = reflect_ray(r);
			r->orig = outside ? r->p_hit + bias : r->p_hit - bias;
			hit_color += v_mult_d(object_color, (1.0 - hit_object->reflect) * mask);
			mask *= hit_object->reflect;
			depth++;
		}
	}
    return (hit_color); 
} 

static t_ray			find_cam_dir(__global t_camera    *cam, const int *iter, size_t i_w, size_t i_h)
{
	float scale;
	float x;
	float y;
	t_ray ray;

	scale = native_tan(ft_deg2rad(cam->fov * 0.5));
	x = (2 * (iter[1] + 0.5) / (float)i_w - 1) * (i_w / (float)i_h) * scale;
	y = (1 - 2 * (iter[0] + 0.5) / (float)i_h) * scale;
	cam->dir = (t_vector){x, y, -1};
	cam->dir = ft_rotate(cam->dir, cam->rot);
	ray.dir = v_normalize(cam->dir);
	ray.orig = cam->pos;
	return (ray);
}

unsigned int		ft_renderer(
		global t_object	*o,
		global t_light	*l,
		global t_camera *cam,
		int x, int y, size_t img_w, size_t img_h)
{
	int				iter[2];
	t_vector		res;
	t_object		hit_object;
	t_ray			ray;

	iter[0] = y;
	iter[1] = x;
	ray = find_cam_dir(cam, iter, img_w, img_h);
	res = ft_cast_ray(o, l, &ray, &hit_object);
	return (set_rgb(res));
}
