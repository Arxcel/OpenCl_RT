/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_buttons_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:50:08 by anestor           #+#    #+#             */
/*   Updated: 2018/03/22 14:20:22 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_buttons_init_1(t_ui *ui, t_sdl *sdl)
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
	ui->btn[BTN_CUBE].on =
		sdl_texture_from_file("textures/btns/cube_on.png", sdl->ren);
	ui->btn[BTN_CUBE].off =
		sdl_texture_from_file("textures/btns/cube_off.png", sdl->ren);
	ui->btn[BTN_PARABOLOID].on =
		sdl_texture_from_file("textures/btns/paraboloid_on.png", sdl->ren);
	ui->btn[BTN_PARABOLOID].off =
		sdl_texture_from_file("textures/btns/paraboloid_off.png", sdl->ren);
}

static void	ui_buttons_init_2(t_ui *ui, t_sdl *sdl)
{
	ui->btn[BTN_PLANE].on =
		sdl_texture_from_file("textures/btns/plane_on.png", sdl->ren);
	ui->btn[BTN_PLANE].off =
		sdl_texture_from_file("textures/btns/plane_off.png", sdl->ren);
	ui->btn[BTN_SPHERE].on =
		sdl_texture_from_file("textures/btns/sphere_on.png", sdl->ren);
	ui->btn[BTN_SPHERE].off =
		sdl_texture_from_file("textures/btns/sphere_off.png", sdl->ren);
	ui->btn[BTN_CYLINDER].on =
		sdl_texture_from_file("textures/btns/cylinder_on.png", sdl->ren);
	ui->btn[BTN_CYLINDER].off =
		sdl_texture_from_file("textures/btns/cylinder_off.png", sdl->ren);
	ui->btn[BTN_CONUS].on =
		sdl_texture_from_file("textures/btns/cone_on.png", sdl->ren);
	ui->btn[BTN_CONUS].off =
		sdl_texture_from_file("textures/btns/cone_off.png", sdl->ren);
	ui->btn[BTN_DISK].on =
		sdl_texture_from_file("textures/btns/disk_on.png", sdl->ren);
	ui->btn[BTN_DISK].off =
		sdl_texture_from_file("textures/btns/disk_off.png", sdl->ren);
	ui->btn[BTN_TRIANGLE].on =
		sdl_texture_from_file("textures/btns/triangle_on.png", sdl->ren);
	ui->btn[BTN_TRIANGLE].off =
		sdl_texture_from_file("textures/btns/triangle_off.png", sdl->ren);
}

static void	ui_buttons_init_3(t_ui *ui, t_sdl *sdl)
{
	ui->btn[PREV_CAM].on =
		sdl_texture_from_file("textures/btns/prev_cam_on.png", sdl->ren);
	ui->btn[PREV_CAM].off =
		sdl_texture_from_file("textures/btns/prev_cam_off.png", sdl->ren);
	ui->btn[NEXT_CAM].on =
		sdl_texture_from_file("textures/btns/next_cam_on.png", sdl->ren);
	ui->btn[NEXT_CAM].off =
		sdl_texture_from_file("textures/btns/next_cam_off.png", sdl->ren);
	ui->btn[BTN_CAM].on =
		sdl_texture_from_file("textures/btns/new_cam_on.png", sdl->ren);
	ui->btn[BTN_CAM].off =
		sdl_texture_from_file("textures/btns/new_cam_off.png", sdl->ren);
	ui->btn[BTN_LIGHT1].on =
		sdl_texture_from_file("textures/btns/new_light1_on.png", sdl->ren);
	ui->btn[BTN_LIGHT1].off =
		sdl_texture_from_file("textures/btns/new_light1_off.png", sdl->ren);
	ui->btn[BTN_LIGHT2].on =
		sdl_texture_from_file("textures/btns/new_light2_on.png", sdl->ren);
	ui->btn[BTN_LIGHT2].off =
		sdl_texture_from_file("textures/btns/new_light2_off.png", sdl->ren);
	ui->btn[BTN_LIGHT3].on =
		sdl_texture_from_file("textures/btns/new_light3_on.png", sdl->ren);
	ui->btn[BTN_LIGHT3].off =
		sdl_texture_from_file("textures/btns/new_light3_off.png", sdl->ren);
}

static void	ui_rbutton_init(t_ui *ui, t_sdl *sdl)
{
	ui->rbtn.a.textr =
		sdl_texture_from_file("textures/btns/rbtn_a.png", sdl->ren);
	ui->rbtn.b.textr =
		sdl_texture_from_file("textures/btns/rbtn_b.png", sdl->ren);
	ui->rbtn.c.textr =
		sdl_texture_from_file("textures/btns/rbtn_c.png", sdl->ren);
}

void		ui_buttons_init(t_ui *ui, t_sdl *sdl)
{
	ui_buttons_init_1(ui, sdl);
	ui_buttons_init_2(ui, sdl);
	ui_buttons_init_3(ui, sdl);
	ui_rbutton_init(ui, sdl);
}
