
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

static short			is_in_area(t_light l, t_ray light)
{
	float	v_cos;

	v_cos = v_dot(light.dir, -l.dir);
	v_cos /= v_length(light.dir) * v_length(-l.dir);
	if (v_cos < fabs(cos(ft_deg2rad(l.ang / 2))))
		return (0);
	else
		return (1);
}

static t_ray			dir_light(t_vector p_hit, t_vector l_dir, t_vector n, float *d)
{
	t_ray	light;
	
	light.dir = l_dir;
	light.orig = p_hit + v_mult_d(n, BIAS);
	*d = INFINITY;
	light.dir = -v_normalize(light.dir);
	return (light);
}

static t_ray			point_light(t_vector p_hit, t_vector l_pos, t_vector n, float *d)
{
	t_ray	light;
	
	light.dir = p_hit - l_pos;
	light.orig = p_hit + v_mult_d(n, BIAS);
	*d = v_length(light.dir);
	light.dir = -v_normalize(light.dir);
	return (light);
}

static float			get_shiness(float lambertian, float specular, float light_intensity, t_ray *r, t_ray light)
{
	float			c_gt;
	t_vector		shine;
	float			corel;

	shine = v_mult_d(r->n_hit, 2 * lambertian) - light.dir;
	c_gt = v_dot(shine, -r->dir);
	if (c_gt <= 0)
		return (0);
	if (specular <= 2)
		corel = 0.04;
	else if (specular <= 10)
		corel = 0.08;
	else if (specular <= 50)
		corel = 0.1;
	else if (specular <= 250)
		corel = 0.15;
	else if (specular <= 1250)
		corel = 0.2;
	else
		corel = 1;
	return (light_intensity * native_powr(c_gt, specular) * corel);
}

t_vector							calc_light(__global t_object	*o,
									__global t_light	*l,
									t_object h, t_ray *r,
									global unsigned int *tex1,
									global unsigned int *tex2,
									global unsigned int *tex3,
									global unsigned int *tex4)
{
	int				i;
	float			lt;
	float			vis;
	t_vector		ret_col;
	float			distance;
	float			shader_distance;
	float			light_intensity;
	t_object		shader;
	t_ray			light;

	i = -1;
	ret_col = (t_vector){0, 0, 0};
	shader.refract = 0;
	while (l[++i].type)
	{
		if (l[i].type == L_AMBIENT)
			ret_col += v_mult_d((t_vector){1, 1, 1} , l[i].intence);
		else
		{
			if (l[i].type == L_PAR)
				light = dir_light(r->p_hit, l[i].pos, r->n_hit, &distance);
			else
				light = point_light(r->p_hit, l[i].pos, r->n_hit, &distance);
			vis = !ft_trace(o, l, &shader_distance, &shader, &(light));
			if (l[i].type == L_AREA && !is_in_area(l[i], light))
				continue ;
			if (shader_distance > distance || (l[i].type == L_PAR && vis) || shader.refract)
				vis = 1;
			lt = v_dot(r->n_hit, light.dir);
			if (lt > 0)
			{
				light_intensity = lt * l[i].intence;
				if (shader.refract > 0 && shader.refract < 0.8)
				{
					light_intensity *= shader.refract;
					get_surface_data(&light, shader, shader_distance);
					ret_col += v_mult_d(l[i].color + get_object_color(&shader, &light, tex1, tex2, tex3, tex4), vis * light_intensity * lt);
					continue ;
				}
				if (h.specular > 0)
					light_intensity += get_shiness(lt, h.specular, light_intensity, r, light);	
				ret_col += v_mult_d(l[i].color, vis * light_intensity * lt);
			}
		}
	}
	return (ret_col);
}