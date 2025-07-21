NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -rf

INCLUDE     = includes
SRC_DIR     = .
LIBFT_DIR     = libft/srcs
OBJ_DIR     = obj
LIBFT_SRC   = $(LIBFT_DIR)/ft_libft
PRINTF_SRC  = $(LIBFT_DIR)/ft_printf
GETNEXTLINE_SRC  = $(LIBFT_DIR)/get_next_line

SRC_FILES   = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_SRC)/*.c) $(wildcard $(PRINTF_SRC)/*.c) $(wildcard $(GETNEXTLINE_SRC)/*.c)
OBJ_FILES   = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

RED         = \033[1;31m
GREEN       = \033[1;32m
BLUE        = \033[1;34m
YELLOW      = \033[1;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(YELLOW)Création de $(NAME)...$(RESET)"
	@$(CC) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)$(NAME) créé avec succès!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compilacion de $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	@echo "$(RED)Suppression des fichiers objets...$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Suppression de $(NAME)...$(RESET)"
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
