NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj/

FILES = \
	ft_atoi.c     ft_isprint.c	 	ft_lstlast.c  ft_memmove.c		ft_strchr.c    ft_strmapi.c  ft_toupper.c \
	ft_bzero.c    ft_itoa.c		 	ft_lstmap.c   ft_memset.c		ft_strdup.c    ft_strncmp.c  get_next_line.c \
	ft_calloc.c   ft_lstadd_back.c	ft_lstnew.c   ft_putchar_fd.c	ft_striteri.c  ft_strnstr.c	 gnl_utils.c \
	ft_isalnum.c  ft_lstadd_front.c ft_lstsize.c  ft_putendl_fd.c	ft_strjoin.c   ft_strrchr.c  ft_isnumber.c \
	ft_isalpha.c  ft_lstclear.c	 	ft_memchr.c   ft_putnbr_fd.c	ft_strlcat.c   ft_strtrim.c \
	ft_isascii.c  ft_lstdelone.c	ft_memcmp.c   ft_putstr_fd.c	ft_strlcpy.c   ft_substr.c \
	ft_isdigit.c  ft_lstiter.c		ft_memcpy.c   ft_split.c		ft_strlen.c    ft_tolower.c \

OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(FILES))

$(OBJ_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
