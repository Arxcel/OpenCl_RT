/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_create_context.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:42:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/21 23:02:18 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_create_context(t_cl *cl)
{
	cl_context_properties	*properties;
	cl_uint					used_devices;
	cl_int					res;

	properties = 0;
	used_devices = 1;
	cl->context = clCreateContext(properties, used_devices,
							&cl->devices[1], &cl_error_msg, NULL, &res);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while creating the context. Code:[%d]\n", res);
		exit(1);
	}
}
