# Nom de l'exécutable
NAME = so_long

# Contient les fichiers d'en-tête X11 et MLX
INCLUDES = -I/usr/include -Imlx

# Lier X11 et MLX
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Fichiers sources
SRCS = main.c \
	so_long_pixel.c \
	so_long_utils.c

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Règles
all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX_FLAGS) $(INCLUDES)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all