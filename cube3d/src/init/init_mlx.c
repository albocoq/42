/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:32:25 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/05 10:34:26 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_mlx(t_map *map)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (DEBUG)
		map->mlx = mlx_init(map->mat.width * BLOCK, map->mat.height * BLOCK,
				"cube3d albo", true);
	else
		map->mlx = mlx_init(WIDTH, HEIGHT, "cube3d albo", true);
	if (!map->mlx)
	{
		printf("Error: MLX initialization failed.\n");
		free_all(map);
		return (1);
	}
	return (0);
}
