DIR	=	src

INC_DIR =	include/

SRC	=	$(DIR)/get.c		\
		$(DIR)/set.c		\
		$(DIR)/disp.c		\
		$(DIR)/sort.c		\
		$(DIR)/uniq.c		\
		tests/disp.test.c	\
		tests/sort.test.c	\
		tests/uniq.test.c	\

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
