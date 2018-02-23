/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 20:19:50 by vkozlov           #+#    #+#             */
/*   Updated: 2017/11/05 12:10:15 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	int sub;

	sub = 32;
	if (c >= 65 && c <= 90)
		return (c + sub);
	return (c);
}