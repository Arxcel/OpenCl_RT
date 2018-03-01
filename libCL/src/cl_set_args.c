/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:52:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/01 20:11:43 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_set_args(t_cl *cl, void *a, size_t arg_size, cl_uint arg_index)
{
	cl_mem			data;
	cl_int			res;

	data = clCreateBuffer(cl->context, 0, arg_size, NULL, &res);
	if ((res = clEnqueueWriteBuffer(cl->commands, data, CL_TRUE, 0,
								arg_size, a, 0, NULL, NULL)) != CL_SUCCESS)
	{
		ft_printf("Error while creating args buffer. Code:[%d]\n", res);
		exit(1);
	}
	res = clSetKernelArg(cl->kernel, arg_index, sizeof(data), &data);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while setting kernel arguments. Code:[%d]\n", res);
		exit(1);
	}
}
