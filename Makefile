NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = ft_printf.c \
              ft_print_chars.c \
              ft_print_nbr.c \
              ft_print.hex.c

OBJS        = $(SRCS:.c=.o)

RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re