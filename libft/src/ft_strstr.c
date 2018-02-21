/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 13:22:19 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	if (!ft_strlen((char*)to_find))
		return ((char*)str);
	while (str[i] != '\0')
	{
		k = i;
		while (str[k] == to_find[j] && to_find[j] != '\0')
		{
			if (to_find[j + 1] == '\0')
				return ((char*)(str + i));
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	return (0);
}
