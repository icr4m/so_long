# Name executable
NAME = so_long

# Source Files
SRCS = main.c \
	so_long_map_test.c 

GNL_SRCS = $(addprefix gnl/, get_next_line_utils.c get_next_line.c)

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Contient les fichiers d'en-tête X11 et MLX
INCLUDES = -I/usr/include -Imlx

# Lier X11 et MLX
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Rules
all: $(NAME)

$(NAME): $(SRCS) $(GNL_SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX_FLAGS) $(INCLUDES)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all