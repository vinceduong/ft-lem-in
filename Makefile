NAME = lem-in

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

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a \
			printf/libftprintf.a

FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = printf
HEADER = -I includes -I libft -I srcs/path
CC = gcc
RM = rm -rf
OK = $(C_OK)OK$(C_NO)

C_NO = "\033[00m"
C_OK = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

.PHONY: all clean fclean re

all: $(NAME)

 $(NAME): $(LIB) $(OBJ)
	@$(CC) $(HEADER) $(FLAGS) $(OBJ) $(FLAGS) -o $(NAME) $(LIB)

$(LIB):
	@make -C libft
	@make -C printf

clean:
	@make clean -s -C $(LIBFT)
	@make clean -s -C $(PRINTF)
	@$(RM) $(OBJ)
	@$(RM) $(OBJ)
	@echo "\033[32m[ Delete ]\033[0m [ objs /$(NAME_P) /$(NAME_C) ]" $(OK)

fclean:
	@make fclean -s -C $(LIBFT)
	@make fclean -s -C $(PRINTF)
	@$(RM) $(OBJ)
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@$(RM) $(NAME)
	@echo "\033[32m[ Delete ]\033[0m [ objs & $(NAME_P) $(NAME_C) ]" $(OK)

re:fclean all
