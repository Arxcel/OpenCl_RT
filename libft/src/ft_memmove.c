/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 08:19:55 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (tmp2 < tmp1)
	{
		tmp1 += len;
		tmp2 += len;
		while (len--)
		{
			tmp1--;
			tmp2--;
			*tmp1 = *tmp2;
		}
	}
	else
		while (len--)
		{
			*tmp1 = *tmp2;
			tmp1++;
			tmp2++;
		}
	return (dst);
}
