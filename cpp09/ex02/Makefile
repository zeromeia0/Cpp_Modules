# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: vivaz-ca <vivaz-ca@student.42lisboa.com>     +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 0026/04/01 01:25:21 by #+#                 #+#    #+#             #
#   Updated: 2026/10/09 13:59:13 by vivaz-ca           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -g -std=c++98

NAME	=	PmergeMe
OBJ_DIR =	obj
SRC		=	main.cpp \
			PmergeMe.cpp

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

val: re
	@valgrind --leak-check=full ./$(NAME)


re: fclean all

test:
	@echo "===== TEST 1 ===== "
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "===== TEST 2 ===== "
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@echo "===== TEST 3 ===== "
	@./$(NAME) "(1 + 1)"
	@echo "===== TEST 4 ===== "
	@./$(NAME) "1 2"
	@echo "===== TEST 5 ===== "
	@./$(NAME) "12 4 +"
	@echo "===== TEST 6 ===== "
	@./$(NAME) "8 0 /"
	@echo "===== TEST 7 ===== "
	@./$(NAME) "8 2 +"
	
.PHONY: all clean fclean re