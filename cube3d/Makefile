# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 21:50:08 by albocoq           #+#    #+#              #
#    Updated: 2025/12/01 10:55:54 by aboussem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = src
OBJS_DIR = obj
INCS_DIR = include
LIBFT_DIR = libft
LIBFT_INCS_DIR = $(LIBFT_DIR)/includes
LIBMLX		= MLX42

HEADERS		= -I ./include -I $(LIBMLX)/include
LIBMLX_BUILD = $(LIBMLX)/build
MLX_LIB = $(LIBMLX_BUILD)/libmlx42.a
GLFW_LIB = $(LIBMLX_BUILD)/_deps/glfw-build/src/libglfw3.a
LIBS		= $(MLX_LIB) $(GLFW_LIB) -ldl -pthread -lm

LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	$(SRCS_DIR)/cub3d.c \
				$(SRCS_DIR)/init/init_map.c \
				$(SRCS_DIR)/init/init_map_utils.c \
				$(SRCS_DIR)/init/init_mat.c \
				$(SRCS_DIR)/init/init_game.c \
				$(SRCS_DIR)/init/init_player.c \
				$(SRCS_DIR)/init/init_mlx.c \
				$(SRCS_DIR)/init/init_element.c \
				$(SRCS_DIR)/init/init_textures.c \
				$(SRCS_DIR)/movement/moves.c \
				$(SRCS_DIR)/movement/move_player.c \
				$(SRCS_DIR)/checkers/global_check.c \
				$(SRCS_DIR)/checkers/checkers.c \
				$(SRCS_DIR)/checkers/checker_mat.c \
				$(SRCS_DIR)/checkers/checker_mat_walls.c \
				$(SRCS_DIR)/checkers/checker_colors.c \
				$(SRCS_DIR)/utils/utils.c \
				$(SRCS_DIR)/utils/keyhook.c \
				$(SRCS_DIR)/utils/texture.c \
				$(SRCS_DIR)/utils/map.c \
				$(SRCS_DIR)/utils/elements.c \
				$(SRCS_DIR)/free/free_splits.c \
				$(SRCS_DIR)/free/detroy_textures.c \
				$(SRCS_DIR)/free/free_all.c \
				$(SRCS_DIR)/draw/draw.c \
				$(SRCS_DIR)/draw/draw_background.c \
				$(SRCS_DIR)/draw/draw_textures.c \
				$(SRCS_DIR)/raycast/raycast_setup.c \
				$(SRCS_DIR)/raycast/raycast_dda.c \
				$(SRCS_DIR)/raycast/raycast_post.c \
				


OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

debug: CFLAGS += -g
debug: $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4


$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCS_DIR) -I$(LIBFT_INCS_DIR) $(LIBFT) -o $(NAME) $(MLX_LIB) $(GLFW_LIB) -ldl -pthread -lm -lX11 -lXrandr -lXinerama $(X11_EXTRA_LIBS) -lXcursor -lXi -lGL

$(MLX_LIB):
	@cmake $(LIBMLX) -B $(LIBMLX_BUILD)
	@$(MAKE) -C $(LIBMLX_BUILD) -j4
	@echo "cub3d compilation completed!"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS_DIR)/cub3d.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LIBFT_INCS_DIR) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@echo "Cleaning executable file..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
