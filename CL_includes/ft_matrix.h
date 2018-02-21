/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:34:23 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/24 17:25:15 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# include "ft_rtv1.h"

typedef float	t_mrow __attribute__((vector_size(sizeof(float)*4)));
typedef struct	s_matrix
{
	t_mrow		r[4];
}				t_matrix;

t_matrix		m_mult_m(t_matrix a, t_matrix b);
t_matrix		m_transpose(t_matrix a);
t_vector		m_mult_v(t_matrix m, t_vector v);
t_vector		m_mult_p(t_matrix m, t_vector v);
#endif
