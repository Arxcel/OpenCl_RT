/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_buttons_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:50:08 by anestor           #+#    #+#             */
/*   Updated: 2018/03/19 17:53:22 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_file_buttons_init(t_ui *ui, t_sdl *sdl)
{
	ui->btn[OPEN].on =
		sdl_texture_from_file("textures/btns/open_on.png", sdl->ren);
	ui->btn[OPEN].off =
		sdl_texture_from_file("textures/btns/open_off.png", sdl->ren);
	ui->btn[SAVE].on =
		sdl_texture_from_file("textures/btns/save_on.png", sdl->ren);
	ui->btn[SAVE].off =
		sdl_texture_from_file("textures/btns/save_off.png", sdl->ren);
	ui->btn[SAVE_AS].on =
		sdl_texture_from_file("textures/btns/save_as_on.png", sdl->ren);
	ui->btn[SAVE_AS].off =
		sdl_texture_from_file("textures/btns/save_as_off.png", sdl->ren);
	ui->btn[EXPORT].on =
		sdl_texture_from_file("textures/btns/export_on.png", sdl->ren);
	ui->btn[EXPORT].off =
		sdl_texture_from_file("textures/btns/export_off.png", sdl->ren);
}

static void	ui_create_elem_buttons_init_1(t_ui *ui, t_sdl *sdl)
{
	ui->btn[BTN_PLANE].on =
		sdl_texture_from_file("textures/btns/open_on.png", sdl->ren);
	ui->btn[BTN_PLANE].off =
		sdl_texture_from_file("textures/btns/open_off.png", sdl->ren);
	ui->btn[BTN_SPHERE].on =
		sdl_texture_from_file("textures/btns/open_on.png", sdl->ren);
	ui->btn[BTN_SPHERE].off =
		sdl_texture_from_file("textures/btns/open_off.png", sdl->ren);
	ui->btn[BTN_CYLINDER].on =
		sdl_texture_from_file("textures/btns/open_on.png", sdl->ren);
	ui->btn[BTN_CYLINDER].off =
		sdl_texture_from_file("textures/btns/open_off.png", sdl->ren);
	ui->btn[BTN_CONUS].on =
		sdl_texture_from_file("textures/btns/open_on.png", sdl->ren);
	ui->btn[BTN_CONUS].off =
		sdl_texture_from_file("textures/btns/open_off.png", sdl->ren);
	ui->btn[BTN_DISK].on =
		sdl_texture_from_file("textures/btns/open_on.png", sdl->ren);
	ui->btn[BTN_DISK].off =
		sdl_texture_from_file("textures/btns/open_off.png", sdl->ren);
	ui->btn[BTN_TRIANGLE].on =
		sdl_texture_from_file("textures/btns/open_on.png", sdl->ren);
	ui->btn[BTN_TRIANGLE].off =
		sdl_texture_from_file("textures/btns/open_off.png", sdl->ren);
}

static void	ui_create_elem_buttons_init_2(t_ui *ui, t_sdl *sdl)
{
	ui->btn[BTN_PARABOLOID].on =
		sdl_texture_from_file("textures/btns/open_on.png", sdl->ren);
	ui->btn[BTN_PARABOLOID].off =
		sdl_texture_from_file("textures/btns/open_off.png", sdl->ren);
}

void		ui_buttons_init(t_ui *ui, t_sdl *sdl)
{
	ui_file_buttons_init(ui, sdl);
	ui_create_elem_buttons_init_1(ui, sdl);
	ui_create_elem_buttons_init_2(ui, sdl);
}
