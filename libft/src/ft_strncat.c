/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 23:52:51 by vkozlov           #+#    #+#             */
/*   Updated: 2017/11/05 12:09:52 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int n)
{
	char	*buf;

	buf = dest;
	while (*buf != '\0')
		buf++;
	while (*src != '\0' && n > 0)
	{
		*buf = *src;
		buf++;
		src++;
		n--;
	}
	*buf = '\0';
	return (dest);
}
