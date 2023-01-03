DIR	=	src

TEST = test

INC_DIR =	include/

SRC	=	$(DIR)/string_init.c		\
		$(DIR)/string_destroy.c		\
		$(DIR)/_strlen.c			\
		$(DIR)/assign.c				\
		$(DIR)/append.c				\
		$(DIR)/at.c					\
		$(DIR)/clear.c				\
		$(DIR)/length.c				\
		$(DIR)/compare.c			\
		$(TEST)/string_init.test.c	\
		$(TEST)/assign.test.c		\
		$(TEST)/append.test.c		\
		$(TEST)/at.test.c			\
		$(TEST)/clear.test.c		\
		$(TEST)/length.test.c		\
		$(TEST)/compare.test.c		\

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
