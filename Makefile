NAME = minishell
CC = gcc
CFLAGS = -g #-Wall -Werror -Wextra 

SRC = $(wildcard src/*.c) \
	  $(wildcard src/binaries/*.c) \
      $(wildcard src/builtins/*.c) \
      $(wildcard src/executor/*.c) \
      $(wildcard src/parser/*.c) \
      $(wildcard src/signals/*.c) \
      $(wildcard src/utils/*.c) 
OBJ = $(SRC:%.c=obj/%.o)

LIBFT_PATH = libft
LIBFT_FILE = $(LIBFT_PATH)/libft.a
READLINE_LIB = -lreadline

all: $(NAME)

$(NAME): $(LIBFT_FILE) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FILE) $(READLINE_LIB) -o $(NAME)

$(LIBFT_FILE):
	make -C $(LIBFT_PATH)

clean:
	rm -rf ./obj
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

obj/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
