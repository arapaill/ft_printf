# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 15:00:08 by arapaill          #+#    #+#              #
#    Updated: 2020/03/10 10:00:16 by arapaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
NC = \033[0m
NAME = libftprintf.a
SRCS = printf_arg1.c printf_arg2.c ft_printf.c ft_printf_utils.c ft_printf_utils2.c flags.c flags2.c
FLAGS = -Wall -Werror -Wextra
LIB = ar rcs
CC = @gcc
OBJ         =   $(SRCS:.c=.o)
all: $(NAME)
$(NAME):    $(OBJ)
			@make -C ./libft
			@cp ./libft/libft.a $(NAME)
			@$(LIB) $(NAME) ${OBJ}
clean:
	@make clean -C ./libft
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
re: fclean all

exec:	re
		@gcc ${FLAGS} ${NAME} main.c
		@./a.out