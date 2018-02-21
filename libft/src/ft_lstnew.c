/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 22:43:25 by vkozlov           #+#    #+#             */
/*   Updated: 2018/01/16 15:54:24 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*el;

	if ((el = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		el->content = malloc(content_size);
		if (el->content == NULL)
		{
			free(el);
			return (NULL);
		}
		ft_memcpy(el->content, content, content_size);
		el->content_size = content_size;
		el->next = NULL;
	}
	else
	{
		el->content = NULL;
		el->content_size = 0;
	}
	return (el);
}
