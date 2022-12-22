DIR	=	src

INC_DIR =	include/

SRC	=	$(DIR)/main.c

CFLAGS	=	-Wall -Wextra -std=gnu17 -I ./$(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	z

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
