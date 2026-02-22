SHELL = /bin/sh
NAME = rush-02
CC = cc
SRCS = dict.c ft_split.c ft_strcmp.c ft_strncpy.c ft_util.c interactive.c main.c run.c str_big_int.c
HDRS = rush02.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -std=c11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

norm:
	@norminette $(SRCS) $(HDRS)

# Test with one argument
test: $(NAME)
	./$(NAME) 42

# Test with two arguments
test-dict: $(NAME)
	./$(NAME) numbers_dict 42

# Leaks - checks
leaks: $(NAME)
	leaks -atExit -- ./$(NAME) 42

leaks-dict: $(NAME)
	leaks -atExit -- ./$(NAME) numbers_dict 42

valgrind: $(NAME)
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes -s ./$(NAME) 42

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all norm test test-dict leaks leaks-dict valgrind clean fclean re
