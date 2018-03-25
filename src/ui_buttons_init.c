/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_buttons_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:50:08 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 16:55:26 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static void	ui_buttons_init_1(t_ui *ui, t_sdl *sdl)
{
	TEXTURE_ON(OPEN, "textures/btns/open_on.png");
	TEXTURE_OFF(OPEN, "textures/btns/open_off.png");
	TEXTURE_ON(SAVE, "textures/btns/save_on.png");
	TEXTURE_OFF(SAVE, "textures/btns/save_off.png");
	TEXTURE_ON(SAVE_AS, "textures/btns/save_as_on.png");
	TEXTURE_OFF(SAVE_AS, "textures/btns/save_as_off.png");
	TEXTURE_ON(EXPORT, "textures/btns/export_on.png");
	TEXTURE_OFF(EXPORT, "textures/btns/export_off.png");
	TEXTURE_ON(BTN_CUBE, "textures/btns/cube_on.png");
	TEXTURE_OFF(BTN_CUBE, "textures/btns/cube_off.png");
	TEXTURE_ON(BTN_PARABOLOID, "textures/btns/paraboloid_on.png");
	TEXTURE_OFF(BTN_PARABOLOID, "textures/btns/paraboloid_off.png");
	TEXTURE_ON(BTN_PLANE, "textures/btns/plane_on.png");
	TEXTURE_OFF(BTN_PLANE, "textures/btns/plane_off.png");
	TEXTURE_ON(BTN_SPHERE, "textures/btns/sphere_on.png");
	TEXTURE_OFF(BTN_SPHERE, "textures/btns/sphere_off.png");
	TEXTURE_ON(BTN_CYLINDER, "textures/btns/cylinder_on.png");
	TEXTURE_OFF(BTN_CYLINDER, "textures/btns/cylinder_off.png");
	TEXTURE_ON(BTN_CONUS, "textures/btns/cone_on.png");
	TEXTURE_OFF(BTN_CONUS, "textures/btns/cone_off.png");
	TEXTURE_ON(BTN_DISK, "textures/btns/disk_on.png");
	TEXTURE_OFF(BTN_DISK, "textures/btns/disk_off.png");
	TEXTURE_ON(BTN_TRIANGLE, "textures/btns/triangle_on.png");
	TEXTURE_OFF(BTN_TRIANGLE, "textures/btns/triangle_off.png");
}

static void	ui_buttons_init_2(t_ui *ui, t_sdl *sdl)
{
	TEXTURE_ON(PREV_CAM, "textures/btns/prev_cam_on.png");
	TEXTURE_OFF(PREV_CAM, "textures/btns/prev_cam_off.png");
	TEXTURE_ON(NEXT_CAM, "textures/btns/next_cam_on.png");
	TEXTURE_OFF(NEXT_CAM, "textures/btns/next_cam_off.png");
	TEXTURE_ON(BTN_CAM, "textures/btns/new_cam_on.png");
	TEXTURE_OFF(BTN_CAM, "textures/btns/new_cam_off.png");
	TEXTURE_ON(BTN_LIGHT1, "textures/btns/new_light1_on.png");
	TEXTURE_OFF(BTN_LIGHT1, "textures/btns/new_light1_off.png");
	TEXTURE_ON(BTN_LIGHT2, "textures/btns/new_light2_on.png");
	TEXTURE_OFF(BTN_LIGHT2, "textures/btns/new_light2_off.png");
	TEXTURE_ON(BTN_LIGHT3, "textures/btns/new_light3_on.png");
	TEXTURE_OFF(BTN_LIGHT3, "textures/btns/new_light3_off.png");
	TEXTURE_ON(BTN_LIGHT4, "textures/btns/new_light4_on.png");
	TEXTURE_OFF(BTN_LIGHT4, "textures/btns/new_light4_off.png");
	TEXTURE_ON(BTN_SQUARE, "textures/btns/square_on.png");
	TEXTURE_OFF(BTN_SQUARE, "textures/btns/square_off.png");
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

static void	ui_buttons_init_3(t_ui *ui, t_sdl *sdl)
{
	TEXTURE_ON(BTN_SQUARE, "textures/btns/square_on.png");
	TEXTURE_OFF(BTN_SQUARE, "textures/btns/square_off.png");
	TEXTURE_ON(BTN_AE1, "textures/btns/ae1_on.png");
	TEXTURE_OFF(BTN_AE1, "textures/btns/ae1_off.png");
	TEXTURE_ON(BTN_AE2, "textures/btns/ae2_on.png");
	TEXTURE_OFF(BTN_AE2, "textures/btns/ae2_off.png");
	TEXTURE_ON(BTN_AE3, "textures/btns/ae3_on.png");
	TEXTURE_OFF(BTN_AE3, "textures/btns/ae3_off.png");
	TEXTURE_ON(BTN_AE4, "textures/btns/ae4_on.png");
	TEXTURE_OFF(BTN_AE4, "textures/btns/ae4_off.png");
	TEXTURE_ON(BTN_AE5, "textures/btns/ae5_on.png");
	TEXTURE_OFF(BTN_AE5, "textures/btns/ae5_off.png");
	TEXTURE_ON(BTN_AE6, "textures/btns/ae6_on.png");
	TEXTURE_OFF(BTN_AE6, "textures/btns/ae6_off.png");
	TEXTURE_ON(BTN_PLUS, "textures/btns/aeplus_on.png");
	TEXTURE_OFF(BTN_PLUS, "textures/btns/aeplus_off.png");
	TEXTURE_ON(BTN_MINUS, "textures/btns/aeminus_on.png");
	TEXTURE_OFF(BTN_MINUS, "textures/btns/aeminus_off.png");
	TEXTURE_ON(BTN_ZERO, "textures/btns/aezero_on.png");
	TEXTURE_OFF(BTN_ZERO, "textures/btns/aezero_off.png");
	TEXTURE_ON(BTN_ONE, "textures/btns/aeone_on.png");
	TEXTURE_OFF(BTN_ONE, "textures/btns/aeone_off.png");
}

void		ui_buttons_init(t_ui *ui, t_sdl *sdl)
{
	ui_buttons_init_1(ui, sdl);
	ui_buttons_init_2(ui, sdl);
	ui_buttons_init_3(ui, sdl);
	ui_rbutton_init(ui, sdl);
}
