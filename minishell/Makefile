NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
LIB_DIR = lib

LIBFT = $(LIB_DIR)/libft.a

SRCS = \
	$(SRC_DIR)/main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJS)


fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
