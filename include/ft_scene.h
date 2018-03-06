/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:15:03 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/06 10:01:19 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H
# define O_SPHERE	1
# define O_CON		2
# define O_PLANE	3
# define O_CYL		4
# define L_SUN		1

typedef float	t_vector __attribute__((vector_size(sizeof(float)*3)));
typedef struct		s_object
{
	short			type;
	t_vector		color;
	t_vector		point;
	float			radius;
	float			angle;
	t_vector		dir;
	float			p;
	int				shape;
}					t_object;
typedef struct		s_light
{
	short			type;
	t_vector		color;
	t_vector		pos;
}					t_light;
typedef struct		s_camera
{
	short			type;
	t_vector		pos;
	t_vector		dir;
	t_vector		rot;
	float			fov;
	float			bias;
}					t_camera;
typedef struct		s_scene
{
	short			id;
	int				o_num;
	int				l_num;
	int				c_num;
	t_object		*object;
	t_light			*light;
	t_camera		*camera;
}					t_scene;
#endif
