CC = cc -Wall -Wextra -Werror
LIB_DIR = ./libft
LIB = libft.a
MLX_DIR = ./mlx
MLX = libmlx.dylib
HEADER = so_long.h
HEADER_B = so_long_bonus.h
SRCS = main.c utils.c init.c map_check.c
SRCS_B = 
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = so_long
NAME_B = so_long_bonus

ifdef WITH_BONUS
	HEADER = $(HEADER_B)
endif

.PHONY: all re clean fclean re bonus

all : $(NAME)

bonus : $(NAME_B)

.c.o : %.c $(HEADER)
	$(CC) -c $<

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB) $(MLX_DIR)/$(MLX)
	$(CC) -o $@ $(OBJS) -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(NAME_B) : $(OBJS_B) $(LIB_DIR)/$(LIB)
	$(CC) -o $(NAME_B) $(OBJS_B) -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME_B)

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)
	make bonus -C $(LIB_DIR)

$(MLX_DIR)/$(MLX) :
	make -C $(MLX_DIR)

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	make fclean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	make clean -C $(MLX_DIR)

re : fclean all