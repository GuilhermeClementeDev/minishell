# -*- MakeFile -*-
CC = cc

NAME = libft.a

MY_SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c \
ft_toupper.c ft_tolower.c ft_atoi.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
ft_strmapi.c ft_printf.c ft_printf_char.c ft_printf_string.c \
ft_printf_number.c ft_printf_unsigned_num.c ft_printf_hex.c \
ft_printf_pointer.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
get_next_line.c get_next_line_utils.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(MY_SOURCES:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)


re: fclean all

