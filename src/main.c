/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:57 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/15 17:00:21 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static char			*get_text(void)
{
	char *text;

	text = ft_strdup("\n" \
		"#include \"ft_rtv1.h\"\n#include \"conus.cl\"\n" \
		"#include \"disk.cl\"\n#include \"cylinder.cl\"\n" \
		"#include \"ft_matrix.cl\"\n#include \"ft_vector.cl\"\n" \
		"#include \"renderer.cl\"\n#include \"rotation.cl\"\n" \
		"#include \"sphere.cl\"\n#include \"utils.cl\"\n" \
		"#include \"plane.cl\"\n#include \"sh_triangle.cl\"\n" \
		"kernel void kernel_entry (global t_object *object\n" \
		", global t_light *light , global t_camera *camera\n" \
		", global unsigned int *img_buf){t_scene scene;   \n" \
		"unsigned int col;int x;int y;x = get_global_id(0);\n" \
		"y = get_global_id(1);scene.object = (t_object*)object;\n" \
		"scene.light = (t_light*)light;scene.camera = (t_camera*)camera;\n" \
		"col =  ft_renderer(object,light,camera,x,y);\n"\
		"*(img_buf + x + y * 1280) = col;}\n");
	return (text);
}

static void			draw(t_cl *cl, t_sdl *sdl, t_scene *s)
{
	cl_init(cl);
	cl->flags = set_flags("./cl_includes/");
	cl->text = get_text();
	cl_create_program(cl, cl->flags, cl->text);
	cl_create_kernel(cl, "kernel_entry");
	re_draw(cl, sdl, s);
	free(cl->flags);
	free(cl->text);
}

void				re_draw(t_cl *cl, t_sdl *sdl, t_scene *s)
{
	move_camera(s);
	cl_set_args(cl, s->object, s->o_num * sizeof(t_object), 0);
	cl_set_args(cl, s->light, s->l_num * sizeof(t_light), 1);
	cl_set_args(cl, s->camera, s->c_num * sizeof(t_camera), 2);
	cl_set_out_arg(cl, (size_t)sdl->img.w *
				sdl->img.h * sizeof(unsigned int), 3);
	cl_exec_kernel(cl, 2, cl->work_dim);
	cl_get_res(cl, (size_t)sdl->img.w *
				sdl->img.h * sizeof(unsigned int), sdl->img.pixels, 3);
	cl_free_all_args(4, cl->args);
}

int					main(int ac, char **av)
{
	clock_t	start;
	t_main	m;
	clock_t	stop;
	float	elapsed;

	m.cl.work_dim[0] = WIN_W;
	m.cl.work_dim[1] = WIN_H;
	m.sdl.win_w = WIN_W;
	m.sdl.win_h = WIN_H;
	start = clock();
	sdl_init(&m.sdl);
	if (ac != 2)
		put_error("Wrong number of arguments.");
	get_scene(av[1], &m.s);
	draw(&m.cl, &m.sdl, &m.s);
	stop = clock();
	elapsed = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("\nTime elapsed: %.5f\n", elapsed);
	sdl_put_image(&m.sdl);
	sdl_loop(&m);
	return (0);
}
