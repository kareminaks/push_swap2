DEFAULT_GOAL := all

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
SRC = main.c check_input.c error_management.c instructions.c node_list_helper_func.c command_optimization.c sorting.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

libft/libft.a:
	make -C libft

%.o: %.c $(HEADER)
	cc $(CFLAGS) -Ilibft -c -o $@ $(HEADER) $<

$(NAME): $(OBJ) $(HEADER) libft/libft.a
	cc -o $(NAME) $(OBJ) $(HEADER) libft/libft.a

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean


re: fclean all