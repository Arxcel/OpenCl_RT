/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_get_all_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:27:54 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/22 13:38:26 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ae.h"

unsigned int	set_test_blur(t_ae *ae, unsigned int *in, size_t x, size_t y)
{
	t_color		tmp;
	size_t		w;

	w = *ae->w;
	tmp.argb.red = clamp_rgb(get_large_red(x, y, in, *ae->w));
	tmp.argb.green = clamp_rgb(get_large_green(x, y, in, *ae->w));
	tmp.argb.blue = clamp_rgb(get_large_blue(x, y, in, *ae->w));
	return (tmp.col);
}
