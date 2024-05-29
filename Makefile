# Name executable
NAME = so_long

# Source Files
SRC = $(addprefix srcs/, main.c so_long_map_test.c so_long_utils.c)
GNL_SRC = $(addprefix gnl/, get_next_line_utils.c get_next_line.c)
PRINTF_SRC = $(addprefix ft_printf/, ft_printf_utils.c ft_printf.c ft_put_printf.c)
OBJ =  $(SRC:.c=.o)
GNL_OBJ := $(GNL_SRC:.c=.o)
PRINTF_OBJ := $(PRINTF_SRC:.c=.o)

# Compilation
CFLAGS = -Wall -Wextra -Werror

# Contient les fichiers d'en-tête X11 et MLX
INCLUDES = -I/usr/include -Imlx

# Lier X11 et MLX
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	gcc $(CFLAGS) $^ $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

.c.o:
	gcc $(CCFLAGS) $(MLX_FLAGS) $(INCLUDES) -Iincludes -c $< -o ${<:.c=.o}

clean:
	rm -rf $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all