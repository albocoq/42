/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removetexture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:29:53 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/10 10:04:14 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_left_texture(mlx_image_t *img, t_pos pos, t_map *map, int y_temp)
{
	y_temp--;
	if (map->mat.mat[map->elements.character.y][y_temp] != '1')
		mlx_image_to_window(map->mlx, img, pos.x, pos.y);
	if (map->mat.mat[map->elements.character.y][y_temp] != 'E' &&
		map->mat.mat[map->elements.character.y]
			[map->elements.character.x] == 'E')
		createwall(map, pos, "./texture/final.png");
}

void	remove_right_texture(mlx_image_t *img, t_pos pos, t_map *map, int temp)
{
	temp++;
	if (map->mat.mat[map->elements.character.y][temp] != '1')
		mlx_image_to_window(map->mlx, img, pos.x, pos.y);
	if (map->mat.mat[map->elements.character.y][temp] != 'E' &&
		map->mat.mat[map->elements.character.y]
			[map->elements.character.x] == 'E')
		createwall(map, pos, "./texture/final.png");
}

void	remove_up_texture(mlx_image_t *img, t_pos pos, t_map *map, int x_temp)
{
	x_temp--;
	if (map->mat.mat[x_temp][map->elements.character.x] != '1')
		mlx_image_to_window(map->mlx, img, pos.x, pos.y);
	if (map->mat.mat[x_temp][map->elements.character.x] != 'E' &&
		map->mat.mat[map->elements.character.y]
			[map->elements.character.x] == 'E')
		createwall(map, pos, "./texture/final.png");
}

void	remove_down_texture(mlx_image_t *img, t_pos pos, t_map *map, int x_temp)
{
	x_temp++;
	if (map->mat.mat[x_temp][map->elements.character.x] != '1')
		mlx_image_to_window(map->mlx, img, pos.x, pos.y);
	if (map->mat.mat[x_temp][map->elements.character.x] != 'E' &&
		map->mat.mat[map->elements.character.y]
			[map->elements.character.x] == 'E')
		createwall(map, pos, "./texture/final.png");
}

void	free_map(char **map)
{
	int	count;

	if (!map)
		return ;
	count = 0;
	while (map[count])
	{
		free(map[count]);
		map[count] = NULL;
		count++;
	}
	free(map);
	map = NULL;
}
