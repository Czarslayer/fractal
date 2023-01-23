
NAME = fractol

CFLAGS = -Wall -Wextra -Werror

SRC = mandelbrot.c \
	  julia.c \
	  burning_ship.c \
	  main.c\
	  tools.c \
	  tools2.c \
	  libft_tools.c \
	  error.c \

DARKBLUE = \033[1;34m
RED = \033[1;31m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
GREEN = \033[1;32m
RED_UNDERLINE = \033[4;31m\033[1;31m

END = \033[0m

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)	
	@echo "${GREEN}compiling fractal program...${END}"
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "${GREEN}fractal program compiled!${END}"
	@clear
	@sleep 0.5
	@echo "${CYAN}====================================================================================================${END}"
	@echo "${DARKBLUE}/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ ${END}"
	@echo "${CYAN}====================================================================================================${END}"
	@sleep 0.5
	@echo "${DARKBLUE}   _____  ______           _____    ______  _____              _____  _______        ____   _      "
	@echo "  / ____||___  /    /\    |  __ \  |  ____||  __ \     /\     / ____||__   __|      / __ \ | |     "
	@echo " | |        / /    /  \   | |__| | | |__   | |__| |   /  \   | |        | | ______ | |  | || |     "
	@echo " | |       / /    / /\ \  |  _  /  |  __|  |  _  /   / /\ \  | |        | ||______|| |  | || |     "
	@echo " | |____  / /__  / ____ \ | | \ \  | |     | | \ \  / ____ \ | |____    | |        | |__| || |____ "
	@echo "  \_____|/_____|/_/    \_\|_|  \_\ |_|     |_|  \_\/_/    \_\ \_____|   |_|         \____/ |______|${END}"
	@sleep 0.5
	@echo "${CYAN}====================================================================================================${END}"
	@echo "${DARKBLUE}/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/${RED_UNDERLINE}By Mabahani${END}${DARKBLUE}\/ ${END}"
	@echo "${CYAN}====================================================================================================${END}"
	@sleep 0.5
	@echo
	@echo "   ${DARKBLUE}Hello there,${YELLOW} welcome to my fractal program${END}"
	@sleep 0.1
	@echo "                ${YELLOW}you can choose between mandelbrot, julia and burningship${END}"
	@sleep 0.1
	@echo "                ${YELLOW}you can also zoom in and out with the ${WHITE}[mouse wheel]${END}"
	@sleep 0.1
	@echo "                ${YELLOW}and move around with the arrow keys ${WHITE}[left]${END} ${WHITE}[right]${END} ${WHITE}[up]${END} ${WHITE}[down]${END}"
	@sleep 0.1
	@echo "                ${YELLOW}if you want to go back to original zoom, press${WHITE} [the wheel]${END}"
	@sleep 0.1
	@echo "                ${YELLOW}if you want to change the color, press${WHITE} [h] [j] [k] [l]${END}"
	@sleep 0.1
	@echo "                ${YELLOW}if you want to quit, press${WHITE} [esc] ${END}"
	@sleep 0.5
	@echo
	@echo "                    =========================================="
	@echo "                    || ${CYAN}how to use: ${RED}./fractol [fractal name] ${END}||"
	@echo "                    =========================================="
	@echo


all: $(NAME)

bonus: all

clean:
	@rm -f $(OBJ)

fclean: clean
	@clear
	@rm -f $(NAME)

re: fclean all

czar: all clean

.PHONY:all clean fclean re czar bonus