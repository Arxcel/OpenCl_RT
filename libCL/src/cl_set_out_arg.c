/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_set_out_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:52:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/01 13:01:35 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_set_out_arg(t_cl *cl, cl_uint arg_index)
{
	cl_int			res;

	res = clSetKernelArg(cl->kernel, arg_index, sizeof(cl_mem), (void*)&cl->output_buf);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while setting kernel arguments. Code:[%d]\n", res);
		exit(1);
	}
}
