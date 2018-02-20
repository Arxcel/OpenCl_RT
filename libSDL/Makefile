# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 14:07:37 by vkozlov           #+#    #+#              #
#    Updated: 2018/02/20 15:34:59 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_GSDL = ~/SDL_INVADERS

DIR_SDL2 = SDL2

DIR_SDL2_IMG = SDL2_image

all: dir lsdl lsdl_img

dir:
	mkdir -p $(DIR_GSDL)

lsdl:
	./lsdl.sh

lsdl_img:
	./lsdl_im.sh

clean:
	@rm -rf $(DIR_GSDL)

fclean: clean

re: fclean all

.PHONY: all clean fclean
#.SILENT: