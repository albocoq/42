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
void ft_perror(char *text, t_map *map, int all_free);
void ft_hook(void* param);
void my_keyhook(mlx_key_data_t keydata, void* param);
t_map *checkinput(char *file);
t_mat getfileinfo(char *file, t_map *map);
void	ft_check_is_posible(t_map *data);
void check_extension(char *command, t_map *map);
void free_all(t_map	*map, int all_free);
void free_map(char **map);

// textures
mlx_image_t *createpers(t_pos pos, t_map *map);
void createwall(t_map *map, t_pos pos, char *link);
void removewall(t_map *map, t_pos pos, char *link, char step);
void remove_left_texture(mlx_image_t *img, t_pos pos, t_map *map, int y_temp);
void remove_right_texture(mlx_image_t *img, t_pos pos, t_map *map, int y_temp);
void remove_up_texture(mlx_image_t *img, t_pos pos, t_map *map, int x_temp);
void remove_down_texture(mlx_image_t *img, t_pos pos, t_map *map, int x_temp);


// moov
int go_up(t_map *map, int x_temp, int y_temp, t_pos temp);
int go_down(t_map *map, int x_temp, int y_temp, t_pos temp);
int go_left(t_map *map, int x_temp, int y_temp, t_pos temp);
int go_right(t_map *map, int x_temp, int y_temp, t_pos temp);

// free
void	free2d(char **str);
void	free_remaining_gnl(int fd, char *line);

#endif
