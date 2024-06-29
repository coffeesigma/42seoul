CC = cc -Wall -Wextra -Werror
LIB_DIR = ./libft
LIB = libft.a
HEADER_M = mandatory/pipex.h
HEADER_B = bonus/pipex_bonus.h
SRCS_M = main.c
SRCS_B = main_bonus.c
OBJS_M = $(addprefix mandatory/, ${SRCS_M:.c=.o})
OBJS_B = $(addprefix bonus/, ${SRCS_B:.c=.o})
NAME = pipex

ifdef WITH_BONUS
	OBJS = $(OBJS_B)
	HEADER = $(HEADER_B)
else
	OBJS = $(OBJS_M)
	HEADER = $(HEADER_M)
endif

.PHONY: all re clean fclean re bonus

all : $(NAME)

bonus :
	make WITH_BONUS=1

.c.o : %.c $(HEADER)
	$(CC) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) -o $@ $(OBJS) -L$(LIB_DIR) -lft

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)
	make bonus -C $(LIB_DIR)

clean :
	rm -f $(OBJS_M)
	rm -f $(OBJS_B)
	make fclean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all