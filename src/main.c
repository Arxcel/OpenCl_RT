/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:57 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/03 17:04:16 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

int					main(int ac, char **av)
{
	clock_t start = clock();
	char *text;
	t_scene s;
	t_cl cl;
	t_sdl sdl;
	size_t wd[2] = {1280, 600};

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
	sdl.win_w = WIN_W;
	sdl.win_h = WIN_H;
	sdl_init(&sdl);

	if (ac != 2)
		put_error("Wrong number of arguments.");
	get_scene(av[1], &s);

	cl_init(&cl);
	cl_create_program(&cl, "-I ./cl_includes/", text);
	cl_create_kernel(&cl, "kernel_entry");
	cl_create_res_buf(&cl, (size_t)sdl.img.w * sdl.img.h * sizeof(unsigned int));
	cl_set_args(&cl, s.object, 4 * sizeof(t_object), 0);
	cl_set_args(&cl, s.light, 3 * sizeof(t_light), 1);
	cl_set_args(&cl, s.camera, 2 * sizeof(t_camera), 2);
	cl_set_out_arg(&cl, 3);
	cl_exec_kernel(&cl, 2, wd);
	cl_get_res(&cl, (size_t)sdl.img.w * sdl.img.h * sizeof(unsigned int), sdl.img.pixels);
	free(text);

	clock_t stop = clock();
	float elapsed = (float) (stop - start) / CLOCKS_PER_SEC;
	printf("\nTime elapsed: %.5f\n", elapsed);
	sdl_put_image(&sdl);
	sdl_loop(&sdl);
	return (0);
}