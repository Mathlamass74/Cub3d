NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
GNL_DIR = GNL
GNL_SRC = $(GNL_DIR)/get_next_line.c
LIBFT_DIR = Libft
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
INCLUDES = -IIncludes
CUBE_DIR = Srcs
CUBE_SRC = $(wildcard $(CUBE_DIR)/*.c)

SRCS = $(GNL_SRC) $(LIBFT_SRC) $(CUBE_SRC)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
