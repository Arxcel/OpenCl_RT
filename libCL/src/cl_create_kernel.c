/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_create_kernel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:26:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/07 18:26:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_create_kernel(t_cl *cl, const char *kernel_name)
{
	cl_int			res;

	cl->kernel = clCreateKernel(cl->program, kernel_name, &res);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while creating of the kernel. Code:[%d]\n", res);
		exit(1);
	}
}
