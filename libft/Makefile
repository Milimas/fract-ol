NAME = libft.a

CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)
OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)


$(NAME): $(OBJS)
	@echo Compiling $@
	@$(AR) rcs $(NAME) $(OBJS)
	@echo $@ "\033[32;1m"Compiled"\x1b[1A\x1b[M\033[0m"

all: $(NAME)

$(OBJ_DIR)%.o:%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ \033[32;1m"Compiled"\033[K\x1b[1A\033[0m"


clean:
	@rm -rf $(OBJ_DIR)
	@echo $(OBJ_DIR) "\033[31;1m"removed"\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) "\033[31;1m"removed"\033[0m"

re: fclean all

.PHONY: all clean fclean re
