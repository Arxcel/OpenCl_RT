/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:09:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/24 13:39:51 by vkozlov          ###   ########.fr       */
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
# define INDEX_NUM 8

typedef struct			s_cl{
	size_t				work_dim[2];
	cl_platform_id		*platforms;
	char				platform_name[128];
	cl_device_id		*devices;
	char				device_name[128];
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				args[INDEX_NUM];
	cl_event			e;
	char				*text;
	char				*flags;
}						t_cl;

typedef struct			s_args
{
	int					number_of_values;
	float				*input_floats;
}						t_args;

void					cl_error_msg(const char *errinfo,
								const void *private_info,
								size_t cb, void *user_data);
void					cl_get_platforms(t_cl *cl);
void					cl_get_devices(t_cl *cl);
void					cl_create_context(t_cl *cl);
void					cl_create_queue(t_cl *cl);
void					cl_create_kernel(t_cl *cl, const char *kernel_name);
void					cl_create_program(t_cl *cl, const char *src_dir,
								const char *program_text);
void					cl_s_a(t_cl *cl, void *a,
								size_t arg_size, cl_uint arg_index);
void					cl_exec_kernel(t_cl *cl,
								cl_uint size_wd, const size_t *val);
void					cl_init(t_cl *cl);
void					cl_get_res(t_cl *cl, size_t size,
								unsigned int *result, cl_uint arg_index);
void					cl_set_out_arg(t_cl *cl, size_t size,
								cl_uint arg_index);
int						ft_printf(const char *format, ...);
void					cl_free_all_args(cl_mem *args);
double					cl_get_exec_time(t_cl *cl);

#endif
