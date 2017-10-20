# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 15:08:21 by dverbyts          #+#    #+#              #
#    Updated: 2017/10/19 20:00:47 by dverbyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror -g

SRC = lem_in.c lem_in_algorithm.c lem_in_algorithm2.c lem_in_init_fail.c \
		lem_in_join_strdel.c lem_in_read.c lem_in_read2.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@gcc $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

