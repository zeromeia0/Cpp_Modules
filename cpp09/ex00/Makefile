# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: vivaz-ca <vivaz-ca@student.42lisboa.com>     +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 0026/04/01 01:25:21 by #                   #+#    #+#             #
#   Updated: 2026/10/07 14:19:38 by vivaz-ca           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	btc
OBJ_DIR =	obj
SRC		=	main.cpp \
			BitcoinExchange.cpp
			
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# -->ANSI COLOR <--
GREEN	= \e[0;32m
YELLOW	= \e[0;33m
RESET	= \e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo -e "$(GREEN)Compiling $<$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo -e "$(YELLOW)Cleaning...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo -e "$(YELLOW)Removing [$(NAME)]$(RESET)"
	@rm -f $(NAME)
	@if [ -f input.txt ]; then \
		echo -e "$(YELLOW)Removing [input.txt]$(RESET)"; \
		rm input.txt; \
	fi

test:
	@printf "date | value\n2011-01-03 | 3\n2011-01-03 | 2\n2011-01-03 | 1\n2011-01-03 | 1.2\n2011-01-09 | 1\n2012-01-11 | -1\n2001-42-42\n2012-01-11 | 1\n2012-01-11 | 2147483648\n" > input.txt
	@echo "=====Created [input.txt]====="

val: re
	@valgrind --leak-check=full ./$(NAME) input.txt

run: fclean all test
	@./$(NAME) input.txt

re: fclean all


.PHONY: all clean fclean re