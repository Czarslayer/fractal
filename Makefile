
NAME = fractal

FLAGS = -Wall -Wextra -Werror

SRC = mandelbrot.c \
	  julia.c \
	  burning_ship.c \
	  tools.c \
	  main.c\

SRC_LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(SRC_LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re