/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_settings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:54:46 by anestor           #+#    #+#             */
/*   Updated: 2018/03/24 22:18:07 by anestor          ###   ########.fr       */
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

	a = m->ui.list.active - 1;
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
	sprintf(text, "%hu       ", m->s.object[a].tex_scale);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_TEX_SCL].data);
	sprintf(text, "%hu       ", m->s.object[a].tex_angle);
	texture_from_text(text, &m->sdl, &m->ui.o_set[E_TEX_ANG].data);
	ft_memdel((void **)&text);
}

void	ui_o_settings_pointers_set(t_main *m)
{
	int		a;

	a = m->ui.list.active - 1;
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
	m->ui.o_set[E_TEX_ANG].sp = (short *)&m->s.object[a].tex_angle;
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

void		ui_l_settings_rect_params(t_ui *ui, t_sdl *sdl)
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

void		ui_l_settings_data_textures(t_main *m)
{
	int		a;
	char	*text;

	a = m->ui.list.active - 1;
	text = ft_strnew(20);
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
	sprintf(text, "%.2f       ", m->s.light[a].intence);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LINTENCE].data);
	sprintf(text, "%.2f       ", m->s.light[a].ang);
	texture_from_text(text, &m->sdl, &m->ui.l_set[E_LANGLE].data);
	ft_memdel((void **)&text);
}

void	ui_l_settings_pointers_set(t_main *m)
{
	int		a;

	a = m->ui.list.active - 1;
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

void		render_copy_l_settings(t_main *m)
{
	int		i;

	ui_l_settings_data_textures(m);	
	ui_l_settings_pointers_set(m);
	ui_l_settings_rect_params(&m->ui, &m->sdl);
	i = 0;
	while (i != LI_SET)
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.l_set[i].name.textr,
								NULL, &m->ui.l_set[i].name.rect);
		SDL_RenderCopy(m->sdl.ren, m->ui.l_set[i].data.textr,
								NULL, &m->ui.l_set[i].data.rect);
		SDL_DestroyTexture(m->ui.l_set[i].data.textr);
		i++;
	}
}

void		ui_c_settings_data_textures(t_main *m)
{
	int		a;
	char	*text;

	a = m->ui.list.active - 1;
	text = ft_strnew(20);
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
	ft_memdel((void **)&text);
}

void	ui_c_settings_pointers_set(t_main *m)
{
	int		a;

	a = m->ui.list.active - 1;
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

void		ui_c_settings_rect_params(t_ui *ui, t_sdl *sdl)
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

void		render_copy_c_settings(t_main *m)
{
	int		i;

	ui_c_settings_data_textures(m);	
	ui_c_settings_pointers_set(m);
	ui_c_settings_rect_params(&m->ui, &m->sdl);
	i = 0;
	while (i != CA_SET)
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.c_set[i].name.textr,
								NULL, &m->ui.c_set[i].name.rect);
		SDL_RenderCopy(m->sdl.ren, m->ui.c_set[i].data.textr,
								NULL, &m->ui.c_set[i].data.rect);
		SDL_DestroyTexture(m->ui.c_set[i].data.textr);
		i++;
	}
}

void		render_copy_settings(t_main *m)
{
	if (m->ui.list.active != 0)
	{
		if (m->ui.rbtn.status == 0)
			render_copy_o_settings(m);
		else if (m->ui.rbtn.status == 1)
			render_copy_l_settings(m);
		else if (m->ui.rbtn.status == 2)
			render_copy_c_settings(m);
	}
}
