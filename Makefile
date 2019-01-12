NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 	sources/line.c \
		sources/format.c \
		sources/main.c

OBJ = $(SRC:.c=.o)

LIBPATH = libft/libft.a

.PHONY: all re clean fclean

$(NAME):
	@cd libft; $(MAKE) -f Makefile
	@make $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH)

all: $(NAME)

re: fclean all

clean:
	@cd libft; $(MAKE) -f Makefile clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(LIBPATH)
