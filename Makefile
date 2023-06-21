# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaremin <kkaremin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 17:22:56 by kkaremin          #+#    #+#              #
#    Updated: 2023/06/21 17:22:57 by kkaremin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT_GOAL := all

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
SRC = main.c check_input.c error_management.c instructions.c node_list_helper_func.c command_optimization.c sorting.c sorting_more.c small_sorting.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

libft/libft.a:
	make -C libft

%.o: %.c $(HEADER)
	cc $(CFLAGS) -g -Ilibft -c -o $@ $(HEADER) $<

$(NAME): $(OBJ) $(HEADER) libft/libft.a
	cc -o $(NAME) $(OBJ) $(HEADER) libft/libft.a

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean


re: fclean all