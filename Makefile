NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Linux
#MLX_DIR = minilibx-linux
#MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm

# Macos
MLX_DIR = mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework AppKit -framework OpenGL

MLX = $(MLX_DIR)/libmlx.a

LIBFTDIR = Libft
LIBFT_INC = -I $(LIBFTDIR)/Includes
LIBFT_LINK = -L $(LIBFTDIR) -lft

INCLUDES = -I Includes $(LIBFT_INC)
CUBE_DIR = Srcs
CUBE_SRC = $(wildcard $(CUBE_DIR)/*.c)
OBJ_DIR = obj/

SRCS = $(CUBE_SRC)
OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT_LINK)

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLX_DIR)

all: $(NAME)

clean:
	make -C $(LIBFTDIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
