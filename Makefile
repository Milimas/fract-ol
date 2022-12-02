NAME=fractol

CFLAGS= -Lmlx -lmlx -framework OpenGL -framework AppKit

CC= cc

SRC= main.c put_pixel.c create_trgb.c

OBJ= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
