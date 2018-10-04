.PHONY : all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = lem_in

LIBFT = libft/libft.a

INCLUDES = -I./libft/ -I./includes/

SRC = 	srcs/main.c \
			srcs/parse/ft_fill_matrice.c\
			srcs/parse/matrice.c\
			srcs/parse/parse.c\
			srcs/path/add_new_paths.c \
			srcs/path/add_node.c \
			srcs/path/add_path.c \
			srcs/path/check_nodelist.c \
			srcs/path/count_new_childs.c \
			srcs/path/cpy_nodelist.c \
			srcs/path/cpy_path.c \
			srcs/path/delete_path.c \
			srcs/path/init_node.c \
			srcs/path/init_path.c \
			srcs/path/list_to_sorted_array.c \
			srcs/path/merge_paths.c \
			srcs/path/new_path_list.c \
			srcs/path/paths.c \
			srcs/path/sort_paths.c \
			srcs/path/update_bl.c \
			srcs/path/update_paths.c \
			srcs/display.c\
			srcs/record.c\
			srcs/split_ants.c\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRC) $(LIBFT)
		@$(CC) $(FLAGS) $(INCLUDES) $(SRC) -o $(NAME) $(LIBFT)
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
