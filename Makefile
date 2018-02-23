# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 16:21:44 by vkozlov           #+#    #+#              #
#    Updated: 2018/02/23 16:43:42 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = rt

FLAGS = -Wall -Wextra -Werror

IDIR = ./include

CFLAGS = -I$(IDIR) \
		 -I./libft/include \
		 -I./libCL/include \
		 -I./libSDL/SDL2.framework/Headers/ \
		 -I./libSDL/SDL2_image.framework/Headers/ \
		 -I./libftSDL/include \


LIBFT = libft

LIBCL = libCL

LIBFTSDL = libftSDL

SDL2_F		= -framework SDL2 -framework SDL2_image  -F ./libSDL/

SDL2_P		= -rpath @loader_path/libSDL/

DIR_S = src

DIR_O = obj

HEADER = include

_DEPS = ft_rt.h

DEPS = $(patsubst %,$(HEADER)/%,$(_DEPS))

SOURCES =  main.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj libs $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(CFLAGS) -L $(LIBFT) -lft -L $(LIBCL) -lCL -framework OpenCl $(SDL2_P) $(SDL2_F) $(FSDL2) -L $(LIBFTSDL) -lftsdl

		

libs: 
	make -C $(LIBFT)
	make -C $(LIBCL)
	make -C $(LIBFTSDL)

obj:
	mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS)
		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS)

norme:
		make norme -C $(LIBFT)
		make norme -C $(LIBCL)
		make norme -C $(LIBFTSDL)
		echo "--------------------Checking header files $(NAME)"
		norminette ./$(HEADER)
		echo "--------------------Checking source files $(NAME)"
		norminette ./$(DIR_S)

clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		make clean -C $(LIBCL)
		make clean -C $(LIBFTSDL)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
		make fclean -C $(LIBCL)
		make fclean -C $(LIBFTSDL)

re: fclean all

.PHONY: all, obj, norme, clean, fclean, re
.NOTPARALLEL:  all, obj, norme, clean, fclean, re
.SILENT: