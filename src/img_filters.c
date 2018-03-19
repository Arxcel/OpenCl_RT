/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_filters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:37:03 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/19 16:10:02 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

// static void			set_smooth(t_main *main)
// {
// 	byte[] inputBytes = BitmapBytes.GetBytes(input);
// 	byte[] outputBytes = new byte[inputBytes.Length];

// 	int width = input.Width;
// 	int height = input.Height;

// 	int kernelWidth = kernel.GetLength(0);
// 	int kernelHeight = kernel.GetLength(1);

// 	//Производим вычисления
// 	for (int x = 0; x < width; x++)
// 	{
// 		for (int y = 0; y < height; y++)
// 		{
// 			double rSum = 0, gSum = 0, bSum = 0, kSum = 0;

// 			for (int i = 0; i < kernelWidth; i++)
// 			{
// 				for (int j = 0; j < kernelHeight; j++)
// 				{
// 					int pixelPosX = x + (i - (kernelWidth / 2));
// 					int pixelPosY = y + (j - (kernelHeight / 2));
// 					if ((pixelPosX < 0) || 
// 					(pixelPosX >= width) || (pixelPosY < 0) || (pixelPosY >= height))
// 						continue;

// 					byte r = inputBytes[3 * (width * pixelPosY + pixelPosX) + 0];
// 					byte g = inputBytes[3 * (width * pixelPosY + pixelPosX) + 1];
// 					byte b = inputBytes[3 * (width * pixelPosY + pixelPosX) + 2];

// 					double kernelVal = kernel[i, j];

// 					rSum += r * kernelVal;
// 					gSum += g * kernelVal;
// 					bSum += b * kernelVal;

// 					kSum += kernelVal;
// 				}
// 			}

// 			if (kSum <= 0)
// 				kSum = 1;
// 			//Контролируем переполнения переменных
// 			rSum /= kSum;
// 			if (rSum < 0)
// 				rSum = 0;
// 			if (rSum > 255)
// 				rSum = 255;

// 			gSum /= kSum;
// 			if (gSum < 0)
// 				gSum = 0;
// 			if (gSum > 255)
// 				gSum = 255;

// 			bSum /= kSum;
// 			if (bSum < 0) bSum = 0;
// 			if (bSum > 255) bSum = 255;

// 			//Записываем значения в результирующее изображение
// 			outputBytes[3 * (width * y + x) + 0] = (byte)rSum;
// 			outputBytes[3 * (width * y + x) + 1] = (byte)gSum;
// 			outputBytes[3 * (width * y + x) + 2] = (byte)bSum;
// 		}
// 	}
// }

unsigned int				set_sepia(unsigned int in)
{
	t_color		col;
	t_color		res;

	col.col = in;
	res.rgba.red = (col.rgba.red * 0.393) + (col.rgba.green * 0.769) + (col.rgba.blue * 0.189);
	res.rgba.green = (col.rgba.red * 0.349) + (col.rgba.green * 0.686) + (col.rgba.blue * 0.168);
	res.rgba.blue = (col.rgba.red * 0.272) + (col.rgba.green * 0.534) + (col.rgba.blue * 0.131);
	return (res.col);
}

static void			set_sepia(t_main *main)
{
	int				i;
	int				j;





	i = -1;
	while (++j < main->sdl.img.h && (i = -1))
	{
		while (++i < main->sdl.img.w)
		{
			
		}
	}

}

void				set_filter(t_main *main)
{
	if (main->after_effect == AE_SEPIA)
		set_sepia(main);
	// else if (main->after_effect == AE_TOON)
	// 	set_toon(main);
	// else if (main->after_effect == AE_M_BLUR)
	// 	set_blur(main);
	// else if (main->after_effect == AE_STEREO)
	// 	set_stereoscopia(main);
	// else if (main->after_effect == AE_SMOOTH)
	// 	set_smooth(main);
	// return BitmapBytes.GetBitmap(outputBytes, width, height);
}