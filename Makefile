
NAME = fractal

FLAGS = -Wall -Wextra -Werror

SRC = mandelbrot.c \
	  julia.c \
	  burning_ship.c \
	  main.c\
	  tools.c \
	  tools2.c \
	  libft_tools.c \

DARKBLUE = \033[1;34m
RED = \033[1;31m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
GREEN = \033[1;32m

END = \033[0m
#.SILENT:
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@echo "${GREEN}compiling fractal program...${END}"
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "${GREEN}fractal program compiled!${END}"
	@echo "${CYAN}====================================================================================================${END}"
	@echo "${DARKBLUE}/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ ${END}"
	@echo "${CYAN}====================================================================================================${END}"
	@echo "${DARKBLUE}   _____  ______           _____    ______  _____              _____  _______        ____   _      "
	@echo "  / ____||___  /    /\    |  __ \  |  ____||  __ \     /\     / ____||__   __|      / __ \ | |     "
	@echo " | |        / /    /  \   | |__| | | |__   | |__| |   /  \   | |        | | ______ | |  | || |     "
	@echo " | |       / /    / /\ \  |  _  /  |  __|  |  _  /   / /\ \  | |        | ||______|| |  | || |     "
	@echo " | |____  / /__  / ____ \ | | \ \  | |     | | \ \  / ____ \ | |____    | |        | |__| || |____ "
	@echo "  \_____|/_____|/_/    \_\|_|  \_\ |_|     |_|  \_\/_/    \_\ \_____|   |_|         \____/ |______|${END}"
	@echo "${CYAN}====================================================================================================${END}"
	@echo "${DARKBLUE}/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ ${END}"
	@echo "${CYAN}====================================================================================================${END}"

	@echo "   ${DARKBLUE}HELLO THERE,${YELLOW} welcome to my fractal program${END}"
	@echo "                ${YELLOW}you can choose between mandelbrot, julia and burningship${END}"
	@echo "                ${YELLOW}you can also zoom in and out with the ${WHITE}[mouse wheel]${END}"
	@echo "                ${YELLOW}and move around with the arrow keys ${WHITE}[left]${END} ${WHITE}[right]${END} ${WHITE}[up]${END} ${WHITE}[down]${END}"
	@echo "                ${YELLOW}if you want to go back to original zoom, press${WHITE} [the wheel]${END}"
	@echo "                    =========================================="
	@echo "                    || ${CYAN}how to use: ${RED}./fractol [fractal name] ${END}||"
	@echo "                    =========================================="


all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re