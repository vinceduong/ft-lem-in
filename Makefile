.PHONY : all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = lem_in

LIBFT = libft/libft.a

INCLUDES = -I./libft/ -I./includes/

SRC = 	srcs/main.c \
		srcs/parse/parser.c \
		srcs/parse/readrooms.c \
		srcs/parse/tool_parse.c \
		srcs/parse/read_start_end.c \
		srcs/display.c\
		srcs/error.c\
		srcs/node_tools.c\
		srcs/path_tools.c\
		srcs/path.c\
		srcs/record.c\
		srcs/split_ants.c\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

<<<<<<< HEAD
=======
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = printf
HEADER = -I includes -I libft
CC = gcc
RM = rm -rf
OK = $(C_OK)OK$(C_NO)
>>>>>>> master

$(NAME) : $(SRC) $(LIBFT)
	@$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIBFT) -o $(NAME)
	@printf "\n\033[032mFiller Compilation Successful\033[0m\n"

$(LIBFT) :
	@make -C libft

clean :
	@make clean -C libft
	@rm -f $(OBJ)

fclean : clean
	@make clean -C libft
	@rm -f $(NAME)

re : fclean all
