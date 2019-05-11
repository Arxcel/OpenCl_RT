/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 02:07:00 by vkozlov           #+#    #+#             */
/*   Updated: 2019/05/11 14:54:21 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_init(t_cl *cl)
{
	cl_get_platforms(cl);
	cl_get_devices(cl);
	cl_create_context(cl);
	cl_create_queue(cl);
	ft_printf("platform_name: %s\n", cl->platform_name);
	ft_printf("device_name: %s\n", cl->device_name);
}
