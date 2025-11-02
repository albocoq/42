# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 21:50:08 by albocoq           #+#    #+#              #
#    Updated: 2025/11/02 12:29:57 by albocoq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cube3d
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

XF86VM_PRESENT := $(wildcard /usr/lib*/libXxf86vm.* /usr/lib*/libXxf86vm.so*)
ifeq ($(XF86VM_PRESENT),)
$(warning libXxf86vm not found on the system. If link fails, install the Xxf86vm development package (e.g. libxxf86vm-dev).)
X11_EXTRA_LIBS :=
else
X11_EXTRA_LIBS := -lXxf86vm
endif

LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	$(SRCS_DIR)/cube3d.c \
				$(SRCS_DIR)/init/init_map.c \
		    $(SRCS_DIR)/checkers/global_check.c \
		    $(SRCS_DIR)/checkers/checkers.c \
				$(SRCS_DIR)/checkers/checker_mat.c \
				$(SRCS_DIR)/checkers/checker_mat_walls.c \
				$(SRCS_DIR)/utils/utils.c \
				$(SRCS_DIR)/utils/keyhook.c \
				$(SRCS_DIR)/free/free_splits.c \
				$(SRCS_DIR)/free/free_all.c \
				$(SRCS_DIR)/prints/prints.c


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
	@echo "cube3d compilado correctamente!"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS_DIR)/cube3d.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LIBFT_INCS_DIR) -c $< -o $@

clean:
	@echo "Limpiando archivos objeto..."
	@$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Limpiando ejecutable..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(LIBMLX_BUILD)

re: fclean all

.PHONY: all clean fclean re debug
