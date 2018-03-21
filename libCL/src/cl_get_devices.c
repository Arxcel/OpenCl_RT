/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_get_devices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:38:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/21 23:01:25 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_get_devices(t_cl *cl)
{
	cl_uint		max_devices;
	cl_uint		num_devices;
	cl_int		res;

	max_devices = 3;
	cl->devices = (cl_device_id*)malloc(max_devices * sizeof(cl_device_id));
	res = clGetDeviceIDs(cl->platforms[0], CL_DEVICE_TYPE_GPU, max_devices,
						cl->devices, &num_devices);
	if (res != CL_SUCCESS)
	{
		res = clGetDeviceIDs(cl->platforms[0], CL_DEVICE_TYPE_CPU, max_devices,
							cl->devices, &num_devices);
		if (res != CL_SUCCESS)
		{
			ft_printf("Error while getting devices. Code:[%d]\n", res);
			exit(1);
		}
	}
	clGetDeviceInfo(cl->devices[1], CL_DEVICE_NAME, 128, cl->device_name, NULL);
	printf("device name %s\n", cl->device_name);
}
