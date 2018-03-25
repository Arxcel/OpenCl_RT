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

#include "ft_rt.h"

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
	else if (object.type == O_SQUARE)
		get_square_data(ray, object, t);
	else if (object.type == O_CUBE)
	{
		if(object.mini_type == O_SQUARE)
			get_square_data(ray, object, t);
	}
	else if (object.type == O_CAPSULA)
	{
		if(object.mini_type == O_SPHERE)
			get_sphere_data(ray, object, t);
		else if(object.mini_type == O_CYL)
			get_cyl_data(ray, object, t);
	}
	else if (object.type == O_BARBELL)
	{
		if(object.mini_type == O_SPHERE)
			get_sphere_data(ray, object, t);
		else if(object.mini_type == O_CYL)
			get_cyl_data(ray, object, t);
	}
}

int		check_object_type(t_object *object, t_ray *ray, float *t)
{
	if (object->type == O_SPHERE)
		return (sphere_cross(*object, ray, t));
	else if (object->type == O_CYL)
		return (cyl_cross(*object, ray, t));
	else if (object->type == O_CON)
		return (con_cross(*object, ray, t));
	else if (object->type == O_PLANE)
		return (plane_cross(object, ray, t));
	else if (object->type == O_DISK)
		return (disk_cross(object, ray, t)); 
	else if (object->type == O_TRIANGLE)
		return (triangle_cross(object, ray, t));
	else if (object->type == O_PARABOLOID)
		return (par_cross(*object, ray, t));
	else if (object->type == O_SQUARE)
		return (square_cross(object, ray, t));
	else if (object->type == O_CUBE)
		return (cube_cross(object, ray, t));
	else if (object->type == O_CAPSULA)
		return (capsula_cross(object, ray, t));
	else if (object->type == O_BARBELL)
		return (barbell_cross(object, ray, t));
	return (0);
}

static int				ft_trace(__global t_object	*o,
								__global t_light	*l,
								float *t_near,
								t_object *hit_object,
								t_ray *ray)
{
	float	t;
	int		i;
	int		flag;
	float	z_buf;
	t_object	o_buf;

	i = 0;
	flag = 0;
	z_buf = INF;
	while (o[i].type)
	{
		o_buf = o[i];
		if (check_object_type(&(o_buf), ray, &t) && t < z_buf)
		{
			*t_near = t;
			z_buf = t;
			*hit_object = o_buf;
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
	float eta;
	float k;

	cosi = v_dot(r->dir, r->n_hit);
	if (cosi < 0)
	{
		cosi = -cosi;
		eta = 1 / refract_index;
	}
	else 
		eta = refract_index; 
	k = 1 - eta * eta * (1 - cosi * cosi);
	return k < 0 ? (t_vector){0, 0, 0} : v_normalize(v_mult_d(r->dir, eta) + v_mult_d(r->n_hit, (eta * cosi - native_sqrt(k))));
}

static float	fresnel(t_vector dit, t_vector norm, float ior)
{
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
	if (cosi < 0)
	{
		etai = 1;
		etat = ior;
	}
	else
	{
		etai = ior;
		etat = 1;
	}
	sint = etai / etat * native_sqrt((1 - cosi * cosi) < 0 ? 0 : (1 - cosi * cosi));
	if (sint < 1)
	{
		cost = native_sqrt((1 - sint * sint) < 0 ? 0 : (1 -  sint * sint));
		cosi = cosi < 0 ? -cosi : cosi;
		Rs = ((etat * cosi) - (etai * cost)) / ((etat * cosi) + (etai * cost));
		Rp = ((etai * cosi) - (etat * cost)) / ((etai * cosi) + (etat * cost));
		return ((Rs * Rs + Rp * Rp) / 2);
	}
	return (1);
}

t_vector		set_light(t_vector obj_color, t_vector light)
{
	t_vector res;

	res[0] = obj_color[0] * light[0];
	res[1] = obj_color[1] * light[1];
	res[2] = obj_color[2] * light[2];
	return (res);
}

static t_vector			ft_cast_ray(
						__global t_object	*o,
						__global t_light	*l,
						t_ray				*r,
						t_object			*hit_object,
						global unsigned int *tex1,
						global unsigned int *tex2,
						global unsigned int *tex3,
						global unsigned int *tex4,
						global unsigned int *perlin)
{
	int			depth;
	t_vector	object_color;
	t_vector	hit_color;
	float		mask_reflection;
	float		mask_refraction;
	float		t;
	float		kr;
	t_vector	bias;
	int			outside;

	depth = 0;
	mask_reflection = 1;
	mask_refraction = 1;
	hit_color = (t_vector){0,0,0}; 
	while (depth < MAX_ITER)
	{
		if (!ft_trace(o, l, &t, hit_object, r))
			break ;
		get_surface_data(r, *hit_object, t);
		r->n_hit = v_dot(r->n_hit, r->dir) < 0 ? r->n_hit : -r->n_hit;
		outside = v_dot(r->n_hit, r->dir) < 0 ? 1 : 0;
		bias = v_mult_d(r->n_hit, BIAS);
		object_color = set_light(get_object_color(hit_object, r, tex1, tex2, tex3, tex4, perlin), calc_light(o, l, *hit_object, r, tex1, tex2, tex3, tex4, perlin));
		if ((!hit_object->reflect && !hit_object->refract))
		{
			hit_color += v_mult_d(object_color, mask_refraction * mask_reflection);
			break ;
		}
		else if (hit_object->reflect && !hit_object->refract)
		{
			r->dir = reflect_ray(r);
			r->orig = outside ? r->p_hit + bias : r->p_hit - bias;
			hit_color += v_mult_d(object_color, (1.0 - hit_object->reflect) * mask_reflection * mask_refraction);
			mask_reflection *= hit_object->reflect;
			depth++;
		}
		else if (hit_object->refract)
		{	
			kr = fresnel(r->dir, r->n_hit, hit_object->ior);
			if (kr < 1)
			{
				r->dir = refract_ray(r, hit_object->ior);
				r->orig = outside ? r->p_hit - bias : r->p_hit + bias;
				hit_color += v_mult_d(object_color, (1.0 - hit_object->refract) * mask_refraction * (1 - kr));
				mask_refraction *= hit_object->refract;
				depth++;
				continue ;
			}
			r->dir = reflect_ray(r);
			r->orig = outside ? r->p_hit + bias : r->p_hit - bias;
			hit_color += v_mult_d(object_color, (1.0 - hit_object->reflect) * mask_reflection * kr);
			mask_reflection *= hit_object->reflect;
			depth++;
			continue ;
		}
	}
    return (hit_color); 
} 

static t_ray				find_cam_dir(__global t_camera    *cam, int xx, int yy, size_t i_w, size_t i_h)
{
	float scale;
	float x;
	float y;
	t_ray ray;
	float d;

	d = cam->fov * 0.5;
	scale = native_tan(radians(d));
	x = (2 * (xx + 0.5) / (float)i_w - 1) * (i_w / (float)i_h) * scale;
	y = (1 - 2 * (yy + 0.5) / (float)i_h) * scale;
	ray.dir = v_normalize(ft_rotate((t_vector){x, y, -1}, cam->rot));
	ray.orig = cam->pos;	
	return (ray);
}

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
							global unsigned int *perlin)
{
	t_object		hit_object;
	t_ray			ray;

    ray = find_cam_dir(cam, x, y, img_w, img_h);
	return (set_rgb(ft_cast_ray(o, l, &ray, &hit_object, tex1, tex2, tex3, tex4, perlin)));
}
