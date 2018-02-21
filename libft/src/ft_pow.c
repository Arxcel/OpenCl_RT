/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:23:30 by vkozlov           #+#    #+#             */
/*   Updated: 2017/11/11 12:23:33 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int power)
{
	int result;

	if (power < 0)
		return (0);
	else if (power == 0 || nb == 1)
		return (1);
	else
	{
		result = nb * ft_pow(nb, power - 1);
		return (result);
	}
}
