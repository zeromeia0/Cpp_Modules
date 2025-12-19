# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeslin-ticiane <jeslinticianevaz@gmail.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 21:27:07 by jeslin-tici       #+#    #+#              #
#    Updated: 2025/12/18 20:39:21 by jeslin-tici      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	bored
SRC		=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp

OBJ		= $(SRC:.cpp=.o)

# -->ANSI COLOR <--
GREEN	= \e[0;32m
YELLOW	= \e[0;33m
RESET	= \e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@echo -e "$(GREEN)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -e "$(YELLOW)Cleaning...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo -e "$(YELLOW)Removing [$(NAME)]$(RESET)"
	@rm -f $(NAME)

val: re
	@valgrind --leak-check=full ./$(NAME)

re: fclean all

.PHONY: all clean fclean re