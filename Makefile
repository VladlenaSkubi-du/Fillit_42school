# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sschmele <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 15:31:08 by sschmele          #+#    #+#              #
#    Updated: 2019/04/08 14:28:30 by sschmele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SOURCES = main.c check.c read_and_struct.c square.c fill_and_clean.c
DIR_O = objs
DIR_S = srcs
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all:	$(NAME)

$(NAME):	text $(OBJS)
			@make --directory ./libft
			@gcc $(FLAGS) $(OBJS) -o $(NAME) -L ./libft -lft
			@echo "\x1b[32;01mYour ./fillit is ready\x1b[32;01m"

text:
			@echo "\x1b[32;01mCompilation\x1b[32;01m"

$(OBJS):	$(DIR_O)/%.o: $(DIR_S)/%.c includes/fillit.h
			@mkdir -p $(DIR_O)
			@gcc $(FLAGS) -c $< -I includes -o $@
clean:
			@echo "\033[34mDeliting o-files\033[34m"
			@/bin/rm -f $(OBJS)
			@make clean --directory ./libft

fclean:	clean
			@echo "\033[34mDeliting binary\033[34m"
			@/bin/rm -f $(NAME)
			@make fclean --directory ./libft

re:	fclean all

