/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_create_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:50:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/18 15:46:39 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_create_queue(t_cl *cl)
{
	cl_int							res;
	cl_command_queue_properties		c_properties;

	c_properties = CL_QUEUE_PROFILING_ENABLE;
	cl->commands = clCreateCommandQueue(cl->context, cl->devices[0],
										c_properties, &res);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while creating the command queue. Code:[%d]\n", res);
		exit(1);
	}
}
