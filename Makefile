# ======================================================
# Compiler
# ======================================================
CC = gcc

# ======================================================
# Project
# ======================================================
NAME = myshell

# ======================================================
# Sources
# ======================================================
SRC = \
	src/myshell.c \
	src/execute.c \
	src/redirect.c \
	src/builtin.c \
	src/path.c \
	src/print_prompt.c \
	src/signals.c \
	commands/ls.c \
	commands/cat.c \
	commands/mkdir.c \
	commands/history.c \
	commands/touch.c

# ======================================================
# Objects
# ======================================================
OBJ = $(SRC:.c=.o)

# ======================================================
# Compiler flags
# ======================================================
CFLAGS = -Wall -Wextra -Werror -Iinclude

# ======================================================
# Libraries
# ======================================================
LIBS = -lreadline

# ======================================================
# Rules
# ======================================================
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ)
	rm -f history.txt

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re