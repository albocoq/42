/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:02:37 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/10 10:03:18 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	checkwalls(t_map *map)
{
	int	x;

	x = 0;
	while (map->mat.width > x)
	{
		if (map->mat.mat[0][x] != '1')
			ft_perror("Top wall must be all 1", map, 1);
		if (map->mat.mat[map->mat.height - 1][x] != '1')
			ft_perror("bottom wall must be all 1", map, 1);
		x++;
	}
	x = 0;
	while (map->mat.height > x)
	{
		if (map->mat.mat[x][0] != '1')
			ft_perror("left wall must be all 1", map, 1);
		if (map->mat.mat[x][map->mat.width - 1] != '1')
			ft_perror("right wall must be all 1", map, 1);
		x++;
	}
}

t_pos	checkduplicate(t_map *map, t_pos	pos)
{
	t_pos	character;
	int		n;

	n = 0;
	while (pos.y < map->mat.height)
	{
		pos.x = 0;
		while (pos.x < map->mat.width)
		{
			if (map->mat.mat[pos.y][pos.x] == 'E')
				n++;
			if (map->mat.mat[pos.y][pos.x] == 'P')
			{
				character.x = pos.x;
				character.y = pos.y;
				n++;
			}
			pos.x++;
		}
		pos.y++;
	}
	if (n != 2)
		ft_perror("It muts have only one E and one P", map, 0);
	return (character);
}

static void	checkcollective(t_map *map)
{
	t_pos	pos;
	int		n;

	n = 0;
	pos.x = 0;
	pos.y = 0;
	while (pos.y < map->mat.height)
	{
		while (pos.x < map->mat.width)
		{
			if (map->mat.mat[pos.y][pos.x] == 'C')
				n++;
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	if (n < 1)
		ft_perror("It muts have at least on Collective item", map, 0);
}

t_map	*checkinput(char *file)
{
	t_map	*map;
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		ft_perror("Memory allocation failed", map, 0);
	map->mat.height = 0;
	map->mat.width = 0;
	map->mat = getfileinfo(file, map);
	if (map->mat.height >= map->mat.width)
	{
		free_all(map, 1);
		ft_perror("It must be a rectangule form", map, 0);
	}
	checkwalls(map);
	map->elements.character = checkduplicate(map, pos);
	checkcollective(map);
	return (map);
}

void	check_extension(char *command, t_map *map)
{
	char	**split_command;
	char	*type;

	type = "ber";
	split_command = ft_split(command, '.');
	if (split_command == NULL || split_command[1] == NULL)
	{
		free2d(split_command);
		ft_perror("Invalid command format", map, 0);
	}
	if (ft_strncmp(type, split_command[1], ft_strlen(type)) != 0)
	{
		free2d(split_command);
		ft_perror("Type of file must be .ber", map, 0);
	}
	free2d(split_command);
}
