CC = clang

NAME = RT

KEYS = -Wall -Wextra -Werror

FLAGS = -flto -O3

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
		 -I./libSDL/SDL2_ttf.framework/Headers/ \
		 -I./libftSDL/include \
		 -I./libJson/include \
		 -I./libmy_math/include \
		 -I./libTFD \
		 -I./libAE/includes \

LIBFT = libft

LIBCL = libCL

LIBJSON = libJson

LIBFTSDL = libftSDL

LIBMMATH = libmy_math

LIBTFD = libTFD

LIBAE = libAE

SDL2_F		= -framework SDL2 -framework SDL2_image -framework SDL2_ttf -F ./libSDL/

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
			utils2.c \
			validate_objects.c \
			ui.c \
			mouse_down.c \
			mouse_up.c \
			ui_render_lines_and_corners.c \
			ui_render_copy_buttons.c \
			ui_render_copy_rbutton.c \
			ui_render_copy_background.c \
			ui_render_copy_scroll.c \
			ui_render_copy_list.c \
			ui_render_copy_settings.c \
			change_settings_value.c \
			open_export_save.c \
			save_function.c \
			save_function_sub.c \
			ui_buttons_init.c \
			ui_textures_init.c \
			ui_settings_init.c \
			sdl_sub.c \
			sdl_rinit.c \
			scene_textures.c \
			ctors_1.c \
			ctors_2.c \
			ctors_3.c \
			retrive_cameras.c \
			retrive_lights.c \
			retrive_objects.c \
			retrive_utils.c \
			validation_1.c \
			validation_2.c \
			scene_perlin_noise.c \
			create_buttons_1.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS) $(EXTENSIONS)
		make libs
		$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(CFLAGS) -L $(LIBFT) -lft $(LIBTFD)/libtfd.a -L $(LIBMMATH) -lmy_math -L $(LIBJSON) -lJSON -L $(LIBCL) -lCL -framework OpenCl $(SDL2_P) $(SDL2_F) -L $(LIBFTSDL) -lftsdl -L $(LIBAE) -lae

		

libs: 
	make -C $(LIBFT)
	make -C $(LIBJSON)
	make -C $(LIBMMATH)
	make -C $(LIBCL)
	make -C $(LIBFTSDL)
	make -C $(LIBTFD)
	make -C $(LIBAE)

obj:
	mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS) $(EXTENSIONS)
		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS)

norme:
		make norme -C $(LIBFT)
		make norme -C $(LIBCL)
		make norme -C $(LIBFTSDL)
		make norme -C $(LIBMMATH)
		make norme -C $(LIBAE)
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
		make clean -C $(LIBAE)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
		make fclean -C $(LIBCL)
		make fclean -C $(LIBFTSDL)
		make fclean -C $(LIBJSON)
		make fclean -C $(LIBMMATH)
		make fclean -C $(LIBTFD)
		make fclean -C $(LIBAE)

re: fclean all

.PHONY: all, obj, norme, clean, fclean, re
.NOTPARALLEL:  all, obj, norme, clean, fclean, re
.SILENT:
