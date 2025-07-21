/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:26:10 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/10 09:26:51 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_2(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	is_posible(char **map, int x, int y, t_pos max)
{
	if (x >= max.x || y >= max.y || map[x][y] == 'X' || map[x][y] == '1' )
		return ;
	map[x][y] = 'X';
	is_posible(map, x + 1, y, max);
	is_posible(map, x - 1, y, max);
	is_posible(map, x, y + 1, max);
	is_posible(map, x, y - 1, max);
}

void	check_existed_items(char **mat, t_pos max, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < max.x)
	{
		y = 0;
		while (y < max.y && mat[x][y] != '\0')
		{
			if (mat[x][y] == 'C' || mat[x][y] == 'E')
			{
				free_map_2(mat, max.x);
				ft_perror("Map impossible", map, 1);
			}
			y++;
		}
		x++;
	}
}

char	**copy_map_f(char **original, t_pos max, t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(max.x * sizeof(char *));
	i = 0;
	if (copy == NULL)
	{
		ft_perror("Memory allocation failed", map, 0);
		return (NULL);
	}
	while (i < max.x)
	{
		copy[i] = ft_strdup(original[i]);
		if (copy[i] == NULL)
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	ft_check_is_posible(t_map *data)
{
	char	**copy_map;
	t_pos	character;
	t_pos	max;

	max.x = data->mat.height;
	max.y = data->mat.width;
	character.x = data->elements.character.x;
	character.y = data->elements.character.y;
	copy_map = copy_map_f(data->mat.mat, max, data);
	if (copy_map == NULL)
		return ;
	is_posible(copy_map, character.y, character.x, max);
	check_existed_items(copy_map, max, data);
	free_map_2(copy_map, max.x);
}
