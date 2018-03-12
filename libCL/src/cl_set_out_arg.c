/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_set_out_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:52:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/12 13:01:18 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_set_out_arg(t_cl *cl, size_t size, cl_uint arg_index)
{
	cl_int			res;

	cl->args[arg_index] = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY, size,
									NULL, &res);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while initializing output data. Code:[%d]\n", res);
		exit(1);
	}
	res = clSetKernelArg(cl->kernel, arg_index,
		sizeof(cl_mem), (void*)&cl->args[arg_index]);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while setting kernel arguments. Code:[%d]\n", res);
		exit(1);
	}
}
