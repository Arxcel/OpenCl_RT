/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render_copy_settings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:54:46 by anestor           #+#    #+#             */
/*   Updated: 2018/03/25 22:00:28 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void		render_copy_o_settings(t_main *m)
{
	int		i;

	ui_o_settings_rebuild(m);
	i = 0;
	while (i != O_SET)
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.o_set[i].name.textr,
								NULL, &m->ui.o_set[i].name.rect);
		SDL_RenderCopy(m->sdl.ren, m->ui.bg[SET_1].textr,
								NULL, &m->ui.bg[SET_1].rect);
		SDL_RenderCopy(m->sdl.ren, m->ui.o_set[i].data.textr,
								NULL, &m->ui.o_set[i].data.rect);
		SDL_DestroyTexture(m->ui.o_set[i].data.textr);
		i++;
	}
}

void		render_copy_l_settings(t_main *m)
{
	int		i;

	ui_l_settings_rebuild(m);
	i = 0;
	while (i != LI_SET)
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.l_set[i].name.textr,
								NULL, &m->ui.l_set[i].name.rect);
		SDL_RenderCopy(m->sdl.ren, m->ui.bg[SET_2].textr,
								NULL, &m->ui.bg[SET_2].rect);
		SDL_RenderCopy(m->sdl.ren, m->ui.l_set[i].data.textr,
								NULL, &m->ui.l_set[i].data.rect);
		SDL_DestroyTexture(m->ui.l_set[i].data.textr);
		i++;
	}
}

void		render_copy_c_settings(t_main *m)
{
	int		i;

	ui_c_settings_rebuild(m);
	i = 0;
	while (i != CA_SET)
	{
		SDL_RenderCopy(m->sdl.ren, m->ui.c_set[i].name.textr,
								NULL, &m->ui.c_set[i].name.rect);
		SDL_RenderCopy(m->sdl.ren, m->ui.bg[SET_3].textr,
								NULL, &m->ui.bg[SET_3].rect);
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
