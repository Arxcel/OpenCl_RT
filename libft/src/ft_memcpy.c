/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:08:01 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *start;
	char *tmp1;
	char *tmp2;

	tmp1 = (char *)dst;
	tmp2 = (char *)src;
	start = dst;
	while (n--)
	{
		*(unsigned char *)tmp1 = *(unsigned char *)tmp2;
		tmp1++;
		tmp2++;
	}
	return (start);
}
