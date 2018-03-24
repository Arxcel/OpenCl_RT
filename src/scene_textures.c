/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:39:56 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/24 21:34:27 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static int				set_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r << 16) | (g << 8) | b);
}

static unsigned int		get_col_by_i(void *ptr, int i)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ptr;
	return (set_rgb(tmp[i + 2], tmp[i + 1], tmp[i]));
}

static void				load_texture(unsigned int *pixels, const char *path)
{
	SDL_Surface		*sur;
	int				i;
	int				size;
	int				k;

	i = -1;
	size = 256 * 256;
	k = 0;
	sur = IMG_Load(path);
	if (!sur || sur->w != 256 || sur->h != 256)
		put_error("The standart texture was deleted or changed.");
	while (++i < size)
	{
		pixels[i] = get_col_by_i(sur->pixels, k);
		k += 4;
	}
	SDL_FreeSurface(sur);
}

static void				generate_perlin(unsigned int *pixels)
{
	int				i;
	int				size;
	unsigned int	c[3];
	float			p;

	i = -1;
	size = 256 * 256;
	while (++i < size)
	{
		p = perlin2d(i, i / 256, 0.1, 4);
		p = fabs(p);
		p = p > 1 ? 1 : p;
		c[0] = p * 256;
		c[1] = p * 256;
		c[2] = p * 256;
		pixels[i] = (((int)c[0] << 16) | ((int)c[1] << 8) | (int)c[2]);
	}
}

void					get_scene_textures(t_main *m)
{
	int i;

	i = -1;
	while (++i < N_TEX)
		m->s.tex[i] = sdl_create_image(256, 256);
	load_texture(m->s.tex[0].pixels, "textures/scene_textures/tex1.png");
	load_texture(m->s.tex[1].pixels, "textures/scene_textures/tex2.png");
	load_texture(m->s.tex[2].pixels, "textures/scene_textures/tex3.png");
	load_texture(m->s.tex[3].pixels, "textures/scene_textures/tex4.png");
	generate_perlin(m->s.tex[4].pixels);
}
