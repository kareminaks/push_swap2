DEFAULT_GOAL := all

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
SRC = main.c check_input.c error_management.c instructions.c node_list_helper_func.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

libft/libft.a:
	make -C libft libft.a

%.o: %.c $(HEADER)
	cc -I. -Ilibft -c $(CFLAGS) -c -o $@ $(HEADER) $<

$(NAME): $(OBJ) $(HEADER) libft/libft.a
	cc -o $(NAME) $(OBJ) libft/libft.a $(HEADER)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
