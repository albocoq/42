/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:32:25 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
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
		printf("Error: MLX initialization failed.\n");
		free_all(map);
		return (1);
	}
	return (0);
}
