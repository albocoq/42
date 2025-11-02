/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:00:00 by juanandub         #+#    #+#             */
/*   Updated: 2025/11/02 12:30:06 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define WIDTH 800
# define HEIGHT 600

# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_pos
{
	int	x;
	int y;
	mlx_image_t* img;
}	t_pos;

typedef struct s_mat
{
	int		width;
	int 	height;
	char 	**mat;
}	t_mat;

typedef struct s_elements
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_elements;
typedef struct s_map
{
	t_mat mat;
	t_elements elements;
	mlx_t* mlx;
}	t_map;


int init_map(t_map *map, int fd);
int global_check(char *filename, t_map *map);

/* Checkers */
int check_commands(char *filename);
int check_existence_file(char *filename);
int check_inputs(t_map *map);
int check_mat(t_mat *mat);
int check_right_walls(t_mat *mat, int i, int j);
int check_left_walls(t_mat *mat, int i, int j);
int check_bottom_walls(t_mat *mat, int i, int j);
int check_top_walls(t_mat *mat, int i, int j);

/* Freeing */
void free_splits(char **splits);
void	free_all(t_map *map);

/* Debug prints */
void print_elements(const t_elements *el);
void print_mat(const t_mat *mat);
void print_map(const t_map *map);

/* Utils */
int only_whitespace(const char *str);
void	my_keyhook(mlx_key_data_t keydata, void *param);

#endif
