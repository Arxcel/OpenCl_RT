# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 14:07:37 by vkozlov           #+#    #+#              #
#    Updated: 2018/02/20 18:01:09 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_GSDL = ready_libs

all: dir lsdl lsdl_img

dir:
	mkdir -p $(DIR_GSDL)

lsdl:
	./libSDL_src/lsdl.sh

lsdl_img:
	./libSDL_src/lsdl_im.sh

clean:
	echo "\n"

fclean: clean
	@rm -rf $(DIR_GSDL)

re: fclean all

.PHONY: all clean fclean
.SILENT: