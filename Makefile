##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for cloning trantor
##

SRC =	src/trantor_elements.c\
		src/trantor_resources.c\
		src/trantor_vision.c\
		src/trantor_world.c\
		src/trantor_player.c\
		src/trantor_server.c\
		src/trantor_cmd.c\
		src/trantor.c\
		src/main.c

OBJ =	$(SRC:.c=.o)

CC =	gcc

INC =	-I./include

CFLAGS =	-W -Wall -Wextra -Werror -Wshadow -lpthread $(INC)

NAME =	trantor_v1

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	make clean -C tests

fclean: clean
	rm -f $(NAME)

re: fclean all

thread:
	$(CC) $(CFLAGS) -fsanitize=thread -o $(NAME) $(OBJ)

test: 
	make -C tests
	./tests/trantor_test

.PHONY: all clean fclean re test