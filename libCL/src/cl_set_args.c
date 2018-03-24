/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:52:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/24 13:39:51 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_s_a(t_cl *cl, void *a, size_t arg_size, cl_uint arg_index)
{
	cl_int			res;

	cl->args[arg_index] = clCreateBuffer(cl->context, 0, arg_size, NULL, &res);
	if ((res = clEnqueueWriteBuffer(cl->commands,
				cl->args[arg_index], CL_TRUE, 0,
				arg_size, a, 0, NULL, NULL)) != CL_SUCCESS)
	{
		ft_printf("Error while creating args buffer. Code:[%d]\n", res);
		exit(1);
	}
	res = clSetKernelArg(cl->kernel, arg_index,
						sizeof(cl->args[arg_index]), &cl->args[arg_index]);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while setting kernel arguments. Code:[%d]\n", res);
		exit(1);
	}
}
