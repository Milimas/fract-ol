NAME=fractol

CFLAGS= -Lmlx -lmlx -framework OpenGL -framework AppKit

CC= cc

SRC= put_pixel.c create_trgb.c

OBJ= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) main.c $(OBJ) -o $(NAME) -fsanitize=address -g

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
