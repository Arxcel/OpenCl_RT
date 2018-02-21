/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:15:03 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/23 20:01:56 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef float	t_vector __attribute__((vector_size(sizeof(float)*3)));

t_vector			v_normalize(t_vector v);
t_vector			v_mult_d(t_vector v, float d);
t_vector			v_div_d(t_vector v, float d);
float				v_length(t_vector v);
float				v_dot(t_vector v1, t_vector v2);
#endif
