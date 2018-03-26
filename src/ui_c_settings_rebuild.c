/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_c_settings_rebuild.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 20:22:22 by anestor           #+#    #+#             */
/*   Updated: 2018/03/26 15:47:49 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_c_settings_data_textures(t_main *m, char *text, int a)
{
	sprintf(text, "%.2f       ", m->s.camera[a].rot[0]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CROT_X].data);
	sprintf(text, "%.2f       ", m->s.camera[a].rot[1]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CROT_Y].data);
	sprintf(text, "%.2f       ", m->s.camera[a].rot[2]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CROT_Z].data);
	sprintf(text, "%.2f       ", m->s.camera[a].pos[0]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CPOS_X].data);
	sprintf(text, "%.2f       ", m->s.camera[a].pos[1]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CPOS_Y].data);
	sprintf(text, "%.2f       ", m->s.camera[a].pos[2]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CPOS_Z].data);
	sprintf(text, "%.2f       ", m->s.camera[a].dir[0]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CDIR_X].data);
	sprintf(text, "%.2f       ", m->s.camera[a].dir[1]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CDIR_Y].data);
	sprintf(text, "%.2f       ", m->s.camera[a].dir[2]);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CDIR_Z].data);
	sprintf(text, "%.2f       ", m->s.camera[a].fov);
	texture_from_text(text, &m->sdl, &m->ui.c_set[E_CFOV].data);
}

static void	ui_c_settings_pointers_set(t_main *m, int a)
{
	m->ui.c_set[E_CPOS_X].p = (float *)&m->s.camera[a].pos;
	m->ui.c_set[E_CPOS_Y].p = (float *)&m->s.camera[a].pos;
	m->ui.c_set[E_CPOS_Z].p = (float *)&m->s.camera[a].pos;
	m->ui.c_set[E_CDIR_X].p = (float *)&m->s.camera[a].dir;
	m->ui.c_set[E_CDIR_Y].p = (float *)&m->s.camera[a].dir;
	m->ui.c_set[E_CDIR_Z].p = (float *)&m->s.camera[a].dir;
	m->ui.c_set[E_CROT_X].p = (float *)&m->s.camera[a].rot;
	m->ui.c_set[E_CROT_Y].p = (float *)&m->s.camera[a].rot;
	m->ui.c_set[E_CROT_Z].p = (float *)&m->s.camera[a].rot;
	m->ui.c_set[E_CFOV].p = (float *)&m->s.camera[a].fov;
}

static void	ui_c_settings_rect_params(t_ui *ui, t_sdl *sdl)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = sdl->win_w - 170;
	y = 150;
	while (i != CA_SET)
	{
		ui->c_set[i].name.rect.x = x * RTN;
		ui->c_set[i].name.rect.y = y * RTN;
		ui->c_set[i].data.rect.x = x * RTN + 200;
		ui->c_set[i].data.rect.y = y * RTN;
		i++;
		y += R_TEXT_H;
	}
}

void		ui_c_settings_rebuild(t_main *m)
{
	char	*text;
	int		a;

	text = ft_strnew(100);
	a = m->ui.list.active - 1;
	ui_c_settings_data_textures(m, text, a);
	ft_memdel((void **)&text);
	ui_c_settings_pointers_set(m, a);
	ui_c_settings_rect_params(&m->ui, &m->sdl);
}
