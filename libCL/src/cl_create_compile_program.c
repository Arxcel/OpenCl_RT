/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_create_compile_program.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:08:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/21 16:15:13 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void			cl_create_program(t_cl *cl,
								const char *src_dir, const char *program_text)
{
	size_t				*string_lengths;
	cl_uint				d_count;
	cl_int				res;

	string_lengths = NULL;
	d_count = 0;
	cl->program = clCreateProgramWithSource(cl->context, 1,
							&program_text, string_lengths, &res);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while creating the program. Code:[%d]\n", res);
		exit(1);
	}
	res = clBuildProgram(cl->program, d_count, NULL, src_dir, NULL, NULL);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while compiling the program. Code:[%d]\n", res);
		exit(1);
	}
}
