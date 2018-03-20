/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_smooth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:12:46 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/20 20:34:27 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static unsigned int		multiple_rgb(unsigned int col, float coef)
{
	t_color		tmp;

	tmp.col = col;
	tmp.argb.red = (unsigned char)(tmp.argb.red * coef);
	tmp.argb.green = (unsigned char)(tmp.argb.green * coef);
	tmp.argb.blue = (unsigned char)(tmp.argb.blue * coef);
	return (tmp.col);
}

static void				smoth_matrix(unsigned int **m)
{
	m[0][0] = (0.5f * m[0][0]);
	m[0][1] = (0.75f * m[0][1]);
	m[0][2] = (0.75f * m[0][2]);
	m[1][0] = (0.75f * m[1][0]);
	m[1][2] = (0.75f * m[1][2]);
	m[2][0] = (0.5f * m[2][0]);
	m[2][1] = (0.75f * m[2][1]);
	m[2][2] = (0.5f * m[2][2]);
}

static void				contrast_matrix(unsigned int **m)
{
	m[0][0] = (-1 * m[0][0]);
	m[0][1] = (-1 * m[0][1]);
	m[0][2] = (-1 * m[0][2]);
	m[1][0] = (-1 * m[1][0]);
	m[1][2] = (-1 * m[1][2]);
	m[2][0] = (-1 * m[2][0]);
	m[2][1] = (-1 * m[2][1]);
	m[2][2] = (-1 * m[2][2]);
	m[1][1] = (9 * m[1][1]);
}

static unsigned int		test_one(unsigned int **m)
{
	unsigned int		res;

	res = m[0][0] + m[0][1] + m[0][2] +
	m[1][0] + m[1][1] + m[1][2] +
	m[2][0] + m[2][1] + m[2][2];
	res = res / 3;
	free_matrix(m);
	return (res);
}

static unsigned int		test_two(unsigned int **m)
{
	unsigned int		res;
	unsigned int		tmp[9];
	int					i;
	int					j;
	unsigned int		buf;

	tmp[0] = m[0][0];
	tmp[1] = m[0][1];
	tmp[2] = m[0][2];
	tmp[3] = m[1][0];
	tmp[4] = m[1][1];
	tmp[5] = m[1][2];
	tmp[6] = m[2][0];
	tmp[7] = m[2][1];
	tmp[8] = m[2][2];
	// res = m[0][0] + m[0][1] + m[0][2] +
	// m[1][0] + m[1][1] + m[1][2] +
	// m[2][0] + m[2][1] + m[2][2];
	// res = res / 6;
	free_matrix(m);
	i = -1;
	while (++i < 9)
	{
		j = i;
		while (++j < 9)
		{
			if (tmp[i] > tmp[j])
			{
				buf = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = buf;
			}
		}
	}
	return ((tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] + tmp[5] + tmp[6] + tmp[7] + tmp[8]) / 6);
}

unsigned int			set_smooth(t_main *main, size_t x, size_t y, unsigned int *in)
{
	unsigned int		**m;

	m = get_matrix(main, x, y, in);
	// smoth_matrix(m);
	// contrast_matrix(m);
	// return (ae_calc_matrix(m, 6));
	return (test_one(m));
	// return (test_two(m));
}