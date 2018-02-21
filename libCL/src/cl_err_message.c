/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_err_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:44:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/07 17:44:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_cl.h"

void	cl_error_msg(const char *errinfo, const void *private_info,
							size_t cb, void *user_data)
{
	(void)private_info;
	(void)cb;
	(void)user_data;
	ft_printf("Error while working in the context: %s\n", errinfo);
}
