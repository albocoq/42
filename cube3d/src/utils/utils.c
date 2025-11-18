/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:08:59 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	only_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

bool	touch(float px, float py, t_map *map)
{
	int	x;
	int	y;

	x = (int)(px / BLOCK);
	y = (int)(py / BLOCK);
	if (y < 0 || x < 0 || y >= map->mat.height || x >= map->mat.width)
		return (true);
	if (map->mat.mat[y][x] == '1')
		return (true);
	return (false);
}

float	distance(float dx, float dy)
{
	return (sqrtf(dx * dx + dy * dy));
}

int	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	color_rgba(char *s)
{
	char		**split_color;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	split_color = ft_split(s, ',');
	if (!split_color || !split_color[0] || !split_color[1] || !split_color[2])
	{
		free_splits(split_color);
		return (0);
	}
	r = (uint8_t)ft_atoi(split_color[0]);
	g = (uint8_t)ft_atoi(split_color[1]);
	b = (uint8_t)ft_atoi(split_color[2]);
	free_splits(split_color);
	return (get_rgba(r, g, b, 255));
}
