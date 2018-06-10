##
## EPITECH PROJECT, 2017
## sokoban
## File description:
## sokoban
##

NAME	= my_sokoban

CC	= gcc

RM	= rm -f

SRCS	= 	./src/main.c		\
		./src/my_sokoban.c	\
		./src/utils.c		\
		./src/movment.c		\
		./src/check.c		\
		./src/game_status.c	\
		./src/my_free_tab.c	\
		./src/my_usage.c

OBJS	= $(SRCS:.c=.o)

LIB	= -L ./lib/ -lmy -lncurses

CFLAGS	= -I ./include/

CFLAGS	+= -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 make -C ./lib/my/
	 $(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	make clean -C ./lib/my/
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./lib/libmy.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
