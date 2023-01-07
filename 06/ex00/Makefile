DIR	=	src

SRC	=	$(DIR)/main.cpp		\

CFLAGS	=	-Wall -Wextra -std=c++20

CC	=	g++

OBJ	=	$(SRC:.cpp=.o)

NAME	=	my_cat

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re