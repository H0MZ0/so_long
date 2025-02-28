CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC = so_long.c map_parsing.c GNL/get_next_line.c GNL/get_next_line_utils.c ft_helpers.c
OBJ = $(SRC:.c=.o)

NAME = so_long
PRINTF_DIR = Printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF_LIB)
	@$(CC) $(CFLAGS) $(PRINTF_LIB) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
