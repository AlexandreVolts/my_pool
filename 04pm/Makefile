DIR	=	src

TEST = test

INC_DIR =	include/

SRC	=	$(DIR)/list_add_elem_at_position.c			\
		$(DIR)/list_get_size.c						\
		$(DIR)/list_clear.c							\
		$(TEST)/list_add_elem_at_position.test.c	\
		$(TEST)/list_get_size.test.c				\
		$(TEST)/list_clear.test.c					\

CFLAGS	=	-Wall -Wextra -std=gnu17 -lcriterion -I ./$(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	output

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
