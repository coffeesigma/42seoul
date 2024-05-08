CC = cc -Wall -Wextra -Werror
LIB_DIR = ./libft
LIB = libft.a
HEADER = push_swap.h
SRCS = test.c init.c utils.c stack.c op.c
SRCS_B = 
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = push_swap
NAME_B = checker

.PHONY: all re clean fclean re bonus

all : $(NAME)

.c.o : %.c $(HEADER)
	$(CC) -c $<

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) -o $@ $^ -L$(LIB_DIR) -lft

bonus : $(OBJS_B) $(LIB_DIR)/$(LIB)
	$(CC) -o $(NAME_B) $^ -L$(LIB_DIR) -lft

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)
	make bonus -C $(LIB_DIR)

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	make fclean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_B)

re : fclean all