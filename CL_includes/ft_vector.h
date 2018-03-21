/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:15:03 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/21 18:26:30 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef float	t_vector __attribute__((vector_size(sizeof(float)*3)));
typedef float	t_vector2 __attribute__((vector_size(sizeof(float)*2)));

float				v_length(t_vector v);
float				v_dot(t_vector v1, t_vector v2);
t_vector			v_normalize(t_vector v);
t_vector			v_mult_d(t_vector v, float d);
t_vector			v_div_d(t_vector v, float d);
t_vector            v_cross(t_vector a, t_vector b);
t_vector2			v_normalize2(t_vector2 v);
t_vector2			v_mult_d2(t_vector2 v, float d);
t_vector2			v_div_d2(t_vector2 v, float d);
float				v_length2(t_vector2 v);
float				v_dot2(t_vector2 v1, t_vector2 v2);
#endif
