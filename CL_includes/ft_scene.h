/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:15:03 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/20 11:24:28 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H
# include "ft_rtv1.h"
# define O_SPHERE	1
# define O_CON		2
# define O_PLANE	3
# define O_CYL		4
# define O_DISK		5
# define O_TRIANGLE	6
# define O_PARABOLOID 7
# define L_DIR		1
# define L_LAMP		2
# define L_AMBIENT	3

typedef struct		s_object
{
	short			type;
	int				specular;
	float			radius;
	float			angle;
	float			reflect;
	float			refract;
	float			min;
	float			max;
	t_vector		color;
	t_vector		point;
	t_vector		dir;
	t_vector		p1;
	t_vector		p2;
	t_vector		p3;
}					t_object;

typedef struct		s_light
{
	short			type;
	float			intence;
	t_vector		color;
	t_vector		pos;
}					t_light;

typedef struct		s_camera
{
	short			type;
	float			fov;
	t_vector		pos;
	t_vector		dir;
	t_vector		rot;
}					t_camera;
#endif
