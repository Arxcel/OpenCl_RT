/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ae_sepia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:14:14 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/20 17:14:47 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

unsigned int			set_sepia(unsigned int in)
{
	t_color		col;
	t_color		res;
	int			tmp;

	col.col = in;
	tmp = (col.argb.red * 0.393) + (col.argb.green * 0.769) +
		(col.argb.blue * 0.189);
	res.argb.red = clamp_rgb(tmp);
	tmp = (col.argb.red * 0.349) + (col.argb.green * 0.686) +
		(col.argb.blue * 0.168);
	res.argb.green = clamp_rgb(tmp);
	tmp = (col.argb.red * 0.272) + (col.argb.green * 0.534) +
		(col.argb.blue * 0.131);
	res.argb.blue = clamp_rgb(tmp);
	return (res.col);
}
