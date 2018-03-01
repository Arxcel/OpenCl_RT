/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:09:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/01 13:02:09 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MY_CL_H
# define _MY_CL_H
# ifdef __APPLE__
#  include "OpenCL/opencl.h"
# else
#  include "CL/cl.h"
# endif
# include <stdio.h>

typedef struct			s_cl{
	cl_platform_id		*platforms;
	char				platform_name[128];
	cl_device_id		*devices;
	char				device_name[128];
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				input_buf;
	cl_mem				output_buf;
}						t_cl;
typedef struct			s_args
{
	int					number_of_values;
	float				*input_floats;
}						t_args;
void					cl_error_msg(const char *errinfo,
				const void *private_info, size_t cb, void *user_data);
void					cl_get_platforms(t_cl *cl);
void					cl_get_devices(t_cl *cl);
void					cl_create_context(t_cl *cl);
void					cl_create_queue(t_cl *cl);
void					cl_create_kernel(t_cl *cl, const char *kernel_name);
void					cl_create_program(t_cl *cl, const char *src_dir,
				const char *program_text);
void					cl_create_input_buf(t_cl *cl, t_args args, size_t size);
void					cl_create_res_buf(t_cl *cl, size_t size);
void					cl_set_args(t_cl *cl, void *a,
				size_t arg_size, cl_uint arg_index);
void					cl_exec_kernel(t_cl *cl,
				cl_uint size_wd, const size_t *val);
void					cl_init(t_cl *cl);
void					cl_get_res(t_cl *cl, size_t size, unsigned int *res);
void					cl_set_out_arg(t_cl *cl, cl_uint arg_index);
int						ft_printf(const char *format, ...);
#endif
