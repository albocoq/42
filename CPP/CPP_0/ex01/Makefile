# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 15:25:52 by aboussem          #+#    #+#              #
#    Updated: 2025/12/02 10:55:58 by aboussem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = PhoneBook
CC      = c++
CFLAGS  = -Wall -Werror -Wextra -std=c++98
RM      = rm -f

RED     = \033[1;31m
GREEN   = \033[1;32m
BLUE    = \033[1;34m
YELLOW  = \033[1;33m
RESET   = \033[0m

SRCS    = $(NAME).cpp AddCommand.cpp SearchCommand.cpp Utils.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Création de $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) créé avec succès!$(RESET)"

%.o: %.cpp %.hpp
	@echo "$(BLUE)Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Suppression des fichiers objets...$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)Suppression de $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all