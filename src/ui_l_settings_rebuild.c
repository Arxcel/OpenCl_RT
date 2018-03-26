/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_l_settings_rebuild.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 20:22:11 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 20:44:40 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_l_settings_rect_params(t_ui *ui, t_sdl *sdl)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = sdl->win_w - 170;
	y = 150;
	while (i != LI_SET)
	{
		ui->l_set[i].name.rect.x = x * RTN;
		ui->l_set[i].name.rect.y = y * RTN;
		ui->l_set[i].data.rect.x = x * RTN + 200;
		ui->l_set[i].data.rect.y = y * RTN;
		i++;
		y += R_TEXT_H;
	}
}

static void	ui_l_settings_data_textures(t_main *m, char *text, int a)
{
	sprintf(text, "%.2f       ", m->s.light[a].color[0]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LCOL_R].data);
	sprintf(text, "%.2f       ", m->s.light[a].color[1]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LCOL_G].data);
	sprintf(text, "%.2f       ", m->s.light[a].color[2]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LCOL_B].data);
	sprintf(text, "%.2f       ", m->s.light[a].pos[0]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LPOS_X].data);
	sprintf(text, "%.2f       ", m->s.light[a].pos[1]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LPOS_Y].data);
	sprintf(text, "%.2f       ", m->s.light[a].pos[2]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LPOS_Z].data);
	sprintf(text, "%.2f       ", m->s.light[a].pos2[0]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LPOS2_X].data);
	sprintf(text, "%.2f       ", m->s.light[a].pos2[1]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LPOS2_Y].data);
	sprintf(text, "%.2f       ", m->s.light[a].pos2[2]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LPOS2_Z].data);
	sprintf(text, "%.2f       ", m->s.light[a].dir[0]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LDIR_X].data);
	sprintf(text, "%.2f       ", m->s.light[a].dir[1]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LDIR_Y].data);
	sprintf(text, "%.2f       ", m->s.light[a].dir[2]);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LDIR_Z].data);
}

static void	ui_l_settings_pointers_set(t_main *m, int a)
{
	m->ui.l_set[E_LCOL_R].p = (float *)&m->s.light[a].color;
	m->ui.l_set[E_LCOL_G].p = (float *)&m->s.light[a].color;
	m->ui.l_set[E_LCOL_B].p = (float *)&m->s.light[a].color;
	m->ui.l_set[E_LPOS_X].p = (float *)&m->s.light[a].pos;
	m->ui.l_set[E_LPOS_Y].p = (float *)&m->s.light[a].pos;
	m->ui.l_set[E_LPOS_Z].p = (float *)&m->s.light[a].pos;
	m->ui.l_set[E_LPOS2_X].p = (float *)&m->s.light[a].pos2;
	m->ui.l_set[E_LPOS2_Y].p = (float *)&m->s.light[a].pos2;
	m->ui.l_set[E_LPOS2_Z].p = (float *)&m->s.light[a].pos2;
	m->ui.l_set[E_LDIR_X].p = (float *)&m->s.light[a].dir;
	m->ui.l_set[E_LDIR_Y].p = (float *)&m->s.light[a].dir;
	m->ui.l_set[E_LDIR_Z].p = (float *)&m->s.light[a].dir;
	m->ui.l_set[E_LINTENCE].p = (float *)&m->s.light[a].intence;
	m->ui.l_set[E_LANGLE].p = (float *)&m->s.light[a].ang;
}

void		ui_l_settings_rebuild(t_main *m)
{
	char	*text;
	int		a;

	text = ft_strnew(20);
	a = m->ui.list.active - 1;
	ui_l_settings_data_textures(m, text, a);
	sprintf(text, "%.2f       ", m->s.light[a].intence);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LINTENCE].data);
	sprintf(text, "%.2f       ", m->s.light[a].ang);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LANGLE].data);
	ft_memdel((void **)&text);
	ui_l_settings_pointers_set(m, a);
	ui_l_settings_rect_params(&m->ui, &m->sdl);
}
