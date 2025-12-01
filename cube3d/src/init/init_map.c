/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:47:57 by albocoq           #+#    #+#             */
/*   Updated: 2025/12/01 13:15:19 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgba_bg(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (((int)r << 0) | ((int)g << 8) | ((int)b << 16) | (int)(a << 24));
}

int	process_line(t_map *map, char *line)
{
	int			res;
	static int	map_started = 0;

	if (!map_started)
		if (only_whitespace(line))
			return (0);
	res = init_elements(&map->elements, line);
	if (res == 2)
		return (2);
	if (!res)
		return (0);
	map_started = 1;
	init_mat(&map->mat, line);
	return (1);
}

int	init_map(t_map *map, int fd)
{
	char	*line;
	int		res;
	int		map_started;
	int		map_finished;

	map_started = 0;
	map_finished = 0;
	line = get_next_line(fd);
	init_textures(map);
	while (line != NULL)
	{
		res = process_map_line(map, line);
		free(line);
		if (res != 0)
			return (res);
		line = get_next_line(fd);
	}
	return (0);
}
