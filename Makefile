# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 15:00:08 by arapaill          #+#    #+#              #
#    Updated: 2020/02/13 16:09:55 by arapaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
NC = \033[0m
NAME = printf
SRCS = main.c printf_arg1.c ft_printf.c ft_printf_utils.c flags.c
FLAGS = -Wall -Werror -Wextra
all: $(NAME)
$(NAME):
	@make re -C ./libft
	@echo "${GREEN}Libft Done ✓${NC}"
	@make clean
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -L libft/ -lft
	@echo "${GREEN}Compilation Done ✓${NC}"
clean:
	@make clean -C ./libft
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
re: fclean all