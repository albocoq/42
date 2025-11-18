/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:31:59 by emilgarc          #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_next_move(float new_x, float new_y, t_map *map)
{
	float	m;
	int		mx0;
	int		mx1;
	int		my0;
	int		my1;

	m = 15;
	mx0 = (int)((new_x - m) / BLOCK);
	mx1 = (int)((new_x + m) / BLOCK);
	my0 = (int)((new_y - m) / BLOCK);
	my1 = (int)((new_y + m) / BLOCK);
	if (is_wall(map, mx0, my0))
		return (0);
	if (is_wall(map, mx1, my0))
		return (0);
	if (is_wall(map, mx0, my1))
		return (0);
	if (is_wall(map, mx1, my1))
		return (0);
	return (1);
}

void	move_up(t_map *map, float c, float s, int sp)
{
	float	new_x;
	float	new_y;

	new_x = map->player->x + c * sp;
	new_y = map->player->y + s * sp;
	if (check_next_move(new_x, new_y, map))
	{
		map->player->x = new_x;
		map->player->y = new_y;
	}
	else if (check_next_move(new_x, map->player->y, map))
	{
		map->player->x = new_x;
	}
	else if (check_next_move(map->player->x, new_y, map))
	{
		map->player->y = new_y;
	}
}

void	move_down(t_map *map, float c, float s, int sp)
{
	float	new_x;
	float	new_y;

	new_x = map->player->x - c * sp;
	new_y = map->player->y - s * sp;
	if (check_next_move(new_x, new_y, map))
	{
		map->player->x = new_x;
		map->player->y = new_y;
	}
	else if (check_next_move(new_x, map->player->y, map))
	{
		map->player->x = new_x;
	}
	else if (check_next_move(map->player->x, new_y, map))
	{
		map->player->y = new_y;
	}
}

void	move_left(t_map *map, float c, float s, int sp)
{
	float	nx;
	float	ny;

	nx = map->player->x + (s) * sp;
	ny = map->player->y + (-c) * sp;
	if (check_next_move(nx, ny, map))
	{
		map->player->x = nx;
		map->player->y = ny;
	}
	else if (check_next_move(nx, map->player->y, map))
	{
		map->player->x = nx;
	}
	else if (check_next_move(map->player->x, ny, map))
	{
		map->player->y = ny;
	}
}

void	move_right(t_map *map, float c, float s, int sp)
{
	float	nx;
	float	ny;

	nx = map->player->x + (-s) * sp;
	ny = map->player->y + (c) * sp;
	if (check_next_move(nx, ny, map))
	{
		map->player->x = nx;
		map->player->y = ny;
	}
	else if (check_next_move(nx, map->player->y, map))
	{
		map->player->x = nx;
	}
	else if (check_next_move(map->player->x, ny, map))
	{
		map->player->y = ny;
	}
}
