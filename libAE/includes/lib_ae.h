/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ae.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:51:11 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/26 14:29:33 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_AE_H
# define LIB_AE_H
# include <stdlib.h>
# include "../../libft/include/ft_libftu.h"
# include <stdio.h>
# define AE_SEPIA		0x1
# define AE_SUPER_BLUR	0x2
# define AE_M_BLUR		0x4
# define AE_SMOOTH		0x8
# define AE_CONTR		0x10
# define AE_SHARPNESS	0x20
# define COEF 1
# define O1 0.0029150 * COEF
# define O2 0.0130642 * COEF
# define O3 0.0215393 * COEF
# define O4 0.0585498 * COEF
# define O5 0.0965324 * COEF
# define O6 0.1591549 * COEF
# define FILTER_SIZE	256
# define EFFECTS_SIZE	8

typedef struct			s_ae
{
	unsigned int	**pixels;
	size_t			*w;
	size_t			*h;
	short			after_effect;
	short			coeficient;
	char			effects[EFFECTS_SIZE];
}						t_ae;

typedef void	(*t_effects)(t_ae *ae, unsigned int **in_out, size_t count);

typedef struct			s_rgb
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	alpha;
}						t_rgb;

typedef union			u_color
{
	unsigned int	col;
	struct s_rgb	argb;
}						t_color;

void					set_blur(t_ae *ae,
	unsigned int **in_out, size_t count);
void					ae_triple_blur(t_ae *ae,
	unsigned int **in_out, size_t count);
void					set_sepia(t_ae *ae, unsigned int **out,
	size_t count);
void					set_contrast(t_ae *ae, unsigned int **out,
	size_t count);
void					ae_sharpness(t_ae *ae, unsigned int **in_out,
	size_t count);
void					ae_set_median(t_ae *ae, unsigned int **in_out,
	size_t count);
unsigned int			get_median_green(size_t x, size_t y, t_ae *ae);
unsigned int			get_median_red(size_t x, size_t y, t_ae *ae);
unsigned int			get_median_blue(size_t x, size_t y, t_ae *ae);
void					sort_colors(unsigned int *cols, int how_much);
void					set_black_white(t_ae *ae, unsigned int **out,
	size_t count);
unsigned int			set_sharpness(t_ae *ae, size_t x, size_t y,
	unsigned int *in);
unsigned int			set_smooth(t_ae *ae, size_t x, size_t y,
	unsigned int *in);
unsigned int			set_test_blur(t_ae *ae,
	unsigned int *in, size_t x, size_t y);
unsigned char			clamp_rgb(int color);
t_rgb					get_color_rgb(int col);
void					set_filter(t_ae *ae);
unsigned int			get_large_blue(size_t x, size_t y,
	unsigned int *in, size_t w);
unsigned int			get_large_green(size_t x, size_t y,
	unsigned int *in, size_t w);
unsigned int			get_large_red(size_t x, size_t y,
	unsigned int *in, size_t w);

#endif
