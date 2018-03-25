/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_o_settings_rebuild.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 20:21:55 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 20:41:17 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_o_settings_rect_params(t_ui *ui, t_sdl *sdl)
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

static void	ui_o_settings_data_textures_1(t_main *m, char *text, int a)
{
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
}

static void	ui_o_settings_data_textures_2(t_main *m, char *text, int a)
{
	sprintf(text, "%.2f       ", m->s.object[a].dir[0]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_DIR_X].data);
	sprintf(text, "%.2f       ", m->s.object[a].dir[1]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_DIR_Y].data);
	sprintf(text, "%.2f       ", m->s.object[a].dir[2]);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_DIR_Z].data);
	sprintf(text, "%.2f       ", m->s.object[a].radius);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_RAD].data);
	sprintf(text, "%.2f       ", m->s.object[a].reflect);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_REFL].data);
	sprintf(text, "%.2f       ", m->s.object[a].refract);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_REFR].data);
	sprintf(text, "%.2f       ", m->s.object[a].angle);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_ANGL].data);
	sprintf(text, "%.2f       ", m->s.object[a].ior);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_IOR].data);
	sprintf(text, "%.2f       ", m->s.object[a].min);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_MIN].data);
	sprintf(text, "%.2f       ", m->s.object[a].max);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_MAX].data);
	sprintf(text, "%hu       ", m->s.object[a].specular);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_SPECUL].data);
	sprintf(text, "%hu       ", m->s.object[a].tex_id);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_TEX_ID].data);
}

static void	ui_o_settings_pointers_set(t_main *m, int a)
{
	m->ui.o_set[E_COL_R].p = (float *)&m->s.object[a].color;
	m->ui.o_set[E_COL_G].p = (float *)&m->s.object[a].color;
	m->ui.o_set[E_COL_B].p = (float *)&m->s.object[a].color;
	m->ui.o_set[E_DIR_X].p = (float *)&m->s.object[a].dir;
	m->ui.o_set[E_DIR_Y].p = (float *)&m->s.object[a].dir;
	m->ui.o_set[E_DIR_Z].p = (float *)&m->s.object[a].dir;
	m->ui.o_set[E_POS1_X].p = (float *)&m->s.object[a].pos1;
	m->ui.o_set[E_POS1_Y].p = (float *)&m->s.object[a].pos1;
	m->ui.o_set[E_POS1_Z].p = (float *)&m->s.object[a].pos1;
	m->ui.o_set[E_POS2_X].p = (float *)&m->s.object[a].pos2;
	m->ui.o_set[E_POS2_Y].p = (float *)&m->s.object[a].pos2;
	m->ui.o_set[E_POS2_Z].p = (float *)&m->s.object[a].pos2;
	m->ui.o_set[E_POS3_X].p = (float *)&m->s.object[a].pos3;
	m->ui.o_set[E_POS3_Y].p = (float *)&m->s.object[a].pos3;
	m->ui.o_set[E_POS3_Z].p = (float *)&m->s.object[a].pos3;
	m->ui.o_set[E_RAD].p = (float *)&m->s.object[a].radius;
	m->ui.o_set[E_REFL].p = (float *)&m->s.object[a].reflect;
	m->ui.o_set[E_REFR].p = (float *)&m->s.object[a].refract;
	m->ui.o_set[E_ANGL].p = (float *)&m->s.object[a].angle;
	m->ui.o_set[E_IOR].p = (float *)&m->s.object[a].ior;
	m->ui.o_set[E_MIN].p = (float *)&m->s.object[a].min;
	m->ui.o_set[E_MAX].p = (float *)&m->s.object[a].max;
	m->ui.o_set[E_SPECUL].usp = (unsigned short *)&m->s.object[a].specular;
	m->ui.o_set[E_TEX_ID].usp = (unsigned short *)&m->s.object[a].tex_id;
	m->ui.o_set[E_TEX_SCL].usp = (unsigned short *)&m->s.object[a].tex_scale;
}

void		ui_o_settings_rebuild(t_main *m)
{
	char	*text;
	int		a;

	a = m->ui.list.active - 1;
	text = ft_strnew(20);
	ui_o_settings_data_textures_1(m, text, a);
	ui_o_settings_data_textures_2(m, text, a);
	sprintf(text, "%hu       ", m->s.object[a].tex_scale);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_TEX_SCL].data);
	sprintf(text, "%hu       ", m->s.object[a].tex_angle);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_TEX_ANG].data);
	ft_memdel((void **)&text);
	ui_o_settings_pointers_set(m, a);
	m->ui.o_set[E_TEX_ANG].sp = (short *)&m->s.object[a].tex_angle;
	ui_o_settings_rect_params(&m->ui, &m->sdl);
}
