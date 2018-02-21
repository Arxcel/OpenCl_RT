/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:46:08 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/21 18:46:17 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void				sdl_pixel_put(t_img *img, int x, int y, int color)
{
	if (x < 0 || (size_t)x > img->w || y < 0 || (size_t)y > img->h)
		return ;
	img->pixels[x + y * img->w] = color;
}
