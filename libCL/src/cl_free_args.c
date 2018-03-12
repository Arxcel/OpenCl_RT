/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_free_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:07:40 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/12 14:12:34 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

static void		cl_free_arg(cl_mem arg)
{
	cl_int			res;

	res = clReleaseMemObject(arg);
	if (res != CL_SUCCESS)
	{
		ft_printf("Error while freeing args buffer. Code:[%d]\n", res);
		exit(1);
	}
}

void			cl_free_all_args(size_t args_num, cl_mem *args)
{
	size_t	i;

	i = 0;
	while (i < args_num)
	{
		cl_free_arg(args[i]);
		i++;
	}
}
