/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:57 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/26 16:31:47 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

const char	*g_text = "\n" \
"#include \"ft_rt.cl\"\n#include \"sh_conus.cl\"\n" \
"#include \"sh_disk.cl\"\n#include \"sh_cylinder.cl\"\n" \
"#include \"ft_matrix.cl\"\n#include \"ft_vector.cl\"\n" \
"#include \"renderer.cl\"\n#include \"rotation.cl\"\n" \
"#include \"sh_sphere.cl\"\n#include \"utils.cl\"\n" \
"#include \"sh_ring.cl\"\n" \
"#include \"sh_plane.cl\"\n#include \"sh_triangle.cl\"\n" \
"#include \"sh_capsula.cl\"\n#include \"sh_barbell.cl\"\n" \
"#include \"patterns_textures.cl\"\n#include \"ft_light.cl\"\n" \
"#include \"sh_elipsoid.cl\"\n#include \"sh_cd_disk.cl\"\n" \
"#include \"sh_paraboloid.cl\"\n#include \"sh_square.cl\"\n" \
"kernel void kernel_entry (global t_object *o\n" \
", global t_light *l , global t_camera *c\n" \
", global unsigned int *tex1, global unsigned int *tex2\n" \
", global unsigned int *tex3, global unsigned int *tex4\n" \
", global unsigned int *perlin\n" \
", global unsigned int *img_buf){\n" \
" size_t img_w = get_global_size(0);\n" \
" size_t img_h = get_global_size(1);\n" \
"unsigned int col;int x;int y;x = get_global_id(0);\n" \
"y = get_global_id(1);\n" \
"col=ft_renderer(o,l,c,x,y,img_w,img_h,tex1,tex2,tex3,tex4,perlin);\n"\
"*(img_buf + x + y * img_w) = col;}\n";

static char			*get_text(void)
{
	char *text;

	text = ft_strdup((char*)g_text);
	return (text);
}

static void			draw(t_main *m)
{
	cl_init(&m->cl);
	m->cl.flags = set_flags("./cl_includes/");
	m->cl.text = get_text();
	cl_create_program(&m->cl, m->cl.flags, m->cl.text);
	cl_create_kernel(&m->cl, "kernel_entry");
	re_draw(&m->cl, &m->sdl, &m->s);
	free(m->cl.flags);
	free(m->cl.text);
}

void				re_draw(t_cl *cl, t_sdl *sdl, t_scene *s)
{
	move_camera(s);
	cl_s_a(cl, s->object, s->o_num * sizeof(t_object), 0);
	cl_s_a(cl, s->light, s->l_num * sizeof(t_light), 1);
	cl_s_a(cl, s->camera + s->cam, s->c_num * sizeof(t_camera), 2);
	cl_s_a(cl, s->tex[0].pixels, s->tex[0].w * s->tex[0].h * sizeof(int), 3);
	cl_s_a(cl, s->tex[1].pixels, s->tex[1].w * s->tex[1].h * sizeof(int), 4);
	cl_s_a(cl, s->tex[2].pixels, s->tex[2].w * s->tex[2].h * sizeof(int), 5);
	cl_s_a(cl, s->tex[3].pixels, s->tex[3].w * s->tex[3].h * sizeof(int), 6);
	cl_s_a(cl, s->tex[4].pixels, s->tex[4].w * s->tex[4].h * sizeof(int), 7);
	cl_set_out_arg(cl, sdl->img.w * sdl->img.h * sizeof(int), 8);
	cl_exec_kernel(cl, 2, cl->work_dim);
	cl_get_res(cl, sdl->img.w * sdl->img.h * sizeof(int), sdl->img.pixels, 8);
	printf("Last frame time: %0.3f milliseconds.\n", cl_get_exec_time(cl));
	clReleaseEvent(cl->e);
	cl_free_all_args(cl->args);
}

int					main(int ac, char **av)
{
	t_main			m;

	(void)av;
	ft_bzero(&m, sizeof(t_main));
	ui_and_sdl_init(&m);
	make_dependencies(&m);
	if (ac != 1)
		put_error("You dont need arguments.");
	get_scene("./textures/scene_textures/default_scene.json", &m.s);
	get_scene_textures(&m);
	draw(&m);
	render_scene_and_ui(&m);
	sdl_loop(&m);
	return (0);
}
