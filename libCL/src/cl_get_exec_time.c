/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_get_exec_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:49:18 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/24 13:26:27 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

double	cl_get_exec_time(t_cl *cl)
{
	cl_ulong	time_start;
	cl_ulong	time_end;

	clGetEventProfilingInfo(cl->e, CL_PROFILING_COMMAND_START,
									sizeof(time_start), &time_start, NULL);
	clGetEventProfilingInfo(cl->e, CL_PROFILING_COMMAND_END,
										sizeof(time_end), &time_end, NULL);
	return ((time_end - time_start) / 1000000.0);
}
