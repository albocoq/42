NAME = libftprintf.a
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FILES = ft_printf.c \
		libft/ft_strlen.c \
		libft/ft_putnbr.c \
		libft/ft_putchar.c \
		src/ft_inttype.c \
		src/ft_charactertype.c \
		src/ft_pourcentagetype.c \
		src/ft_pointertype.c \
		src/ft_stringtype.c \
		src/ft_hexnumbertype.c \
		src/ft_putbase.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
