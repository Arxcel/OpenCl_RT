/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:31:06 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;

	if (s1 && s2 &&
		(tmp = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2))))
	{
		tmp = ft_strcat(tmp, (char *)s1);
		tmp = ft_strcat(tmp, (char *)s2);
		return (tmp);
	}
	return (NULL);
}
