NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = philo.c parse.c init.c utils.c philosopher.c actions.c monitor.c threads.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re