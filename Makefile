NAME = fractol
BONUS_NAME = fractol_bonus
FRACTOL = fractol.a
FRACTOL_BONUS = fractol_bonus.a
LIB = libft.a

LIB_DIR = libft/
MLX_DIR = mlx/

CFLAGS= -Lmlx -lmlx -framework OpenGL -framework AppKit

CC= cc

SRC_DIR = src/
BONUS_DIR = bonus/
SRC_FILES = fractol.c create_trgb.c get_trgb.c put_pixel.c iterate.c mandelbrot.c julia.c get_mouse_pos.c \
			update.c on_gui.c burningship.c point.c help.c parse_arg.c on_trigger.c on_mouse.c
BONUS_FILES = fractol_bonus.c create_trgb_bonus.c get_trgb_bonus.c put_pixel_bonus.c iterate_bonus.c mandelbrot_bonus.c julia_bonus.c get_mouse_pos_bonus.c \
			update_bonus.c on_gui_bonus.c burningship_bonus.c point_bonus.c help_bonus.c parse_arg_bonus.c on_trigger_bonus.c on_mouse_bonus.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))

OBJ_DIR = obj/
BOBJ_DIR = bobj/

OBJ= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
BOBJ= $(BONUS:$(BONUS_DIR)%.c=$(BOBJ_DIR)%.o)

$(NAME):$(FRACTOL) $(SRC_DIR)$(NAME).h
	@echo Compiling $@
	@$(CC) $(FRACTOL) $(LIB) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"

$(FRACTOL): $(LIB) $(OBJ)
	@echo Compiling $@
	@ar rcs $(FRACTOL) $(OBJ) $(LIB)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"

$(FRACTOL_BONUS): $(LIB) $(BOBJ)
	@echo Compiling $@
	@ar rcs $(FRACTOL_BONUS) $(BOBJ) $(LIB)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"

$(LIB): $(LIB_DIR)libft.h
	@$(MAKE) -C $(LIB_DIR)
	@mv $(LIB_DIR)$(LIB) .

$(BONUS_NAME): $(FRACTOL_BONUS) $(BONUS_DIR)$(BONUS_NAME).h
	@echo Compiling $@
	@$(CC) $(FRACTOL_BONUS) $(LIB) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit -o $(BONUS_NAME)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"

bonus: $(BONUS_NAME)

mlx:
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	@echo "$@ \033[32;1m"Compiled"\033[K\x1b[1A\033[0m"

$(BOBJ_DIR)%.o:$(BONUS_DIR)%.c
	@mkdir -p $(BOBJ_DIR)
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	@echo "$@ \033[32;1m"Compiled"\033[K\x1b[1A\033[0m"

all: $(NAME) bonus

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(OBJ_DIR) "\033[31;1m"removed"\033[0m"
	@echo $(NAME) "\033[32;1m"cleaned"\x1b[1A\x1b[M\033[0m"
	@rm -rf $(BOBJ_DIR)
	@echo $(BOBJ_DIR) "\033[31;1m"removed"\033[0m"
	@echo $(BONUS_NAME) "\033[32;1m"cleaned"\x1b[1A\x1b[M\033[0m"
	@$(MAKE) clean -C $(LIB_DIR)
	@echo $(LIB_DIR) "\033[32;1m"cleaned"\x1b[1A\x1b[M\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) "\033[31;1m"removed"\033[0m"
	@rm -f $(BONUS_NAME)
	@echo $(BONUS_NAME) "\033[31;1m"removed"\033[0m"
	@rm -f $(LIB)
	@echo $(LIB) "\033[31;1m"removed"\033[0m"
	@rm -f $(FRACTOL)
	@echo $(FRACTOL) "\033[31;1m"removed"\033[0m"
	@rm -f $(FRACTOL_BONUS)
	@echo $(FRACTOL_BONUS) "\033[31;1m"removed"\033[0m"

re: fclean all

.PHONY: all clean fclean re mlx bonus
