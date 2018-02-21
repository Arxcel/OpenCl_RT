/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:17:56 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (s && (tmp = ft_strdup((char *)s)))
	{
		while (tmp[i])
		{
			tmp[i] = f(tmp[i]);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
