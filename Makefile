# Nome dell'eseguibile
NAME = fractol

# Sorgenti e oggetti
SRC = src/main.c  src/init.c src/render.c src/utils.c src/events.c
OBJ = $(SRC:.c=.o)

# Percorso della libreria MiniLibX
MLX_DIR = ./minilibx-linux

# Include directories
INCLUDES = -I includes -I $(MLX_DIR)

# Flags di compilazione
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)

# Flags di linking
LDFLAGS = $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm

# Regola per creare l'eseguibile
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

# Regola per compilare i file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regole per pulire
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
