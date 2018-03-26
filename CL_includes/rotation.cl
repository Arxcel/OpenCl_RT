/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:23:10 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/22 22:25:31 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.cl"

static t_matrix			v_rot_x(float angle)
{
	t_matrix	a;
	float		an;

	an = -radians(angle);
	a.r[0] = (t_mrow){1, 0, 0, 0};
	a.r[1] = (t_mrow){0, native_cos(an), -native_sin(an), 0};
	a.r[2] = (t_mrow){0, native_sin(an), native_cos(an), 0};
	a.r[3] = (t_mrow){0, 0, 0, 1};
	return (a);
}

static t_matrix			v_rot_y(float angle)
{
	t_matrix	a;
	float		an;

	an = -radians(angle);
	a.r[0] = (t_mrow){native_cos(an), 0, native_sin(an), 0};
	a.r[1] = (t_mrow){0, 1, 0, 0};
	a.r[2] = (t_mrow){-native_sin(an), 0, native_cos(an), 0};
	a.r[3] = (t_mrow){0, 0, 0, 1};
	return (a);
}

static t_matrix			v_rot_z(float angle)
{
	t_matrix	a;
	float		an;

	an = -radians(angle);
	a.r[0] = (t_mrow){native_cos(an), -native_sin(an), 0, 0};
	a.r[1] = (t_mrow){native_sin(an), native_cos(an), 0, 0};
	a.r[2] = (t_mrow){0, 0, 1, 0};
	a.r[3] = (t_mrow){0, 0, 0, 1};
	return (a);
}

t_vector				ft_rotate(t_vector vector, t_vector angle)
{
	t_vector a;

	a = m_mult_v(v_rot_x(angle[0]), vector);
	vector = a;
	a = m_mult_v(v_rot_y(angle[1]), vector);
	vector = a;
	a = m_mult_v(v_rot_z(angle[2]), vector);
	return (a);
}
