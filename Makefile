# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmills <kmills@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 18:35:07 by kmills            #+#    #+#              #
#    Updated: 2019/09/05 16:38:12 by kmills           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME):
	@gcc ./libft/libft.a $(SRCS) -o $(NAME) ./libft/libftprintf.a

g:
	@gcc ./libft/libft.a $(SRCS) -g -o $(NAME)

clean:
	@$(MAKE) -C ./libft clean
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

lib:
	@$(MAKE) -C ./libft re
	@$(MAKE) -C ./libft clean

git:
	git add .
	git commit -am "$(G)"
	git push
