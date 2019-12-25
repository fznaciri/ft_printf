CFLAGS =  -Wall -Wextra -Werror -c
CC = gcc
NAME = libftprintf.a
SRC = ft_printf.c str_auxiliary.c flags.c print_number.c print_scp.c num_auxiliary.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C libft
	@$(CC) $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)

bonus: $(NAME)
clean :
	@rm -rf $(OBJ) ./libft/*.o
	@make -C libft clean
fclean : clean
	@rm $(NAME)
	@make -C libft fclean
re : fclean all
