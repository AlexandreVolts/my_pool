DIR	=	src

TEST = test

INC_DIR =	include/

SRC	=	$(DIR)/list_add_elem_at_position.c			\
		$(DIR)/list_get_elem_at_position.c			\
		$(DIR)/list_del_elem_at_position.c			\
		$(DIR)/list_get_size.c						\
		$(DIR)/list_dump.c							\
		$(DIR)/list_clear.c							\
		$(DIR)/map_clear.c							\
		$(DIR)/map_get_size.c						\
		$(DIR)/map_get_index.c						\
		$(DIR)/map_add_elem.c						\
		$(DIR)/map_get_elem.c						\
		$(DIR)/map_del_elem.c						\
		$(DIR)/queue_clear.c						\
		$(DIR)/queue_get_size.c						\
		$(DIR)/queue_pop.c							\
		$(DIR)/queue_push.c							\
		$(DIR)/queue_front.c						\
		$(DIR)/stack_clear.c						\
		$(DIR)/stack_get_size.c						\
		$(DIR)/stack_pop.c							\
		$(DIR)/stack_push.c							\
		$(DIR)/stack_top.c							\
		$(TEST)/list_add_elem_at_position.test.c	\
		$(TEST)/list_get_elem_at_position.test.c	\
		$(TEST)/list_del_elem_at_position.test.c	\
		$(TEST)/list_get_size.test.c				\
		$(TEST)/list_dump.test.c					\
		$(TEST)/list_clear.test.c					\
		$(TEST)/map_get_index.test.c				\
		$(TEST)/map_add_elem.test.c					\
		$(TEST)/map_del_elem.test.c					\

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
