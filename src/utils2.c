/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:54:03 by afarapon          #+#    #+#             */
/*   Updated: 2018/03/23 14:54:14 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	delete_scene(t_scene *s)
{
	ft_memdel((void **)&s->object);
	ft_memdel((void **)&s->camera);
	ft_memdel((void **)&s->light);
}
