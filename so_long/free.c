/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:58:48 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/10 10:03:00 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_map *map, int all_free)
{
	int	count;

	if (!map)
		return ;
	if (!map->mat.mat)
	{
		if (all_free)
			free(map);
		return ;
	}
	count = 0;
	while (map->mat.height > count)
	{
		if (map->mat.mat[count])
			free(map->mat.mat[count]);
		count++;
	}
	free(map->mat.mat);
	if (all_free)
		free(map);
}

void	free2d(char **str)
{
	int	x;

	x = 0;
	while (str[x])
		free(str[x++]);
	free(str);
}

void	free_remaining_gnl(int fd, char *line)
{
	char	*line_2;

	free(line);
	line_2 = get_next_line(fd);
	while (line_2 != NULL)
	{
		free(line_2);
		line_2 = get_next_line(fd);
	}
	free(line_2);
}
