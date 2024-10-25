CC = cc
CFLAGS = -Werror -Wall -Wextra

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run:
	$(CC) test.c $(CFLAGS) -lft -L.