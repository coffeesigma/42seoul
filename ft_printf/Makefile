CC = cc -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h
LIB_DIR = ./libft
LIB = libft.a
NAME = libftprintf.a

.PHONY: all re clean fclean

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	cp $(LIB_DIR)/$(LIB) $@
	ar rc $@ $(OBJS)

.c.o : %.c $(HEADER)
	$(CC) -c $<

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)

clean :
	rm -rf $(OBJS)
	make clean -C $(LIB_DIR)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)

re : fclean all

