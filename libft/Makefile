# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cammapou <cammapou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 12:06:50 by cammapou          #+#    #+#              #
#    Updated: 2018/08/29 15:13:43 by cammapou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_strcmp.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strdup.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isascii.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strjoin.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strsub.c \
		ft_putchar.c\
		ft_putstr.c \
		ft_strtrim.c \
		ft_putnbr.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_strsplit.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_range.c \
		ft_strndup.c\
		ft_strrev.c\
		ft_swap.c\
		ft_create_elem.c\
		ft_strdeljoin.c \
		ft_lstrev.c \
		ft_atoll.c \
		ft_lstcount.c \
		get_next_line.c \
		ft_lstaddend.c \
		ft_is_int.c

RM = rm -f
OBJ = $(SRC:.c=.o)
C_OK = "\033[35m"
C_NO = "\033[00m"
C_GOOD = "\033[32m"
FLAGS = -Wall -Wextra -Werror
OK = $(C_OK)OK$(C_NO)

all: $(NAME)

%.o: %.c
	@$(CC) -c $(FLAGS) -o $@ $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m[ 100% ]\033[0m Compiling & indexing" [ $(NAME) ] $(OK)

clean:
	@$(RM) $(OBJ)
	@echo "\033[32m[ Delete ]\033[0m [ objs /libft ]" $(OK)

fclean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@echo "\033[32m[ Delete ]\033[0m [ objs & $(NAME) ]" $(OK)

re:fclean all
