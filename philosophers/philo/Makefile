CC = cc -Wall -Wextra -Werror
HEADER = philo.h
SRCS = init.c utils.c utils2.c main.c philo.c simulation.c
OBJS = $(SRCS:.c=.o)
NAME = philo

.PHONY: all re clean fclean re bonus

all : $(NAME)

.c.o : %.c $(HEADER)
	$(CC) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lpthread

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all