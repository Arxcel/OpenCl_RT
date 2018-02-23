/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_killer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:48:19 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/23 16:33:25 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sdl.h"

int					ft_killer(const char *reason)
{
	if (reason && *reason)
		ft_putendl_fd(reason, 2);
	exit(0);
}
