##
## EPITECH PROJECT, 2018
## Spying Trantor Test
## File description:
## Makefile for trantorian_cli unit tests
##

SRC_DIR	= 	../src/

SRC		=	$(SRC_DIR)trantor_elements.c\
			$(SRC_DIR)trantor_resources.c\
			$(SRC_DIR)trantor_vision.c\
			$(SRC_DIR)trantor_world.c\
			$(SRC_DIR)trantor_player.c\
			$(SRC_DIR)trantor_server.c\
			$(SRC_DIR)trantor_cmd.c\
			$(SRC_DIR)trantor.c\
			test_trantor_world.c\
			test_trantor_ressources.c\
			test_trantor.c

OBJ		=	$(SRC:.c=.o)

INC		=	-I../include

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror -Wshadow -lpthread $(INC)

LIB		=	-lcriterion

NAME	=	trantor_test

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re