# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 15:25:52 by aboussem          #+#    #+#              #
#    Updated: 2025/01/27 10:59:24 by aboussem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
AR          = ar rcs
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -rf

INCLUDE     = includes
SRC_DIR     = srcs
LIBFT_SRC   = $(SRC_DIR)/ft_libft
PRINTF_SRC  = $(SRC_DIR)/ft_printf
GETNEXTLINE_SRC  = $(SRC_DIR)/get_next_line
OBJ_DIR     = obj

SRC_FILES   = $(wildcard $(LIBFT_SRC)/*.c) $(wildcard $(PRINTF_SRC)/*.c) $(wildcard $(GETNEXTLINE_SRC)/*.c)
OBJ_FILES   = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_FILES:.c=.o))


RED         = \033[1;31m
GREEN       = \033[1;32m
BLUE        = \033[1;34m
YELLOW      = \033[1;33m
RESET       = \033[0m

all: ascii $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(YELLOW)Création de $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)$(NAME) créé avec succès!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

bonus: $(BONUS_OBJS)
	@echo "$(YELLOW)Ajout des fichiers bonus...$(RESET)"
	@$(AR) $(NAME) $(BONUS_OBJS)
	@echo "$(GREEN)Bonus ajoutés à $(NAME) avec succès!$(RESET)"

clean:
	@echo "$(RED)Suppression des fichiers objets...$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Suppression de $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

TEST_FILE   = tests/test.c
TEST_BIN    = test_libft

test: $(NAME) $(TEST_FILE)
	@echo "$(YELLOW)Compilation du fichier de test...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -o $(TEST_BIN) $(TEST_FILE) $(NAME)
	@echo "$(GREEN)Exécution du fichier de test :$(RESET)"
	@./$(TEST_BIN)

clean_test:
	@echo "$(RED)Suppression du fichier de test...$(RESET)"
	@$(RM) $(TEST_BIN)

ascii:
	@clear
	@printf "$(GREEN)"
	@echo "  _ _ _      __ _"
	@echo " | (_) |__  / _| |_"
	@echo " | | | '_ \| |_| __|"
	@echo " | | | |_) |  _| |_"
	@echo " |_|_|_.__/|_|  \__|"
	@echo "$(RED)by: ALBO"
	@echo "$(RESET)\n"

	
.PHONY: all clean fclean re ascii bonus
