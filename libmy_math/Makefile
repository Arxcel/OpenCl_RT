# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 18:38:09 by vkozlov           #+#    #+#              #
#    Updated: 2018/03/01 16:37:09 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libmy_math.a

FLAGS = -Wall -Wextra -Werror

DIR_S = src

DIR_O = obj

HEADER = include

HEADERS = -I include \

SOURCES = ft_vector.c \
			ft_matrix.c 
		  
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

obj:
		mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c
		$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

norme:
		echo "--------------------Checking header files $(NAME)"
		norminette ./$(HEADER)
		echo "--------------------Checking source files $(NAME)"
		norminette ./$(DIR_S)

clean:
		rm -f $(OBJS)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all obj norme clean fclean re
.NOTPARALLEL: all obj norme clean fclean re
.SILENT:
