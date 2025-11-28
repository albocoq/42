/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:02:48 by emilgarc          #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_values_player(t_player *player)
{
	player->angle = PI / 2;
	player->speed = DEFAULT_SPEED;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
	player->key_plus = false;
	player->key_minus = false;
	player->x = 0;
	player->y = 0;
}

static void	start_player_angle(t_player *player, char **mat, int y, int x)
{
	if (mat[y][x] == 'N')
		player->angle = 3 * PI / 2;
	else if (mat[y][x] == 'S')
		player->angle = PI / 2;
	else if (mat[y][x] == 'E')
		player->angle = 0;
	else if (mat[y][x] == 'W')
		player->angle = PI;
}

void	init_player(t_player *player, t_map *map)
{
	char	**mat;
	int		y;
	int		x;

	mat = map->mat.mat;
	init_values_player(player);
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (mat[y][x] == 'N' || mat[y][x] == 'S' ||
				mat[y][x] == 'E' || mat[y][x] == 'W')
			{
				player->x = x * BLOCK + BLOCK / 2;
				player->y = y * BLOCK + BLOCK / 2;
				start_player_angle(player, mat, y, x);
			}
			x++;
		}
		y++;
	}
}

int	is_wall(t_map *map, int mx, int my)
{
	if (my < 0 || mx < 0 || my >= map->mat.height || mx >= map->mat.width)
		return (1);
	return (map->mat.mat[my][mx] == '1');
}
