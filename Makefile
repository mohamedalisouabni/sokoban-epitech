##
## EPITECH PROJECT, 2023
## make
## File description:
## task1
##

NAME	= my_sokoban

CC	= gcc

SRC =		soko.c		\
			help.c		\
			error.c		\
			play_move.c		\
			cnt_map.c		\
			init_wind.c		\
			get_position.c	\
			w_f.c			\

RM	= rm -f

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L./lib/my -lmy

TEST_NAME = my_sokoban

all: $(NAME)

$(NAME):
	make -C ./lib/my/
	make clean -C ./lib/my/
	$(CC) -o $(NAME) $(SRC) $(LIBFLAG) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean

	$(RM) $(NAME)

re:	fclean all
