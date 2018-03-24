# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 11:49:59 by afarapon          #+#    #+#              #
#    Updated: 2018/03/24 13:49:18 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = libae.a

FLAGS = -Wall -Wextra -Werror

DIR_S = src

DIR_O = obj

HEADER = include

SRC = ae_blur.c \
		ae_triple_blur.c \
		ae_contrast.c \
		ae_get_all_rgb.c \
		ae_sepia.c \
		ae_set_sharpness.c \
		ae_sharpness.c \
		ae_smooth.c \
		ae_black_white.c \
		ae_median.c \
		ae_median_red.c \
		ae_median_green.c \
		ae_median_blue.c \
		ae_get_large_red.c \
		ae_get_large_green.c \
		ae_get_large_blue.c \
		img_filters.c \

SRCS = $(addprefix $(DIR_S)/,$(SRC))

OBJS = $(addprefix $(DIR_O)/,$(SRC:.c=.o))

IDIR = includes

_DEPS = lib_ae.h

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: obj $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

obj:
		@mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS)
		@$(CC) $(FLAGS) -I $(HEADER) -I$(IDIR) -o $@ -c $<

norme:
		@echo "--------------------Checking header files libAE"
		@norminette ./$(IDIR)
		@echo "--------------------Checking source files libAE"
		@norminette ./$(DIR_S)

clean:
		@rm -f $(OBJS)
		@rm -rf $(DIR_O)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all obj clean fclean re
.NOTPARALLEL: all obj clean fclean re
