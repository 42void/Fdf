SRC =	main.c draw.c parser.c get_next_line.c hook.c ft_error.c
OBJ =	$(SRC:.c=.o)
FLG =	-Wall -Werror -Wextra
NAME =	fdf

all: $(NAME)

$(NAME):
	@make -C libft/
	gcc $(FLG) -c $(SRC) -I libft/includes -L libft/ -lft -L /usr/X11/lib -lmlx -lXext -lX11
	gcc $(FLG) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft -L /usr/X11/lib -lmlx -lXext -lX11

clean:
	@make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
