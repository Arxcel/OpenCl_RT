/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:46:40 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

static int	ft_strcount(const char *s, int c)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	if (s)
		while (s[i])
		{
			if (s[i] == (char)c)
				res = i;
			i++;
		}
	return (res);
}

char		*ft_strtrim(char const *s)
{
	char		*end;

	if (s)
	{
		while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
			s++;
		end = (char*)s + ft_strlen((char*)s) - 1;
		while (*end == ' ' || *end == '\n' || *end == '\t')
			end--;
		return (ft_strsub(s, 0, ft_strcount(s, *end) + 1));
	}
	return (NULL);
}
