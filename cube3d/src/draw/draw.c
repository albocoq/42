/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:36:41 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/06 11:35:41 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_map(t_map *map)
{
	char	**mat;
	int		y;
	int		x;

	mat = map->mat.mat;
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (mat[y][x] == '1')
				draw_square(x * 64, y * 64, 64, map->img_game);
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

static void	draw_3d_walls(t_map *map, float ray_x, float ray_y, int i)
{
	float	dist;
	float	height;
	int		start_y;
	int		end_y;

	dist = fixed_dist(ray_x - map->player->x, ray_y - map->player->y, map);
	if (dist < 0.0001f)
		dist = 0.0001f;
	height = (BLOCK / dist) * (WIDTH / 2.0f);
	if (!isfinite(height))
		height = (float)HEIGHT * 4.0f;
	start_y = (int)((HEIGHT - height) / 2.0f);
	end_y = start_y + (int)height;
	if (start_y < 0)
		start_y = 0;
	if (end_y > HEIGHT)
		end_y = HEIGHT;
	if (i >= 0 && i < WIDTH)
	{
		while (start_y < end_y)
		{
			mlx_put_pixel(map->img_game, i, start_y, 0x00FF00FF);
			start_y++;
		}
	}
}

static void	draw_line(t_player *player, t_map *map, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;
	while (!touch(ray_x, ray_y, map))
	{
		if (DEBUG && (int)ray_x >= 0 && (int)ray_x < WIDTH
			&& (int)ray_y >= 0 && (int)ray_y < HEIGHT)
			mlx_put_pixel(map->img_game, (int)ray_x, (int)ray_y, 0x0000FFFF);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	if (!DEBUG)
		draw_3d_walls(map, ray_x, ray_y, i);
}

void	draw_loop(void *param)
{
	t_map		*map;
	float		fraction;
	float		start_x;
	int			i;
	t_player	*player;

	map = (t_map *)param;
	player = map->player;
	move_player(player, map);
	clear_image(map);
	if (DEBUG)
	{
		draw_square((int)player->x - PLAYER_SIZE / 2,
			(int)player->y - PLAYER_SIZE / 2, PLAYER_SIZE, map->img_game);
		draw_map(map);
	}
	fraction = PI / 2 / WIDTH;
	start_x = player->angle - (PI / 6);
	i = 0;
	while (i < WIDTH)
	{
		draw_line(player, map, start_x, i);
		start_x += fraction;
		i++;
	}
}
