
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

static t_ray			point_light(t_vector p_hit, t_vector l_pos, t_vector n, float *light_intensity)
{
	t_ray	light;
	float	d;
	
	light.dir = p_hit - l_pos;
	light.orig = p_hit + v_mult_d(n, BIAS);
	d = v_length(light.dir);
	light.dir = -v_normalize(light.dir);
    // *light_intensity /= (4.0 * 3.14 * d * d);
	return (light);
}

static float			get_shiness(float lambertian, float specular, float light_intensity, t_ray ray, t_ray light)
{
	float			c_gt;
	t_vector		shine;
	float			corel;

	shine = v_mult_d(ray.n_hit, 2 * lambertian) - light.dir;
	c_gt = v_dot(shine, -ray.dir);
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

float					calc_light(__global t_object	*o,
									__global t_light	*l,
									t_object h, t_ray ray)
{
	int				i;
	float			lt;
	float			vis;
	float			ret_col;
	float			distance;
	float			shader_distance;
	float			light_intensity;
	t_object		shader;
	t_ray			light;
	t_vector		lp;

	i = -1;
	ret_col = 0;
	light_intensity = 0.0;
	while (l[++i].type)
	{
		light_intensity += l[i].intence;
		light = point_light(ray.p_hit, l[i].pos, ray.n_hit, &light_intensity);
		vis = !ft_trace(o, l, &shader_distance, &shader, &(light));
		// lp = normalize();
		lt = v_dot(ray.n_hit, light.dir);
		// lt = lt < 0 ? 0 : lt;
		// shader_distance < distance)
		// lt = v_dot(ray.n_hit, light.dir) > 0 ? v_dot(ray.n_hit, light.dir) : v_dot(-ray.n_hit, light.dir);
		if (lt > 0)
		{
			if (h.specular > 0)
					light_intensity += get_shiness(lt, h.specular, light_intensity, ray, light);
			if (shader_distance < distance)
			{
				light_intensity = lt * l[i].intence;
			}
			ret_col += vis * light_intensity * lt;
		}
	}
	return (ret_col);
}