##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for cloning trantor
##

SRC =	src/trantor_world.c\
		src/trantor.c\
		src/main.c

OBJ =	$(SRC:.c=.o)

CC =	gcc

INC =	-I./include

CFLAGS =	-W -Wall -Wextra -Werror $(INC)

NAME =	trantor_v1

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: 
	make -C tests
	./tests/trantor_test

.PHONY: all clean fclean re test