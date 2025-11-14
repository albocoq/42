/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:36:41 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/07 11:42:39 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	draw_map(t_map *map, char *mode)
{
	char	**mat;
	int		y;
	int		x;
	int		block_size;

	if (ft_strcmp(mode, "minimap") == 0)
		block_size = 15;
	else
		block_size = BLOCK;
	mat = map->mat.mat;
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (mat[y][x] == '1')
				draw_square(x * block_size + 15, y * block_size + 15,
					block_size, map->img_game);
			x++;
		}
		y++;
	}
}

float	fixed_dist(float delta_x, float delta_y, t_map *map)
{
	float	angle;
	float	d;

	angle = atan2f(delta_y, delta_x) - map->player->angle;
	d = distance(delta_x, delta_y) * cosf(angle);
	if (!isfinite(d))
		d = 1.0f;
	if (d < 0.0001f)
		d = 0.0001f;
	return (fabsf(d));
}

static void	draw_single_ray(float angle, t_player *player, t_map *map)
{
	float	ray_x;
	float	ray_y;
	int		rx;
	int		ry;

	ray_x = player->x;
	ray_y = player->y;
	while (!touch(ray_x, ray_y, map))
	{
		rx = (int)ray_x;
		ry = (int)ray_y;
		if (DEBUG && rx >= 0 && rx < (int)map->img_game->width
			&& ry >= 0 && ry < (int)map->img_game->height)
			mlx_put_pixel(map->img_game, rx, ry, 0x0000FFFF);
		ray_x += cosf(angle);
		ray_y += sinf(angle);
	}
}

static void	render_rays(t_player *player, t_map *map)
{
	float	fraction;
	float	start_x;
	int		i;
	int		cols;

	cols = (int)map->img_game->width;
	if (cols <= 0)
		return ;
	fraction = PI / 2 / cols;
	start_x = player->angle - (PI / 6);
	i = 0;
	while (i < cols)
	{
		draw_single_ray(start_x, player, map);
		start_x += fraction;
		i++;
	}
}

void	draw_loop(void *param)
{
	t_map		*map;
	t_player	*player;

	map = (t_map *)param;
	player = map->player;
	move_player(player, map);
	clear_image(map);
	if (!DEBUG)
		draw_background(map);
	if (DEBUG)
	{
		draw_map(map, "full");
		draw_square((int)player->x - PLAYER_SIZE / 2,
			(int)player->y - PLAYER_SIZE / 2, PLAYER_SIZE, map->img_game);
		render_rays(player, map);
	}
	else
	{
		draw_walls_textured(map);
		draw_map(map, "minimap");
		draw_square((int)(player->x * 15 / 64 + 15) - 2,
			(int)(player->y * 15 / 64 + 15) - 2, 10, map->img_game);
	}
}
