NAME = libft.a
SRCS = ./x_malloc.c ./ft_realloc.c ./ft_itoa_base_big_ll.c ./ft_itoa_base_big_l.c ./ft_itoa_base_big_h.c ./ft_itoa_base_big_hh.c ./ft_itoa_base_small_h.c ./ft_itoa_base_small_hh.c ./ft_itoa_base_small_l.c ./ft_itoa_base_small_ll.c ./ft_utoa_hh.c ./ft_utoa_h.c ./ft_utoa_l.c ./ft_utoa_ll.c ./ft_itoa_h.c ./ft_itoa_hh.c ./ft_itoa_l.c ./ft_itoa_ll.c  ./ft_catstr.c ./ft_itoa_base_small.c ./ft_itoa_base_big.c ./get_next_line.c ./ft_atoi.c ./ft_utoa.c ./ft_strrev.c ./ft_bzero.c ./ft_strrejoin.c ./ft_isalnum.c ./ft_strchr_n.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_strcat.c ./ft_strchr.c ./ft_strcmp.c ./ft_strcpy.c ./ft_strdup.c ./ft_strlcat.c ./ft_strlen.c ./ft_strncat.c ./ft_strncmp.c ./ft_strncpy.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strstr.c ./ft_tolower.c ./ft_toupper.c ./ft_itoa.c ./ft_memalloc.c ./ft_memdel.c ./ft_putchar.c ./ft_putchar_fd.c ./ft_putendl.c ./ft_putendl_fd.c ./ft_putnbr.c ./ft_putnbr_fd.c ./ft_putstr.c ./ft_putstr_fd.c ./ft_strclr.c ./ft_strdel.c ./ft_strequ.c ./ft_striter.c ./ft_striteri.c ./ft_strjoin.c ./ft_strmap.c ./ft_strmapi.c ./ft_strnequ.c ./ft_strnew.c ./ft_strsplit.c ./ft_strsub.c ./ft_strtrim.c ./ft_lstadd.c ./ft_lstdel.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lstnew.c ./ft_atoi_base.c
OBJS = $(SRCS:.c=.o)
INCLUDE = libft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) ./*.o

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
