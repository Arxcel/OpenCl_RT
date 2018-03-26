/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:15:03 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/26 13:04:42 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H
# include "ft_rt.cl"
# define O_SPHERE		1
# define O_CON			2
# define O_PLANE		3
# define O_CYL			4
# define O_DISK			5
# define O_TRIANGLE		6
# define O_PARABOLOID	7
# define O_SQUARE		8
# define O_CUBE			9
# define O_CAPSULA		10
# define O_BARBELL		11
# define O_ELIPSOID		12
# define O_CDDISK		13
# define O_RING			14
# define L_PAR			1
# define L_LAMP			2
# define L_AMBIENT		3
# define L_AREA			4
# define T_STD			0
# define T_CHECK		1
# define T_GRAD1		2
# define T_GRAD2		3
# define T_CIRC			4
# define T_BRICK		5
# define T_CUSTOM1		6
# define T_CUSTOM2		7
# define T_CUSTOM3		8
# define T_CUSTOM4		9

typedef struct		s_object
{
	t_vector		color;
	t_vector		dir;
	t_vector		pos1;
	t_vector		pos2;
	t_vector		pos3;
	float			radius;
	float			angle;
	float			reflect;
	float			refract;
	float			ior;
	float			min;
	float			max;
	unsigned short	tex_scale;
	short			type;
	short			mini_type;
	unsigned short	specular;
	unsigned short	tex_id;
	short			tex_angle;
	unsigned short	is_neg;
}					t_object;

typedef struct		s_light
{
	short			type;
	float			intence;
	float			ang;
	t_vector		color;
	t_vector		pos;
	t_vector		pos2;
	t_vector		dir;
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
