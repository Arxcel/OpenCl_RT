/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_settings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:54:46 by anestor           #+#    #+#             */
/*   Updated: 2018/03/23 22:05:56 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void		ui_o_settings_rect_params(t_ui *ui, t_sdl *sdl)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = sdl->win_w - 170;
	y = 150;
	while (i != O_SET)
	{
		ui->o_set[i].name.rect.x = x * RTN;
		ui->o_set[i].name.rect.y = y * RTN;
		ui->o_set[i].data.rect.x = x * RTN + 200;
		ui->o_set[i].data.rect.y = y * RTN;
		i++;
		y += R_TEXT_H;
	}
}

void		ui_o_settings_data_textures(t_main *m)
{
	int		a;
	char	*text;

	a = m->ui.list.active;
	text = ft_strnew(20);
	sprintf(text, "%.2f       ", m->s.object[a].color[0]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_COL_R].data);
	sprintf(text, "%.2f       ", m->s.object[a].color[1]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_COL_G].data);
	sprintf(text, "%.2f       ", m->s.object[a].color[2]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_COL_B].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos1[0]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS1_X].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos1[1]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS1_Y].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos1[2]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS1_Z].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos2[0]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS2_X].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos2[1]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS2_Y].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos2[2]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS2_Z].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos3[0]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS3_X].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos3[1]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS3_Y].data);
	sprintf(text, "%.2f       ", m->s.object[a].pos3[2]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_POS3_Z].data);
	sprintf(text, "%.2f       ", m->s.object[a].dir[0]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_DIR_X].data);
	sprintf(text, "%.2f       ", m->s.object[a].dir[1]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_DIR_Y].data);
	sprintf(text, "%.2f       ", m->s.object[a].dir[2]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_DIR_Z].data);
	ft_memdel((void **)&text);
}

void	ui_o_settings_pointers_set(t_main *m)
{

}

void		render_copy_o_settings(t_main *m)
{
	int		i;

	ui_o_settings_data_textures(m);	
	ui_o_settings_pointers_set(m);
	ui_o_settings_rect_params(&m->ui, &m->sdl);
	i = 0;
	while (i != O_SET)
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.o_set[i].name.textr,
								NULL, &m->ui.o_set[i].name.rect);
		SDL_RenderCopy(m->sdl.ren, m->ui.o_set[i].data.textr,
								NULL, &m->ui.o_set[i].data.rect);
		SDL_DestroyTexture(m->ui.o_set[i].data.textr);
		i++;
	}
}

void		render_copy_l_settings(t_main *m)
{

}

void		render_copy_c_settings(t_main *m)
{

}

void		render_copy_scene_settings(t_main *m)
{

}

void		render_copy_settings(t_main *m)
{
	if (m->ui.list.active != 0)
	{
		if (m->ui.rbtn.status == 0)
			render_copy_o_settings(m);
		else if (m->ui.rbtn.status == 1)
			render_copy_l_settings(m);
		else
			render_copy_c_settings(m);
	}
	else
		render_copy_scene_settings(m);
}
