/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:00:13 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/21 14:09:04 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftu.h"

int				get_next_line(int fd, char **l)
{
	static char	*s[100];
	char		*temp;
	char		localbuf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !l || BUFF_SIZE < 1 ||
		(ret = read(fd, localbuf, BUFF_SIZE)) == -1)
		return (-1);
	s[fd] = s[fd] ? s[fd] : ft_strdup("");
	temp = s[fd];
	localbuf[ret] = '\0';
	s[fd] = ft_strjoin(s[fd], localbuf);
	free(temp);
	temp = s[fd];
	if (!ft_strlen(s[fd]))
		return (0);
	else if (ft_strchr(s[fd], '\n') &&
			(*l = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd])))
		s[fd] = ft_strdup(ft_strchr(temp, '\n') + 1);
	else if (!ret && ft_strlen(s[fd]) && (*l = ft_strdup(s[fd])))
		s[fd] = NULL;
	else
		return (get_next_line(fd, l));
	free(temp);
	return (1);
}
