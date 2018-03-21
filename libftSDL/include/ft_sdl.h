/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:38:51 by vkozlov           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/20 19:53:00 by anestor          ###   ########.fr       */
=======
/*   Updated: 2018/03/19 14:07:18 by afarapon         ###   ########.fr       */
>>>>>>> e833463f55d8fc930f31728351bb389c05014a89
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SDL_H
# define FT_SDL_H
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# define MSG(x)	ft_killer(x)

typedef struct		s_img
{
	size_t			w;
	size_t			h;
	unsigned int	*pixels;
}					t_img;

typedef struct		s_sdl
{
	int				win_w;
	int				win_h;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*texture;
	SDL_Event		e;
	t_img			img;
	int				running;
	int				changes;
}					t_sdl;

void				sdl_init(t_sdl *sdl);
t_img				sdl_create_image(size_t w, size_t h);
void				sdl_clear_image(t_img *img);
void				sdl_put_image(t_sdl *sdl);
void				sdl_pixel_put(t_img *img, int x, int y, int color);
void				ft_putendl_fd(char const *s, int fd);
int					ft_killer(const char *reason);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
#endif
