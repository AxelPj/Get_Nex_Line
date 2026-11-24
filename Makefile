CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

NAME = libmy_get_next_line.a
SRCS = my_get_next_line.c my_get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BONUS_NAME = libmy_get_next_line_bonus.a
BONUS_SRCS = my_get_next_line_bonus.c my_get_next_line_utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(BONUS_NAME) $(BONUS_OBJS)

my_get_next_line.o: my_get_next_line.c my_get_next_line.h
	$(CC) $(CFLAGS) -c my_get_next_line.c -o my_get_next_line.o

my_get_next_line_utils.o: my_get_next_line_utils.c my_get_next_line.h
	$(CC) $(CFLAGS) -c my_get_next_line_utils.c -o my_get_next_line_utils.o

my_get_next_line_bonus.o: my_get_next_line_bonus.c my_get_next_line_bonus.h
	$(CC) $(CFLAGS) -c my_get_next_line_bonus.c -o my_get_next_line_bonus.o

my_get_next_line_utils_bonus.o: my_get_next_line_utils_bonus.c my_get_next_line_bonus.h
	$(CC) $(CFLAGS) -c my_get_next_line_utils_bonus.c -o my_get_next_line_utils_bonus.o

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
