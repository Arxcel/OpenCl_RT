/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:49:58 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

static size_t		ft_cnt(char const *s, char c)
{
	size_t i;
	size_t cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static char			*ft_tr(char const *s, char c)
{
	char *str;

	if (s)
	{
		str = (char *)s;
		while (*str == c && *str)
			str++;
		return (str);
	}
	return (NULL);
}

static size_t		ft_wl(char *str, char del)
{
	int len;

	len = 0;
	while (*str && *str != del)
	{
		len++;
		str++;
	}
	return (len);
}

static char			*ft_str_cpy(char *dest, char *src, char del)
{
	char *res;

	res = dest;
	while (*src && *src != del)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (res);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*buf;
	size_t	i;

	i = -1;
	if (s && (arr = (char **)malloc(sizeof(*arr) *
					(ft_cnt(ft_tr(s, c), c) + 1))))
	{
		buf = (char *)s;
		while (++i < ft_cnt(ft_tr(s, c), c))
		{
			buf = ft_tr(buf, c);
			if ((arr[i] = (char *)malloc(sizeof(char) *
			(ft_wl(buf, c)))) == NULL)
			{
				ft_freearr(arr, ft_cnt(ft_tr(s, c), c));
				return (NULL);
			}
			arr[i] = ft_str_cpy(arr[i], buf, c);
			buf = ft_strchr(buf, c);
		}
		arr[i] = 0;
		return (arr);
	}
	return (NULL);
}
