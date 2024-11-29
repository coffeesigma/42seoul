NAME = megaphone
CPP = c++
FLAGS = -Wall -Wextra -Werror --std=c++98
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
