CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = pipex.c pipex_utils.c
SRC_P = ft_printf/ft_printf.c ft_printf/ft_putchar_fd.c ft_printf/ft_putstr_fd.c ft_printf/ft_puthex_fd.c ft_printf/ft_putptr_fd.c ft_printf/ft_uputnbr_fd.c ft_printf/ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)
OBJS = $(SRC_P:.c=.o)
NAME = pipex

all: $(NAME)

$(NAME): $(OBJS) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re