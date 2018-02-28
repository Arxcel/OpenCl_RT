/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:57 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/28 18:38:33 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

unsigned int					set_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r << 16) | (g << 8) | b);
}

unsigned int		set_color(int hexValue)
{
	return set_rgb(((hexValue >> 16) & 0xFF) / 255.0, ((hexValue >> 8) & 0xFF) / 255.0, ((hexValue) & 0xFF) / 255.0);
}


int					main(void) {
	clock_t start = clock();
	char *text;
	text = ft_strdup("\n" \
			"#include \"ft_rtv1.h\"                        \n" \
			"#include \"conus.cl\"                         \n" \
			"#include \"cylinder.cl\"                      \n" \
			"#include \"ft_matrix.cl\"                     \n" \
			"#include \"ft_vector.cl\"                     \n" \
			"#include \"renderer.cl\"                      \n" \
			"#include \"rotation.cl\"                      \n" \
			"#include \"sphere.cl\"                        \n" \
			"#include \"utils.cl\"                         \n" \
			"#include \"plane.cl\"                         \n" \
			"                                              \n" \
			"kernel void                                   \n" \
			"   kernel_entry                               \n" \
			"  (global t_object *object                    \n" \
			"  , global t_light *light                     \n" \
			"  , global t_camera *camera                   \n" \
			"  , global unsigned int *img_buf)             \n" \
			"{                                             \n" \
			"  t_scene		scene;                         \n" \
			"  unsigned int col;                           \n" \
			"  int x;                                      \n" \
			"  int y;                                      \n" \
			"                                              \n" \
			"  x = get_global_id(0);                       \n" \
			"  y = get_global_id(1);                       \n" \
			"  scene.object = (t_object*)object;           \n" \
			"  scene.light = (t_light*)light;              \n" \
			"  scene.camera = (t_camera*)camera;           \n" \
			"  col =  ft_renderer(object,light,camera,x,y);\n" \
			"  *(img_buf + x + y * 1280) = col;            \n" \
			"}                                             \n");

	t_cl cl;
	t_sdl sdl;
	size_t wd[2] = {1280, 600};
	t_scene s;
	sdl.win_w = WIN_W;
	sdl.win_h = WIN_H;
	sdl_init(&sdl);
	unsigned int img[1280 * 600];

	if (!(s.object = (t_object*)ft_memalloc(sizeof(t_object) * 2)))
	{
		ft_printf("Error allocating memory");
		exit(1);
	}
	s.object[0].type = O_SPHERE;
	s.object[0].point = (t_vector){0, 0, -300};
	s.object[0].radius = 100;
	s.object[0].color = (t_vector){0.8 ,0.1, 0.1};
	s.object[0].shape = 100;
	s.object[1].type = 0;
	if (!(s.camera = (t_camera*)ft_memalloc(sizeof(t_camera) * 2)))
	{
		ft_printf("Error allocating memory");
		exit(1);
	}
	s.camera[0].type = 1;
	s.camera[0].pos = (t_vector){0, 0, 0};
	s.camera[0].fov = 50;
	s.camera[0].dias = 0.3;
	s.camera[0].rot = (t_vector){0, 0, 0};
	s.camera[1].type = 0;
	if (!(s.light = (t_light *)ft_memalloc(sizeof(t_light) * 2)))
	{
		ft_printf("Error allocating memory");
		exit(1);
	}
	s.light[0].type = L_SUN;
	s.light[0].pos = (t_vector){500, 0, 500};
	s.light[0].color = (t_vector){1, 1, 1};
	s.light[1].type = 0;

	cl_init(&cl);
	cl_create_program(&cl, "-I ./cl_includes/", text);
	cl_create_kernel(&cl, "kernel_entry");
//	cl_create_input_buf(&cl, a, sizeof(a));
	cl_create_res_buf(&cl, (size_t)(size_t)1280 * 600 * sizeof(unsigned int));
	cl_set_args(&cl, s.object, 2 * sizeof(t_object), 0);
	cl_set_args(&cl, s.light, 2 * sizeof(t_light), 1);
	cl_set_args(&cl, s.camera, 2 * sizeof(t_camera), 2);
	cl_set_args(&cl, img, (size_t)1280 * 600, 3);
	cl_exec_kernel(&cl, 2, wd);
	///results = cl_get_res(&cl, (size_t)1280 * 600);
	free(text);
	int i = -1;
	while (++i < 1280 * 600)
	{
		sdl.img.pixels[i] = img[i];
		if (img[i])
			printf("%#x\n", sdl.img.pixels[i]);
	}
	sdl_put_image(&sdl);
	while (sdl.running)
	{
		sdl_hook(&sdl);
	}
	clock_t stop = clock();
	float elapsed = (float) (stop - start) / CLOCKS_PER_SEC;
	printf("\nTime elapsed: %.5f\n", elapsed);
	return (0);
}