CC = cc -Wall -Wextra -Werror
HEADER = philo.h
SRCS = 
OBJS = $(SRCS_M:.c=.o)
NAME = philo

.PHONY: all re clean fclean re bonus

all : $(NAME)

.c.o : %.c $(HEADER)
	$(CC) -c $< -o ${<:.c=.o} -lpthread

$(NAME) : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all