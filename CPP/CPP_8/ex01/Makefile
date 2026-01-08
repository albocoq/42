# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albocoq <albocoq@student.42.fr>         /home/albocoq/dev/42/CPP/CPP_2/Makefile   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 15:25:52 by aboussem          #+#    #+#              #
#    Updated: 2025/11/11 14:40:22 by albocoq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = ex01
CC      = c++
CFLAGS  = -Wall -Werror -Wextra -std=c++98
RM      = rm -f

RED     = \033[1;31m
GREEN   = \033[1;32m
BLUE    = \033[1;34m
YELLOW  = \033[1;33m
RESET   = \033[0m

SRCS    = main.cpp Span.cpp

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
