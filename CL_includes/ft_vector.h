/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:15:03 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/21 16:48:18 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef float	t_vector __attribute__((vector_size(sizeof(float)*3)));

float				v_length(t_vector v);
float				v_dot(t_vector v1, t_vector v2);
t_vector			v_normalize(t_vector v);
t_vector			v_mult_d(t_vector v, float d);
t_vector			v_div_d(t_vector v, float d);
t_vector            v_cross(t_vector a, t_vector b);
t_vector    		v_mult_v(t_vector v1, t_vector v2);
#endif
