NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I .

SRC_DIR     = src
SRCS        = $(SRC_DIR)/check_utils.c \
              $(SRC_DIR)/errors.c \
              $(SRC_DIR)/indexing.c \
              $(SRC_DIR)/list_utils.c \
              $(SRC_DIR)/node_utils.c \
              $(SRC_DIR)/parse.c \
              $(SRC_DIR)/push_operations.c \
              $(SRC_DIR)/radix.c \
              $(SRC_DIR)/rotate_operations.c \
              $(SRC_DIR)/rr_operations.c \
              $(SRC_DIR)/swap_operations.c \
              $(SRC_DIR)/small_sort.c \
              $(SRC_DIR)/push_swap_logic.c \
			  $(SRC_DIR)/fill_stack.c \
              push_swap.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = Libft
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
