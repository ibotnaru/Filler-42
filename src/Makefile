# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 12:37:43 by ibotnaru          #+#    #+#              #
#    Updated: 2019/09/29 01:38:06 by ibotnaru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I .
LIBFT = libft/libft.a

SRCS =  main.c \
		algorithm.c \
		hit_opponent.c \
		parsing.c \
		validation.c \

OBJ = $(SRCS:.c=.o)

EXEC = ibotnaru.filler

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o:%.c
	@echo "$(GREEN) - Creating $(GREEN_EXTRA)$<...$(RESET)"
	@gcc -Wall -Wextra -Werror -g -c $< -o $@ $(INCLUDES)

all: $(EXEC)
$(EXEC): $(OBJ)
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(EXEC)$(RESET)"
	# @make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@gcc -Wall -Wextra -Werror $(OBJ) $(LIBFT) $(INCLUDES) -g -o $(EXEC)
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	# @make -C libft clean
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi
	# @make -C libft fclean
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all
