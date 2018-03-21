/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:57 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/21 15:34:20 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"


static char			*get_text(void)
{
	char *text;
	text = ft_strdup("\n" \
		"#include \"ft_rtv1.h\"\n#include \"sh_conus.cl\"\n" \
		"#include \"sh_disk.cl\"\n#include \"sh_cylinder.cl\"\n" \
		"#include \"ft_matrix.cl\"\n#include \"ft_vector.cl\"\n" \
		"#include \"renderer.cl\"\n#include \"rotation.cl\"\n" \
		"#include \"sh_sphere.cl\"\n#include \"utils.cl\"\n#include \"ft_light.cl\" \n" \
		"#include \"sh_plane.cl\"\n#include \"sh_triangle.cl\"\n" \
		"#include \"sh_paraboloid.cl\"\n#include \"sh_square.cl\"\n" \
		"kernel void kernel_entry (global t_object *object\n" \
		", global t_light *light , global t_camera *camera\n" \
		", global unsigned int *img_buf){\n" \
		" size_t img_w = get_global_size(0);\n" \
		" size_t img_h = get_global_size(1);\n" \
		"unsigned int col;int x;int y;x = get_global_id(0);\n" \
		"y = get_global_id(1);\n" \
		"col =  ft_renderer(object,light,camera,x,y,img_w,img_h);\n"\
		"*(img_buf + x + y * img_w) = col;}\n");
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
	printf("OpenCl Execution time is: %0.3f milliseconds \n", cl_get_exec_time(cl));
	cl_free_all_args(4, cl->args);
}

int					main(int ac, char **av)
{
	t_main	m;

	ui_and_sdl_init(&m);
	if (ac != 2)
		put_error("Wrong number of arguments.");
	get_scene(av[1], &m.s);
	draw(&m.cl, &m.sdl, &m.s);
	render_scene_and_ui(&m);
	sdl_loop(&m);
	return (0);
}
