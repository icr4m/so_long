# Name executable
NAME = so_long

# Source Files
SRC = $(addprefix srcs/, main.c map_parsing.c so_long_utils.c map_parsing_utils.c init_game.c path_finder.c display.c load.c free.c player_move.c itoa.c)
GNL_SRC = $(addprefix gnl/, get_next_line_utils.c get_next_line.c)
FT_PRINTF_SRC = $(addprefix ft_printf/, ft_printf_utils.c ft_printf.c ft_put_printf.c)
OBJ =  $(SRC:.c=.o)
GNL_OBJ := $(GNL_SRC:.c=.o)
FT_PRINTF_OBJ := $(FT_PRINTF_SRC:.c=.o)
MLX_PATH = ./mlx

# Compilation
CFLAGS = -Wall -Wextra -Werror

# Contient les fichiers d'en-tête X11 et MLX
INCLUDES = -I/usr/include -Imlx

# Lier X11 et MLX
MLX_FLAGS =  $(MLX_PATH)/libmlx.a $(MLX_PATH)/libmlx_Linux.a -lX11 -lXext

# Colors

GREEN=\033[0;32m
BROWN=\033[0;33m
NO_COLOR=\033[0m

# Rules
all: $(MLX_PATH)/libmlx.a $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(FT_PRINTF_OBJ)
	make  $(MLX_PATH)
	cc $(CFLAGS) $^ $(MLX_FLAGS) $(INCLUDES) -o $(NAME)
	@echo "$$ASCII"

$(MLX_PATH)/libmlx.a:
	make -C $(MLX_PATH)

.c.o:
	cc $(CCFLAGS) $(MLX_FLAGS) $(INCLUDES) -Iincludes -c $< -o ${<:.c=.o}

clean:
	rm -rf $(OBJ) $(GNL_OBJ) $(FT_PRINTF_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

define ASCII

$(GREEN)          &&& &&  & &&               $(NO_COLOR)
$(GREEN)      && &\/&\|& ()|/ @, &&            $(NO_COLOR)
$(GREEN)      &\/(/&/&||/& /_/)_&/_&          $(NO_COLOR)
$(GREEN)   &() &\/&|()|/&\/ '%\" & ()          $(NO_COLOR)
$(GREEN)  &_\_&&_\ |& |&&/&__%_/_& &&         $(NO_COLOR)
$(GREEN) &&   && & &| &| /& & % ()& /&&       $(NO_COLOR)
$(GREEN)     ()&_---()&\&\|&&-&&--%---()     $(NO_COLOR)
$(BROWN)                 ||                $(NO_COLOR)
$(BROWN)                 ||                $(NO_COLOR)
$(BROWN)                 ||                $(NO_COLOR)
$(BROWN)                 ||                $(NO_COLOR)
$(BROWN)           ______||______           $(NO_COLOR)
$(BROWN)           \SO LONG MAKED/           $(NO_COLOR)

endef
export ASCII

.PHONY: all clean fclean re