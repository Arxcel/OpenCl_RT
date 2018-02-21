/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:06:14 by vkozlov           #+#    #+#             */
/*   Updated: 2017/11/11 11:48:49 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *start;

	start = (char *)s;
	while (*s)
		s++;
	while (s >= start)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (0);
}
