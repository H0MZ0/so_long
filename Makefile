CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC = so_long.c map_parsing.c GNL/get_next_line.c GNL/get_next_line_utils.c ft_helpers.c error.c \
		check_walls.c 
OBJ = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_LIB)
	@$(CC) $(CFLAGS) $(PRINTF_LIB) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
