/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 00:28:56 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*buf1;
	char			*buf2;
	unsigned int	n;
	unsigned int	len;

	buf1 = dest;
	buf2 = src;
	n = size;
	if (size == 0)
		return (ft_strlen(src));
	while (n-- && *buf1)
		buf1++;
	len = buf1 - dest;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(buf2));
	while (*buf2)
	{
		if (n != 1 && n--)
			*buf1++ = *buf2;
		buf2++;
	}
	*buf1 = '\0';
	return (len + (buf2 - src));
}
