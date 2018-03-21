/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:52:42 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/21 10:13:26 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static unsigned int		get_0_0(t_main *main, size_t x, size_t y,
	unsigned int *in)
{
	if (x == 0 && y == 0)
		return (in[0]);
	else if (x == 0 && y)
		return (in[(y - 1) * main->sdl.img.w]);
	else if (y == 0 && x)
		return (in[x - 1]);
	return (in[x - 1 + (y - 1) * main->sdl.img.w]);
}

static unsigned int		get_0_2(t_main *main, size_t x, size_t y,
	unsigned int *in)
{
	if (x == 0 && (y + 1) == main->sdl.img.h)
		return (in[x + y * main->sdl.img.w]);
	else if (x && (y + 1) == main->sdl.img.h)
		return (in[x - 1 + y * main->sdl.img.w]);
	else if (x == 0 && (y + 1) < main->sdl.img.h)
		return (in [(y - 1) * main->sdl.img.w]);
	return (in[x - 1 + (y - 1) * main->sdl.img.w]);
}

static unsigned int		get_2_2(t_main *main, size_t x, size_t y,
	unsigned int *in)
{
	if ((x + 1) == main->sdl.img.w && (y + 1) == main->sdl.img.h)
		return (in[x + y * main->sdl.img.w]);
	else if ((x + 1) != main->sdl.img.w && (y + 1) == main->sdl.img.h)
		return (in[x + 1 + y * main->sdl.img.w]);
	else if ((x + 1) == main->sdl.img.w && (y + 1) != main->sdl.img.h)
		return (in[x + (y + 1) * main->sdl.img.w]);
	return (in[x + 1 + (y + 1) * main->sdl.img.w]);
}

static unsigned int		get_2_0(t_main *main, size_t x, size_t y,
	unsigned int *in)
{
	if ((x + 1) == main->sdl.img.w && y == 0)
		return (in[x + y * main->sdl.img.w]);
	else if ((x + 1) == main->sdl.img.w && y)
		return (in[x + (y - 1) * main->sdl.img.w]);
	else if ((x + 1) < main->sdl.img.w && y == 0)
		return (in[x - 1 + y * main->sdl.img.w]);
	return (in[x - 1 + (y - 1) * main->sdl.img.w]);
}

unsigned int		**get_matrix(t_main *main, size_t x, size_t y,
	unsigned int *in)
{
	unsigned int	**m;

	m = (unsigned int**)malloc(sizeof(unsigned int*) * 3);
	m[0] = (unsigned int*)malloc(sizeof(unsigned int) * 3);
	m[1] = (unsigned int*)malloc(sizeof(unsigned int) * 3);
	m[2] = (unsigned int*)malloc(sizeof(unsigned int) * 3);
	m[1][1] = in[y * main->sdl.img.w + x];

	m[0][0] = get_0_0(main, x, y, in);
	m[2][0] = get_2_0(main, x, y, in);
	m[0][2] = get_0_2(main, x, y, in);
	m[2][2] = get_2_2(main, x, y, in);

	m[1][0] = (y == 0) ? in[y * main->sdl.img.w + x] : in[(y - 1) * main->sdl.img.w + x];
	m[0][1] = (x == 0) ? in[y * main->sdl.img.w + x] :
		in[y * main->sdl.img.w + x - 1];
	m[1][2] = ((y + 1) == main->sdl.img.h) ? in[y * main->sdl.img.w + x] :
		in[(y + 1) * main->sdl.img.w + x];
	m[2][1] = ((x + 1) == main->sdl.img.w) ? in[y * main->sdl.img.w + x] :
		in[y * main->sdl.img.w + x + 1];
	return (m);
}
