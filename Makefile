NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I./include

SRC_DIR		= src/
OBJ_DIR		= obj/

SRC_FILES	= ft_printf.c \
			  ft_print_chars.c \
			  ft_print_hex.c \
			  ft_print_numbers.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

