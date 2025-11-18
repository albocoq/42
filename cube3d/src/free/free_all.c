/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:29:31 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_elements(t_elements *elements)
{
	if (elements->no)
		free(elements->no);
	if (elements->so)
		free(elements->so);
	if (elements->we)
		free(elements->we);
	if (elements->ea)
		free(elements->ea);
	if (elements->f)
		free(elements->f);
	if (elements->c)
		free(elements->c);
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->mlx)
		mlx_terminate(map->mlx);
	if (map->player)
		free(map->player);
	if (map->mat.mat)
	{
		while (i < map->mat.height)
		{
			free(map->mat.mat[i]);
			i++;
		}
		free(map->mat.mat);
	}
	free_elements(&map->elements);
	free(map);
}

void	clear_image(t_map *map)
{
	int	total_pixels;

	if (!map || !map->img_game)
		return ;
	total_pixels = (int)map->img_game->width * (int)map->img_game->height
		* (int) sizeof(int32_t);
	ft_memset(map->img_game->pixels, 0, total_pixels);
}
