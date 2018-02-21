# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 16:21:44 by vkozlov           #+#    #+#              #
#    Updated: 2018/02/21 19:20:15 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = rt

FLAGS = -Wall -Wextra -Werror

IDIR = ./include

CFLAGS = -I$(IDIR) \
		 -I./libft/include \
		 -I./libCL/include \
		 -I./libSDL/ready_libs/SDL2/include/SDL2/ \
		 -I./libSDL/ready_libs/SDL2_image/include/SDL2 \
		 -I./libftSDL/include \


LIBFT = libft

LIBCL = libCL

LIBSDL = libSDL

LIBFTSDL = libftSDL

LSDL2 = -L ./libSDL/ready_libs/SDL2/lib -lSDL2 \
		-L ./libSDL/ready_libs/SDL2_image/lib -lSDL2_image

SDL2_P = @loader_path/libSDL/ready_libs/

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

		$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(CFLAGS) -L $(LIBFT) -lft -L $(LIBCL) -lCL -framework OpenCl $(SDL2_P) $(LSDL2) -L $(LIBFTSDL) -lftsdl

libs: 
		make -C $(LIBFT)
		make -C $(LIBCL)
		make -C $(LIBSDL)
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
		make clean -C $(LIBSDL)
		make clean -C $(LIBFTSDL)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
		make fclean -C $(LIBCL)
		make fclean -C $(LIBSDL)
		make fclean -C $(LIBFTSDL)

re: fclean all

.PHONY: all, obj, norme, clean, fclean, re
.NOTPARALLEL:  all, obj, norme, clean, fclean, re
.SILENT: