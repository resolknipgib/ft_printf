NAME = libftprintf.a
SRC = printf/ft_printf.c printf/convert_hex.c printf/ft_utoa.c printf/letter_conditionals.c
OBJ = $(SRC:.c=.o)
LIB_PATH = ./libft
HEADERS	= printf/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) all -C $(LIB_PATH)
		ar rcs $(NAME) $(OBJ) $(LIB_PATH)/*.o


%.o: %.c ${HEADERS}
		cc -Wall -Wextra -Werror -c $< -o $@

clean:
		$(MAKE) clean -C $(LIB_PATH)
		rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
		$(MAKE) fclean -C $(LIB_PATH)
		rm -rf $(NAME)
    
re: fclean all

.PHONY: all clean fclean re