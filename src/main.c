/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:57 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/01 20:19:44 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void put_vector(t_vector v)
{
	printf("[%f, %f, %f]\n", v[0], v[1], v[2]);
}

static void show_scene(t_scene *s)
{
	int i;

	i = 0;
	while (s->object[i].type)
	{
		printf("Objects №%d.\n", i);
		printf("Point:");
		put_vector(s->object[i].point);
		printf("Color:");
		put_vector(s->object[i].color);
		printf("Radius: %f\n", s->object[i].radius);
		i++;
	}
	i = 0;
	while (s->light[i].type)
	{
		printf("Light №%d.\n", i);
		printf("Point:");
		put_vector(s->light[i].pos);
		printf("Color:");
		put_vector(s->light[i].color);
		i++;
	}
	i = 0;
	while (s->camera[i].type)
	{
		printf("Camera №%d.\n", i);
		printf("Pos:");
		put_vector(s->camera[i].pos);
		printf("Dir:");
		put_vector(s->camera[i].dir);
		printf("Rot:");
		put_vector(s->camera[i].rot);
		printf("Bias: %f\n", s->camera[i].bias);
		printf("Fov: %f\n",s->camera[i].fov);

		i++;
	}
}

int					main(int ac, char **av) {

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
	sdl.win_w = WIN_W;
	sdl.win_h = WIN_H;
	sdl_init(&sdl);

	t_scene s;
	if (ac != 2)
		put_error("Wrong number of arguments.");
	get_scene(av[1], &s);

	// (void)ac;
	// (void)av;
	// if (!(s.object = (t_object*)ft_memalloc(sizeof(t_object) * 2)))
	// {
	// 	ft_printf("Error allocating memory");
	// 	exit(1);
	// }
	// s.object[0].type = O_SPHERE;
	// s.object[0].point = (t_vector){0, 0, -300};
	// s.object[0].radius = 100;
	// s.object[0].color = (t_vector){0.8 ,0.1, 0.1};
	// s.object[0].shape = 100;
	// s.object[1].type = 0;
	// if (!(s.camera = (t_camera*)ft_memalloc(sizeof(t_camera) * 2)))
	// {
	// 	ft_printf("Error allocating memory");
	// 	exit(1);
	// }
	// s.camera[0].type = 1;
	// s.camera[0].pos = (t_vector){0, 0, 0};
	// s.camera[0].fov = 50;
	// s.camera[0].bias = 0.3;
	// s.camera[0].rot = (t_vector){0, 0, 0};
	// s.camera[1].type = 0;
	// if (!(s.light = (t_light *)ft_memalloc(sizeof(t_light) * 2)))
	// {
	// 	ft_printf("Error allocating memory");
	// 	exit(1);
	// }
	// s.light[0].type = L_SUN;
	// s.light[0].pos = (t_vector){500, 0, 500};
	// s.light[0].color = (t_vector){1, 1, 1};
	// s.light[1].type = 0;

	show_scene(&s);
	// show_scene(s2);
	// put_error("BiDa");
	cl_init(&cl);
	cl_create_program(&cl, "-I ./cl_includes/", text);
	cl_create_kernel(&cl, "kernel_entry");
	cl_create_res_buf(&cl, (size_t)sdl.img.w * sdl.img.h * sizeof(unsigned int));
	cl_set_args(&cl, s.object, 2 * sizeof(t_object), 0);
	cl_set_args(&cl, s.light, 2 * sizeof(t_light), 1);
	cl_set_args(&cl, s.camera, 2 * sizeof(t_camera), 2);
	cl_set_out_arg(&cl, 3);
	cl_exec_kernel(&cl, 2, wd);
	cl_get_res(&cl, (size_t)sdl.img.w * sdl.img.h * sizeof(unsigned int), sdl.img.pixels);
	free(text);

	clock_t stop = clock();
	float elapsed = (float) (stop - start) / CLOCKS_PER_SEC;
	printf("\nTime elapsed: %.5f\n", elapsed);
	sdl_put_image(&sdl);
	while (sdl.running)
	{
		sdl_hook(&sdl);
	}
	return (0);
}