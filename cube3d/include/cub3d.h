/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:14:27 by aboussem          #+#    #+#             */
/*   Updated: 2025/11/25 14:18:59 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 1920
# define HEIGHT 1080
# define DEBUG 0
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define PI 3.14159265358979323846
# define BLOCK 64
# define PLAYER_SIZE 20

# define DEFAULT_SPEED 4
# define MIN_SPEED 1
# define MAX_SPEED 20

typedef struct s_pos
{
	mlx_image_t	*img;
	int			x;
	int			y;
}	t_pos;

typedef struct s_mat
{
	int		width;
	int		height;
	char	**mat;
}	t_mat;

typedef struct s_camera
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}	t_camera;

typedef struct s_ray
{
	double	rdx;
	double	rdy;
	int		mapx;
	int		mapy;
	double	ddx;
	double	ddy;
	int		stepx;
	int		stepy;
	double	sdx;
	double	sdy;
	int		side;
	double	perp;
	int		line_h;
	int		draw_start;
	int		draw_end;
}		t_ray;

typedef struct s_elements
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_elements;

typedef struct s_textures
{
	mlx_texture_t	*no_tx;
	mlx_texture_t	*so_tx;
	mlx_texture_t	*we_tx;
	mlx_texture_t	*ea_tx;
	mlx_image_t		*no_img;
	mlx_image_t		*so_img;
	mlx_image_t		*we_img;
	mlx_image_t		*ea_img;
}	t_textures;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	int		speed;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	key_plus;
	bool	key_minus;

	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_map
{
	t_mat		mat;
	t_elements	elements;
	mlx_t		*mlx;

	t_player	*player;
	t_textures	textures;

	mlx_image_t	*img_background;
	mlx_image_t	*img_game;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}	t_map;

typedef struct s_texspan
{
	const mlx_texture_t	*tx;
	int					tex_x;
}	t_texspan;

int		init_map(t_map *map, int fd);
void	init_player(t_player *player, t_map *map);
int		init_mlx(t_map *map);
int		init_elements(t_elements *elements, char *line);
void	move_player(t_player *player, t_map *map);
int global_check(char *filename, t_map *map);

void init_map_elements(t_map *map);

/* Movement*/
int		is_wall(t_map *map, int mx, int my);
int		check_next_move(float new_x, float new_y, t_map *map);
void	move_up(t_map *map, float c, float s, int sp);
void	move_down(t_map *map, float c, float s, int sp);
void	move_left(t_map *map, float c, float s, int sp);
void	move_right(t_map *map, float c, float s, int sp);
void	move_player(t_player *player, t_map *map);
void	increase_speed(t_player *p);
void	decrease_speed(t_player *p);

/* Checkers */
int		check_inputs(t_map *map);
int		check_mat(t_mat *mat);
int		check_right_walls(t_mat *mat, int i, int j);
int		check_left_walls(t_mat *mat, int i, int j);
int		check_bottom_walls(t_mat *mat, int i, int j);
int		check_top_walls(t_mat *mat, int i, int j);

/* Freeing */
void	free_splits(char **splits);
void	free_all(t_map *map);
void	clear_image(t_map *map);
void	free_mlxtexture(t_textures textures, mlx_t *mlx);

/* Utils */
int		only_whitespace(const char *str);
void	my_keyhook(mlx_key_data_t keydata, void *param);
bool	touch(float px, float py, t_map *map);
float	distance(float dx, float dy);
size_t	line_len_no_nl(const char *line);
char	*dup_trim_ws(const char *s);
int		load_textures(t_map *map);

/* Print game */
int		init_game(t_map *map);
void	draw_square(int x, int y, int size, mlx_image_t *img);

/* Draw */
void	draw_loop(void *param);
void	draw_background(t_map *map);
void	draw_walls_textured(t_map *map);

/* Raycasting helpers */
void	build_camera_from_player(const t_player *player, t_camera *cam);
void	set_ray_dir(int x, const t_camera *cam, t_ray *ray);
void	set_ray_steps(double posx, double posy, t_ray *ray);
int		perform_dda_and_compute_perp(const t_map *map,
			t_ray *ray, double posx, double posy);
int		step_until_hit(const t_map *map, t_ray *ray);
void	compute_perp_distance(t_ray *ray, double posx, double posy);
void	compute_line_bounds(t_ray *ray);
int		ray_map_is_wall(const t_map *map, int mx, int my);
int		compute_tex_x_for_column(const t_map *map, const t_ray *ray,
			const mlx_texture_t *tx);

/* Texture helpers */
void	sample_tex_rgba(const mlx_texture_t *tx, int u, int v,
			uint8_t rgba[4]);
void	shade_if_needed(uint8_t rgba[4], const t_ray *ray);

/* Textures */

void	init_textures_defaults(t_textures *t);
int		load_textures(t_map *map);
void	destroy_textures(t_map *map);
void	init_textures(t_map *map);

int		get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int		get_rgba_bg(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int		color_rgba(char *s);

#endif
