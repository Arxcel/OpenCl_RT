/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_square.cl                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:42:03 by pprivalo          #+#    #+#             */
/*   Updated: 2018/01/23 20:42:16 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

short				capsula_cross(t_object *p, t_ray *r, float *t)
{
	t_object    bot;
	float       t_min;
	short       flag;

    t_min = INF;
    bzero(&bot, sizeof(t_object));
	bot.type = O_SPHERE;
	bot.color = p->color;
	bot.specular = p->specular;
	bot.refract = p->refract;
	bot.reflect = p->reflect;
	bot.ior = p->ior;
	bot.pos1 = p->pos1;
	bot.radius = p->radius;
	flag = sphere_cross(bot, r, &t_min);
	return(flag);
}

short				get_capsula_data(t_ray *ray, t_object cap, float t)
{
    if (cap.type == O_SPHERE)
    	get_sphere_data(ray, cap, t);
	return (1);
}