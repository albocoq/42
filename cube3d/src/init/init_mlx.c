/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:32:25 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/25 15:44:35 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_map *map)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (DEBUG)
		map->mlx = mlx_init(map->mat.width * BLOCK, map->mat.height * BLOCK,
				"cub3d albo", true);
	else
		map->mlx = mlx_init(WIDTH, HEIGHT, "cub3d albo", true);
	if (!map->mlx)
	{
		printf("Error\n MLX initialization failed.\n");
		free_all(map);
		return (1);
	}
	return (0);
}
