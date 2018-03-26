/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:34:23 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/23 19:57:26 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# include "ft_rt.cl"

typedef float	t_mrow __attribute__((vector_size(sizeof(float)*4)));
typedef float	t_mrow3 __attribute__((vector_size(sizeof(float)*3)));

typedef struct	s_matrix
{
	t_mrow		r[4];
}				t_matrix;

t_matrix		m_mult_m(t_matrix a, t_matrix b);
t_matrix		m_transpose(t_matrix a);
t_vector		m_mult_v(t_matrix m, t_vector v);
t_vector		m_mult_p(t_matrix m, t_vector v);
t_vector		v_cross(t_vector a, t_vector b);

typedef struct	s_matrix33
{
	t_mrow3		r[3];
}				t_matrix33;

t_matrix33		m_mult_m33(t_matrix33 a, t_matrix33 b);
t_matrix33		m_transpose33(t_matrix33 a);
t_vector2		m_mult_v33(t_matrix33 m, t_vector2 v);
t_vector2		m_mult_p33(t_matrix33 m, t_vector2 v);
#endif
