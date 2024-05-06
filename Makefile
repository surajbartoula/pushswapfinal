# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 06:35:38 by sbartoul          #+#    #+#              #
#    Updated: 2024/04/29 14:53:00 by sbartoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_PATH = ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF_PATH)libftprintf.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = 	push_swap.c     	\
			argumentstolst.c	\
			bigsort.c			\
			errors.c			\
			indexsorting.c		\
			libft.c				\
			lst_operations.c	\
			papb.c				\
			rarbrr.c			\
			sasb.c				\
			sort.c				\
			stacksortcheck.c	\
			split.c				\

OBJECTS = ${CFILES:.c=.o}

all: subsystems $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)

subsystems:
	@echo $(B)
	make -C $(FT_PRINTF_PATH) all

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJECTS) $(FT_PRINTF_LIB) -o $(NAME)
	@echo $(G)Ready [$(NAME)]$(X)

clean:
	@make -C $(FT_PRINTF_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(FT_PRINTF_PATH) clean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re norm