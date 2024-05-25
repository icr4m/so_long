NAME = so_long

# Contains the X11 and MLX header files
INCLUDES = -I/usr/include -Imlx

# Link X11 and MLX
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Source files
SRCS = main.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Archives
AR = ar rc 

# rules
all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
	
clean:
	rm -rf ${OBJS} ${OBJS_B}

fclean: clean
	rm -rf $(NAME)

re: fclean all