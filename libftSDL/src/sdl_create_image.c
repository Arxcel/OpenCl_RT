/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_create_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:43:37 by vkozlov           #+#    #+#             */
/*   Updated: 2018/02/21 18:44:56 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_img				sdl_create_image(size_t w, size_t h)
{
	t_img img;

	img.w = w;
	img.h = h;
	if (!(img.pixels = ft_memalloc(sizeof(int) * img.w * img.h)))
		MSG("Error allocating memory for pixels");
	sdl_clear_image(&img);
	return (img);
}
