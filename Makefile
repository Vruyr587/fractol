NAME = fractol
SRC_DIR = src
INC_DIR = includes
MLX_DIR = minilibx-linux
LIBFT_DIR = libft

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/controls.c $(SRC_DIR)/events.c $(SRC_DIR)/utils.c \
		$(SRC_DIR)/init.c $(SRC_DIR)/pixel.c $(SRC_DIR)/render.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR)

MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_FLAGS = -L $(MLX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext -lm
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB) 
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_LIB) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

%.o: %.c $(INC_DIR)/fractol.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
