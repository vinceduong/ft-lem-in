# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 18:56:29 by apoque            #+#    #+#              #
#    Updated: 2018/09/17 14:52:10 by carmenia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes/libft.h

CC = gcc

SRC =	ft_memset.c \
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strndup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_uitoabase.c\
		ft_litoabase.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_is_neg.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_strrev.c\
		ft_itoabase_u.c\
		ft_strjoinfree.c\
		ft_strndupfree.c\
		ft_power.c\
		ft_int_strstr.c\
		ft_int_strchar.c\
		ft_get_next_line.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) ft_printf/*.c ft_printf/Makefile
	@make -C ft_printf
	@cp ft_printf/libftprintf.a ./$(NAME)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\n\033[33mLibft Succesfully compiled\n\033[0m"

%.o: %.c
		@printf "\r\033[31mgcc -c -Wall -Wextra -Werror -o $@ $^                    \033[0m"
			@gcc -c -Wall -Wextra -Werror -o $@ $^

clean :
	@cd ft_printf ; make fclean ; cd ..
	@rm -rf $(OBJ)

fclean : clean
	@cd ft_printf ; make clean ; cd ..
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
