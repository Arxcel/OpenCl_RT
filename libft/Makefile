# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 13:38:05 by vkozlov           #+#    #+#              #
#    Updated: 2018/01/17 14:04:38 by vkozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

DIR_S = src

DIR_O = obj

HEADER = include

SOURCES = ft_printf.c \
		parse_option.c \
		char_cases.c \
		cases_string.c \
		cases_char.c \
		put_wchar.c \
		num_cases.c \
		cases_decimal.c \
		cases_hex_oct.c \
		cases_long_num.c \
		num_service.c \
		unum_cases.c \
		other_cases.c \
		service.c \
		length.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_factorial.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_pow.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_rotn.c \
		ft_sqrt.c \
		ft_strcapitalize.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_swap.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstshift.c \
		ft_lstaddend.c \
		ft_strsplit.c \
		ft_freearr.c \
		get_next_line.c
		  
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
		@echo "--------------------Checking header files libft"
		@norminette ./$(HEADER)
		@echo "--------------------Checking source files libft"
		@norminette ./$(DIR_S)

clean:
		@rm -f $(OBJS)
		@rm -rf $(DIR_O)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all obj norme clean fclean re
.NOTPARALLEL: all obj norme clean fclean re
