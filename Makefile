DEFAULT_GOAL := all

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
SRC = main.c check_input.c error_management.c instructions.c node_list_helper_func.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c -o $@ $(HEADER) $<

$(NAME): $(OBJ) $(HEADER)
	cc -o $(NAME) $(OBJ) $(HEADER)