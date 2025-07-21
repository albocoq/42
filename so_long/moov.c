/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:06:23 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/06 17:23:38 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_map *map)
{
	free_all(map, 0);
	mlx_terminate(map->mlx);
	ft_putstr_fd("\nGG You Won", 2);
	exit(EXIT_SUCCESS);
}

int	go_up(t_map *map, int x_temp, int y_temp, t_pos temp)
{
	if (map->mat.mat[map->elements.character.y][map->elements.character.x]
			!= 'E')
		map->mat.mat[map->elements.character.y][map->elements.character.x]
			= '0';
	x_temp--;
	temp.x = y_temp * 100;
	temp.y = x_temp * 100;
	if (map->mat.mat[x_temp][map->elements.character.x] == 'C')
		map->elements.collect.colected++;
	if (map->mat.mat[x_temp][map->elements.character.x] == 'E'
		&& map->elements.collect.colected == map->elements.collect.num)
		end_game(map);
	else if (map->mat.mat[x_temp][map->elements.character.x] == 'E'
		&& map->elements.collect.colected != map->elements.collect.num)
		ft_putstr_fd("\nYou need all collection", 2);
	if (map->mat.mat[x_temp][map->elements.character.x] != '1')
	{
		map->elements.character.y--;
		if (map->mat.mat[x_temp][map->elements.character.x] != 'E')
			createwall(map, temp, "./texture/floor.png");
		createpers(temp, map);
		return (1);
	}
	return (0);
}

int	go_down(t_map *map, int x_temp, int y_temp, t_pos temp)
{
	if (map->mat.mat[map->elements.character.y][map->elements.character.x]
			!= 'E')
		map->mat.mat[map->elements.character.y][map->elements.character.x]
			= '0';
	x_temp++;
	temp.x = y_temp * 100;
	temp.y = x_temp * 100;
	if (map->mat.mat[x_temp][map->elements.character.x] == 'C')
		map->elements.collect.colected++;
	if (map->mat.mat[x_temp][map->elements.character.x] == 'E'
		&& map->elements.collect.colected == map->elements.collect.num)
		end_game(map);
	else if (map->mat.mat[x_temp][map->elements.character.x] == 'E'
		&& map->elements.collect.colected != map->elements.collect.num)
		ft_putstr_fd("\nYou need all collection", 2);
	if (map->mat.mat[x_temp][map->elements.character.x] != '1')
	{
		map->elements.character.y++;
		if (map->mat.mat[x_temp][map->elements.character.x] != 'E')
			createwall(map, temp, "./texture/floor.png");
		createpers(temp, map);
		return (1);
	}
	return (0);
}

int	go_left(t_map *map, int x_temp, int y_temp, t_pos temp)
{
	if (map->mat.mat[map->elements.character.y][map->elements.character.x]
			!= 'E')
		map->mat.mat[map->elements.character.y][map->elements.character.x]
			= '0';
	y_temp--;
	temp.x = y_temp * 100;
	temp.y = x_temp * 100;
	if (map->mat.mat[map->elements.character.y][y_temp] == 'C')
		map->elements.collect.colected++;
	if (map->mat.mat[map->elements.character.y][y_temp] == 'E'
		&& map->elements.collect.colected == map->elements.collect.num)
		end_game(map);
	else if (map->mat.mat[map->elements.character.y][y_temp] == 'E'
		&& map->elements.collect.colected != map->elements.collect.num)
		ft_putstr_fd("\nYou need all collection", 2);
	if (map->mat.mat[map->elements.character.y][y_temp] != '1')
	{
		map->elements.character.x--;
		if (map->mat.mat[map->elements.character.y][y_temp] != 'E')
			createwall(map, temp, "./texture/floor.png");
		createpers(temp, map);
		return (1);
	}
	return (0);
}

int	go_right(t_map *map, int x_temp, int y_temp, t_pos temp)
{
	if (map->mat.mat[map->elements.character.y][map->elements.character.x]
			!= 'E')
		map->mat.mat[map->elements.character.y][map->elements.character.x]
			= '0';
	y_temp++;
	temp.x = y_temp * 100;
	temp.y = x_temp * 100;
	if (map->mat.mat[map->elements.character.y][y_temp] == 'C')
		map->elements.collect.colected++;
	if (map->mat.mat[map->elements.character.y][y_temp] == 'E'
		&& map->elements.collect.colected == map->elements.collect.num)
		end_game(map);
	else if (map->mat.mat[map->elements.character.y][y_temp] == 'E'
		&& map->elements.collect.colected != map->elements.collect.num)
		ft_putstr_fd("\nYou need all collection", 2);
	if (map->mat.mat[map->elements.character.y][y_temp] != '1')
	{
		map->elements.character.x++;
		if (map->mat.mat[map->elements.character.y][y_temp] != 'E')
			createwall(map, temp, "./texture/floor.png");
		createpers(temp, map);
		return (1);
	}
	return (0);
}
