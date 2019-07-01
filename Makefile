##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for cloning trantor
##

SRC_DIR	= 	./src/

SRC 	=	$(SRC_DIR)trantor_elements.c\
			$(SRC_DIR)trantor_resources.c\
			$(SRC_DIR)trantor_vision.c\
			$(SRC_DIR)trantor_world.c\
			$(SRC_DIR)trantor_player.c\
			$(SRC_DIR)trantor_server.c\
			$(SRC_DIR)trantor_buff.c\
			$(SRC_DIR)trantor_cmd.c\
			$(SRC_DIR)trantor_errors.c\
			$(SRC_DIR)trantor.c\
			$(SRC_DIR)main.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

INC		=	-I./include

CFLAGS	=	-W -Wall -Wextra -Werror -Wshadow -lpthread $(INC)

NAME	=	trantor_v1

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

tests_run:
	make -C tests
	./tests/trantor_test

.PHONY: all clean fclean re test