NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
LIB_DIR = lib
BUILTIN_DIR = builtins
EXECUTION_DIR = executions
PARSING_DIR = parsing

LIBFT = $(LIB_DIR)/libft.a

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/utilits_main.c \
	$(SRC_DIR)/$(PARSING_DIR)/verify_input.c \
	$(SRC_DIR)/$(PARSING_DIR)/verify_input_utils.c \
	$(SRC_DIR)/$(PARSING_DIR)/lexer.c \
	$(SRC_DIR)/$(PARSING_DIR)/lexer_utils.c \
	$(SRC_DIR)/$(PARSING_DIR)/lexer_tokens.c \
	$(SRC_DIR)/$(PARSING_DIR)/parser.c \
	$(SRC_DIR)/$(PARSING_DIR)/parser_utils.c \
	$(SRC_DIR)/$(PARSING_DIR)/var_expantion.c \
	$(SRC_DIR)/$(PARSING_DIR)/var_expantion_utils.c \
	$(SRC_DIR)/$(PARSING_DIR)/free_elements.c \
	$(SRC_DIR)/$(PARSING_DIR)/prints.c \
	$(SRC_DIR)/$(PARSING_DIR)/prints_utils.c \
	$(SRC_DIR)/$(BUILTIN_DIR)/utilits.c \
	$(SRC_DIR)/$(BUILTIN_DIR)/utilits_env.c \
	$(SRC_DIR)/$(BUILTIN_DIR)/utilits_export.c \
	$(SRC_DIR)/$(BUILTIN_DIR)/builtins.c \
	$(SRC_DIR)/$(BUILTIN_DIR)/builtins2.c \
	$(SRC_DIR)/$(BUILTIN_DIR)/error.c \
	$(SRC_DIR)/$(EXECUTION_DIR)/executor.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
	@clear
	@echo "✅ ${NAME} is compiled."

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJS)
	@clear
	@echo "🗑️ Objects removed."

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)
	@clear
	@echo "🗑️ Program and objects removed."

re: fclean all
