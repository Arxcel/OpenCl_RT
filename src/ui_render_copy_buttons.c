/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_buttons.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:08:49 by anestor           #+#    #+#             */
/*   Updated: 2018/03/23 20:11:55 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_btn_rect_params(t_ui *ui)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = BTN_ROW1_X;
	y = BTN_ROW1_Y;
	while (i != BTNS)
	{
		ui->btn[i].rect = sdl_rect(x, y, BTN_SIZE, BTN_SIZE);
		x += BTN_ROW1_X + BTN_SIZE;
		i++;
		if (i == 4 || i == 14 || i == 15)
			x += 15;
		if (i == 6)
		{
			y += BTN_ROW1_Y + BTN_SIZE;
			x = BTN_ROW1_X;
		}
	}
}

void		render_copy_buttons(t_main *m)
{
	int		i;

	ui_btn_rect_params(&m->ui);
	i = 0;
	while (i != BTNS)
	{
		if (m->ui.btn[i].status == 1)
		{
			SDL_RenderCopy(m->sdl.ren, m->ui.btn[i].on,
								NULL, &m->ui.btn[i].rect);
		}
		else
		{
			SDL_RenderCopy(m->sdl.ren, m->ui.btn[i].off,
								NULL, &m->ui.btn[i].rect);
		}
		i++;
	}
}
