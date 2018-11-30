##
## EPITECH PROJECT, 2018
## Spying Trantor Test
## File description:
## Makefile for trantorian_cli unit tests
##

SRC =	../src/trantor_world.c\
		../src/trantor_resources.c\
		test_create_grid.c\
		test_create_cell.c\
		test_link_lines.c\
		test_destroy_grid.c

OBJ = $(SRC:.c=.o)

INC = -I../include

CC = gcc

CFLAGS = -W -Wall -Wextra -Werror $(INC)

LIB = -lcriterion

NAME = trantor_test

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re