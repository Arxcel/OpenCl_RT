/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:02:31 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

char			*ft_strdup(char *src)
{
	char *buf;

	buf = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (buf == NULL)
		return (NULL);
	ft_strcpy(buf, src);
	buf[ft_strlen(src)] = '\0';
	return (buf);
}
