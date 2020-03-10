##
## EPITECH PROJECT, 2019
## my_hunter
## File description:
## Makefile
##

CFLAGS = -lm -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -W -Wextra -I./include

SRC = my_runner.c	\
	game_init.c		\
	game_loop.c		\
	animations.c	\
	analyse_event.c	\
	mouvement.c		\
	drawer.c		\
	map_reader.c	\
	crossroad.c		\
	win_and_loose.c	\
	init_loops.c	\

OBJ = $(SRC:.c=.o)

NAME = my_runner

all	: $(NAME)

$(NAME)	:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
	rm -f *.o

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all