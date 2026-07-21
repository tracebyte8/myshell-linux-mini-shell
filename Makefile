# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Libraries
LIBS = -lreadline

# Executable name
NAME = myshell

# Source files
SRC =	src/myshell.c \
		src/execute.c \
		src/redirect.c \
		src/builtin.c \
		src/path.c \
		commands/ls.c \
		commands/cat.c \
		commands/mkdir.c \
		commands/touch.c

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJ)

# Remove executable and object files
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re