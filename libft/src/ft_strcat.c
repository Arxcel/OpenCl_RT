/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:06:09 by vkozlov           #+#    #+#             */
/*   Updated: 2017/11/11 11:42:35 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *buf1;
	char *buf2;

	buf1 = dest;
	buf2 = src;
	while (*buf1 != '\0')
		buf1++;
	while (*buf2 != '\0')
	{
		*buf1 = *buf2;
		buf1++;
		buf2++;
	}
	*buf1 = '\0';
	return (dest);
}
