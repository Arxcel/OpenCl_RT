/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_create_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:02:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/21 16:15:38 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void		cl_create_input_buf(t_cl *cl, t_args args, size_t size)
{
	cl_event	data_input_copy_event;
	cl_int		res;

	cl->input_buf = clCreateBuffer(cl->context, CL_MEM_READ_ONLY, size,
								NULL, &res);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while initializing of input data. Code:[%d]\n", res);
		exit(1);
	}
	res = clEnqueueWriteBuffer(cl->commands, cl->input_buf, CL_TRUE, 0,
							size, &args, 0, NULL,
							&data_input_copy_event);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while writing input data. Code:[%d]\n", res);
		exit(1);
	}
}

void		cl_create_res_buf(t_cl *cl, size_t size)
{
	cl_int		res;

	cl->output_buf = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY, size,
									NULL, &res);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while initializing output data. Code:[%d]\n", res);
		exit(1);
	}
}
