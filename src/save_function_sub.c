/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_function_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:36:55 by anestor           #+#    #+#             */
/*   Updated: 2018/03/24 15:31:38 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

char	*read_object_type(int i, t_main *m)
{
	int		t;

	t = m->s.object[i].type;
	if (t == 1)
		return (ft_strdup("sphere"));
	if (t == 2)
		return (ft_strdup("conus"));
	if (t == 3)
		return (ft_strdup("plane"));
	if (t == 4)
		return (ft_strdup("cylinder"));
	if (t == 5)
		return (ft_strdup("disk"));
	if (t == 6)
		return (ft_strdup("triangle"));
	if (t == 7)
		return (ft_strdup("paraboloid"));
	if (t == 8)
		return (ft_strdup("square"));
	return (ft_strdup(""));
}

char	*read_light_type(int i, t_main *m)
{
	int		t;

	t = m->s.light[i].type;
	if (t == 1)
		return (ft_strdup("parallel"));
	if (t == 2)
		return (ft_strdup("lamp"));
	if (t == 3)
		return (ft_strdup("ambient"));
	if (t == 4)
		return (ft_strdup("area"));
	return (ft_strdup(""));
}

char	*read_camera_type(int i, t_main *m)
{
	int		t;

	t = m->s.camera[i].type;
	if (t == 1)
		return (ft_strdup("common"));
	return (ft_strdup(""));
}

char	*read_pattern_type(int i, t_main *m)
{
	int		t;

	t = m->s.object[i].tex_id;
	if (t == 2)
		return (ft_strdup("chessboard"));
	if (t == 3)
		return (ft_strdup("gradient"));
	if (t == 4)
		return (ft_strdup("perlin"));
	if (t == 5)
		return (ft_strdup("circle"));
	if (t == 6)
		return (ft_strdup("brick"));
	if (t == 7)
		return (ft_strdup("custom-1"));
	if (t == 8)
		return (ft_strdup("custom-2"));
	if (t == 9)
		return (ft_strdup("custom-3"));
	if (t == 10)
		return (ft_strdup("custom-4"));
	return (ft_strdup(""));
}
