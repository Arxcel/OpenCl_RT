/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_get_platforms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:08:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/21 16:16:37 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_get_platforms(t_cl *cl)
{
	cl_uint			num_entr;
	cl_uint			num_platforms;
	cl_int			res;

	num_entr = 1;
	cl->platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * num_entr);
	res = clGetPlatformIDs(num_entr, cl->platforms, &num_platforms);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while getting available platforms. Code:[%d]\n", res);
		exit(1);
	}
	clGetPlatformInfo(cl->platforms[0], CL_PLATFORM_NAME,
					128, cl->platform_name, NULL);
}
