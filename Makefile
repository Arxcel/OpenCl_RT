# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 16:21:44 by vkozlov           #+#    #+#              #
#    Updated: 2018/03/19 18:53:55 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = rt

FLAGS = -Wall -Wextra -Werror -flto -O3

IDIR = ./include

EXTENSIONS = $(addprefix $(IDIR)/,$(EXT))

EXT =		ft_ui.h \
			ft_rt.h \
			ft_scene.h \

CFLAGS = -I$(IDIR) \
		 -I./libft/include \
		 -I./libCL/include \
		 -I./libSDL/SDL2.framework/Headers/ \
		 -I./libSDL/SDL2_image.framework/Headers/ \
		 -I./libftSDL/include \
		 -I./libJson/include \
		 -I./libmy_math/include \
		 -I./libTFD \

LIBFT = libft

LIBCL = libCL

LIBJSON = libJson

LIBFTSDL = libftSDL

LIBMMATH = libmy_math

LIBTFD = libTFD

SDL2_F		= -framework SDL2 -framework SDL2_image  -F ./libSDL/

SDL2_P		= -rpath @loader_path/libSDL/

DIR_S = src

DIR_O = obj

HEADER = include

_DEPS = ft_rt.h

DEPS = $(patsubst %,$(HEADER)/%,$(_DEPS))

SOURCES =   main.c \
			sdl_handle.c \
			parse_json.c \
			error.c \
			set_flags.c \
			move_camera.c \
			utils.c \
			validate_objects.c \
			ui.c \
			mouse_hooks.c \
			ui_render_lines_and_corners.c \
			open_export_save.c \
			ui_buttons_init.c \
			sdl_sub.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj libs $(NAME)

$(NAME): $(OBJS) $(EXTENSIONS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(CFLAGS) -L $(LIBFT) -lft $(LIBTFD)/libtfd.a -L $(LIBMMATH) -lmy_math -L $(LIBJSON) -lJSON -L $(LIBCL) -lCL -framework OpenCl $(SDL2_P) $(SDL2_F) -L $(LIBFTSDL) -lftsdl

		

libs: 
	make -C $(LIBFT)
	make -C $(LIBJSON)
	make -C $(LIBMMATH)
	make -C $(LIBCL)
	make -C $(LIBFTSDL)
	make -C $(LIBTFD)

obj:
	mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS) $(EXTENSIONS)
		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS)

norme:
		make norme -C $(LIBFT)
		make norme -C $(LIBCL)
		make norme -C $(LIBFTSDL)
		make norme -C $(LIBMMATH)
		echo "--------------------Checking header files $(NAME)"
		norminette ./$(HEADER)
		echo "--------------------Checking source files $(NAME)"
		norminette ./$(DIR_S)

clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		make clean -C $(LIBCL)
		make clean -C $(LIBFTSDL)
		make clean -C $(LIBJSON)
		make clean -C $(LIBMMATH)
		make clean -C $(LIBTFD)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
		make fclean -C $(LIBCL)
		make fclean -C $(LIBFTSDL)
		make fclean -C $(LIBJSON)
		make fclean -C $(LIBMMATH)
		make fclean -C $(LIBTFD)

re: fclean all

.PHONY: all, obj, norme, clean, fclean, re
.NOTPARALLEL:  all, obj, norme, clean, fclean, re
.SILENT:
