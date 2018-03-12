# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 13:49:03 by vkozlov           #+#    #+#              #
#    Updated: 2018/03/12 13:14:05 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = libCL.a

FLAGS = -Wall -Wextra -Werror

DIR_S = src

DIR_O = obj

HEADER = include

SOURCES = cl_create_compile_program.c \
			cl_create_context.c \
			cl_create_kernel.c \
			cl_create_queue.c \
			cl_err_message.c \
			cl_execute_kernel.c \
			cl_get_devices.c \
			cl_get_platforms.c \
			cl_get_results.c \
			cl_init.c \
			cl_set_args.c \
			cl_set_out_arg.c \
			cl_free_args.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

obj:
		@mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c
		@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

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
