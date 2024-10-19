NAME = fractol

SRC = src/main.c  src/init.c src/render.c src/utils.c src/events.c
OBJ = $(SRC:.c=.o)

MLX_DIR = ./minilibx-linux

INCLUDES = -I includes -I $(MLX_DIR)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)

LDFLAGS = $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
