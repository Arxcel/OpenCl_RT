/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:25:54 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (!ft_strlen((char *)needle))
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = i;
		while (haystack[k] == needle[j] && needle[j] != '\0' && k < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	return (0);
}
