#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 2000
# define HEIGHT 1000
# include "../MLX42/include/MLX42/MLX42.h"
# include "./libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

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

typedef struct s_col
{
	int num;
	int colected;
}	t_col;

typedef struct s_elements
{
	t_pos character;
	t_col collect;
	t_pos end;
}	t_elements;

typedef struct s_map
{
	t_mat mat;
	t_elements elements;
	mlx_t* mlx;
}	t_map;

typedef struct s_checker
{
	char	**map;
	int	coins_left;
}	t_checker;

// so_long
void ft_error(void);
void ft_perror(char *text, char *file);
void ft_hook(void* param);
void my_keyhook(mlx_key_data_t keydata, void* param);
t_map *checkinput(char *file);
t_mat getfileinfo(char *file, t_mat mat);
// void	ft_is_posible(t_mat *data, int j, int i, int left);
// void	ft_check_is_posible(t_map *data);

// textures
mlx_image_t* createpers(mlx_t* mlx, t_pos pos, mlx_image_t* last);
void createwall(mlx_t* mlx, t_pos pos, char *link);
void removewall(t_map map, t_pos pos, char *link, char step);

// moov
int goup(t_map *map, int x_temp, int y_temp);
int godown(t_map *map, int x_temp, int y_temp);
int goleft(t_map *map, int x_temp, int y_temp);
int goright(t_map *map, int x_temp, int y_temp);

#endif
