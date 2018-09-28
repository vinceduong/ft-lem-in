$(CC) = gcc

$(FLAGS) = -Wall -Wextra -Werror

NAME = lem_in

SRCS = srcs/*.c

OBJ = srcs/*.o

INCLUDE = -I includes -I libft

LIBFT = libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(SRCS)
	$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) $(SRCS) -o $(NAME)

$(LIBFT) :
	make -C libft

clean :
	make clean -C libft
	rm $(OBJ)

fclean : clean
	make fclean -C libft
	rm $(NAME)

re : fclean all
