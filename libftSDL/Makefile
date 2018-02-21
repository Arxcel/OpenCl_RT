# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 18:38:09 by vkozlov           #+#    #+#              #
#    Updated: 2018/02/21 19:01:54 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftSDL.a

FLAGS = -Wall -Wextra -Werror

DIR_S = src

DIR_O = obj

HEADER = include

HEADERS = -I./include \
		  -I../libSDL/ready_libs/SDL2/include/SDL2/ \
		  -I../libSDL/ready_libs/SDL2_image/include/SDL2

SOURCES = ft_killer.c \
			sdl_clear_image.c \
			sdl_create_image.c \
			sdl_init.c \
			sdl_pixel_put.c \
			sdl_put_image.c \
		  
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

obj:
		@mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c
		@$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

norme:
		@echo "--------------------Checking header files $(NAME)"
		@norminette ./$(HEADER)
		@echo "--------------------Checking source files $(NAME)"
		@norminette ./$(DIR_S)

clean:
		@rm -f $(OBJS)
		@rm -rf $(DIR_O)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all obj norme clean fclean re
.NOTPARALLEL: all obj norme clean fclean re
