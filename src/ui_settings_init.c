/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_settings_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 19:16:21 by anestor           #+#    #+#             */
/*   Updated: 2018/03/26 14:56:19 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_o_settings_init_1(t_ui *ui, t_sdl *sdl)
{
	texture_from_text("Color RED:", sdl, &ui->o_set[E_COL_R].name);
	texture_from_text("Color GREEN:", sdl, &ui->o_set[E_COL_G].name);
	texture_from_text("Color BLUE:", sdl, &ui->o_set[E_COL_B].name);
	texture_from_text("Dir X:", sdl, &ui->o_set[E_DIR_X].name);
	texture_from_text("Dir Y:", sdl, &ui->o_set[E_DIR_Y].name);
	texture_from_text("Dir Z:", sdl, &ui->o_set[E_DIR_Z].name);
	texture_from_text("Pos1 X:", sdl, &ui->o_set[E_POS1_X].name);
	texture_from_text("Pos1 Y:", sdl, &ui->o_set[E_POS1_Y].name);
	texture_from_text("Pos1 Z:", sdl, &ui->o_set[E_POS1_Z].name);
	texture_from_text("Pos2 X:", sdl, &ui->o_set[E_POS2_X].name);
	texture_from_text("Pos2 Y:", sdl, &ui->o_set[E_POS2_Y].name);
	texture_from_text("Pos2 Z:", sdl, &ui->o_set[E_POS2_Z].name);
	texture_from_text("Pos3 X:", sdl, &ui->o_set[E_POS3_X].name);
	texture_from_text("Pos3 Y:", sdl, &ui->o_set[E_POS3_Y].name);
	texture_from_text("Pos3 Z:", sdl, &ui->o_set[E_POS3_Z].name);
	texture_from_text("Radius:", sdl, &ui->o_set[E_RAD].name);
	texture_from_text("Reflect:", sdl, &ui->o_set[E_REFL].name);
	texture_from_text("Refract:", sdl, &ui->o_set[E_REFR].name);
	texture_from_text("Angle:", sdl, &ui->o_set[E_ANGL].name);
	texture_from_text("Ior:", sdl, &ui->o_set[E_IOR].name);
	texture_from_text("Min:", sdl, &ui->o_set[E_MIN].name);
	texture_from_text("Max:", sdl, &ui->o_set[E_MAX].name);
	texture_from_text("Specular:", sdl, &ui->o_set[E_SPECUL].name);
}

static void	ui_o_settings_init_2(t_ui *ui, t_sdl *sdl)
{
	texture_from_text("Texture ID:", sdl, &ui->o_set[E_TEX_ID].name);
	texture_from_text("Texture scale:", sdl, &ui->o_set[E_TEX_SCL].name);
	texture_from_text("Texture angle:", sdl, &ui->o_set[E_TEX_ANG].name);
}

static void	ui_l_settings_init(t_ui *ui, t_sdl *sdl)
{
	texture_from_text("Color RED:", sdl, &ui->l_set[E_LCOL_R].name);
	texture_from_text("Color GREEN:", sdl, &ui->l_set[E_LCOL_G].name);
	texture_from_text("Color BLUE:", sdl, &ui->l_set[E_LCOL_B].name);
	texture_from_text("Dir X:", sdl, &ui->l_set[E_LDIR_X].name);
	texture_from_text("Dir Y:", sdl, &ui->l_set[E_LDIR_Y].name);
	texture_from_text("Dir Z:", sdl, &ui->l_set[E_LDIR_Z].name);
	texture_from_text("Pos X:", sdl, &ui->l_set[E_LPOS_X].name);
	texture_from_text("Pos Y:", sdl, &ui->l_set[E_LPOS_Y].name);
	texture_from_text("Pos Z:", sdl, &ui->l_set[E_LPOS_Z].name);
	texture_from_text("Pos2 X:", sdl, &ui->l_set[E_LPOS2_X].name);
	texture_from_text("Pos2 Y:", sdl, &ui->l_set[E_LPOS2_Y].name);
	texture_from_text("Pos2 Z:", sdl, &ui->l_set[E_LPOS2_Z].name);
	texture_from_text("Intence:", sdl, &ui->l_set[E_LINTENCE].name);
	texture_from_text("Angle:", sdl, &ui->l_set[E_LANGLE].name);
}

static void	ui_c_settings_init(t_ui *ui, t_sdl *sdl)
{
	texture_from_text("Dir X:", sdl, &ui->c_set[E_CDIR_X].name);
	texture_from_text("Dir Y:", sdl, &ui->c_set[E_CDIR_Y].name);
	texture_from_text("Dir Z:", sdl, &ui->c_set[E_CDIR_Z].name);
	texture_from_text("Pos X:", sdl, &ui->c_set[E_CPOS_X].name);
	texture_from_text("Pos Y:", sdl, &ui->c_set[E_CPOS_Y].name);
	texture_from_text("Pos Z:", sdl, &ui->c_set[E_CPOS_Z].name);
	texture_from_text("Rot X:", sdl, &ui->c_set[E_CROT_X].name);
	texture_from_text("Rot Y:", sdl, &ui->c_set[E_CROT_Y].name);
	texture_from_text("Rot Z:", sdl, &ui->c_set[E_CROT_Z].name);
	texture_from_text("FOV:", sdl, &ui->c_set[E_CFOV].name);
}

void		ui_settings_init(t_ui *ui, t_sdl *sdl)
{
	ui_o_settings_init_1(ui, sdl);
	ui_o_settings_init_2(ui, sdl);
	ui_l_settings_init(ui, sdl);
	ui_c_settings_init(ui, sdl);
	ui->list.active = 0;
}
