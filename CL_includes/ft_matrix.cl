/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:42:57 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/23 19:41:21 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.cl"

t_matrix	m_mult_m(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	t_matrix	c;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			c.r[i][j] = a.r[i][0] * b.r[0][j] + a.r[i][1] * b.r[1][j] +
					a.r[i][2] * b.r[2][j] + a.r[i][3] * b.r[3][j];
		}
	}
	return (c);
}

t_matrix	m_transpose(t_matrix a)
{
	int			i;
	int			j;
	t_matrix	c;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			c.r[i][j] = a.r[j][i];
	}
	return (c);
}

t_vector	m_mult_p(t_matrix m, t_vector v)
{
	float		a;
	float		b;
	float		c;
	float		w;
	t_vector	res;

	a = v[0] * m.r[0][0] + v[1] * m.r[1][0] + v[2] * m.r[2][0] + m.r[3][0];
	b = v[0] * m.r[0][1] + v[1] * m.r[1][1] + v[2] * m.r[2][1] + m.r[3][1];
	c = v[0] * m.r[0][2] + v[1] * m.r[1][2] + v[2] * m.r[2][2] + m.r[3][2];
	w = v[0] * m.r[0][3] + v[1] * m.r[1][3] + v[2] * m.r[2][3] + m.r[3][3];
	res[0] = a / w;
	res[1] = b / w;
	res[2] = c / w;
	return (res);
}

t_vector	m_mult_v(t_matrix m, t_vector v)
{
	float		a;
	float		b;
	float		c;
	t_vector	res;

	a = v[0] * m.r[0][0] + v[1] * m.r[1][0] + v[2] * m.r[2][0];
	b = v[0] * m.r[0][1] + v[1] * m.r[1][1] + v[2] * m.r[2][1];
	c = v[0] * m.r[0][2] + v[1] * m.r[1][2] + v[2] * m.r[2][2];
	res[0] = a;
	res[1] = b;
	res[2] = c;
	return (res);
}

t_matrix33	m_mult_m33(t_matrix33 a, t_matrix33 b)
{
	int			i;
	int			j;
	t_matrix33	c;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			c.r[i][j] = a.r[i][0] * b.r[0][j] + a.r[i][1] * b.r[1][j] +
						a.r[i][2] * b.r[2][j];
		}
	}
	return (c);
}

t_matrix33	m_transpose33(t_matrix33 a)
{
	int			i;
	int			j;
	t_matrix33	c;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			c.r[i][j] = a.r[j][i];
	}
	return (c);
}

t_vector2	m_mult_p33(t_matrix33 m, t_vector2 v)
{
	float		a;
	float		b;
	float		w;
	t_vector2	res;

	a = v[0] * m.r[0][0] + v[1] * m.r[1][0];
	b = v[0] * m.r[0][1] + v[1] * m.r[1][1];
	w = v[0] * m.r[0][2] + v[1] * m.r[1][2];
	res[0] = a / w;
	res[1] = b / w;
	return (res);
}

t_vector2	m_mult_v33(t_matrix33 m, t_vector2 v)
{
	float		a;
	float		b;
	float		c;
	t_vector2	res;

	a = v[0] * m.r[0][0] + v[1] * m.r[1][0];
	b = v[0] * m.r[0][1] + v[1] * m.r[1][1];
	c = v[0] * m.r[0][2] + v[1] * m.r[1][2];
	res[0] = a;
	res[1] = b;
	return (res);
}