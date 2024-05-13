CC = cc -Wall -Wextra -Werror
LIB_DIR = ./libft
LIB = libft.a
HEADER = push_swap.h
HEADER_B = checker.h
SRCS = push_swap.c init.c utils.c utils2.c utils3.c stack.c op.c sort_lower.c sort.c sort_utils.c optimize.c
SRCS_B = checker.c init_bonus.c utils_bonus.c utils2_bonus.c utils3_bonus.c stack_bonus.c op_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = push_swap
NAME_B = checker

ifdef WITH_BONUS
	HEADER = $(HEADER_B)
endif

.PHONY: all re clean fclean re bonus

all : $(NAME)

bonus : $(NAME_B)

.c.o : %.c $(HEADER)
	$(CC) -c $<

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) -o $@ $^ -L$(LIB_DIR) -lft

$(NAME_B) : $(OBJS_B) $(LIB_DIR)/$(LIB)
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