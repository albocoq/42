/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detroy_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:50:00 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_loaded_pair(mlx_t *mlx, mlx_texture_t **tx, mlx_image_t **img)
{
	if (*img)
	{
		mlx_delete_image(mlx, *img);
		*img = NULL;
	}
	if (*tx)
	{
		mlx_delete_texture(*tx);
		*tx = NULL;
	}
}

void	destroy_textures(t_map *map)
{
	if (!map || !map->mlx)
		return ;
	clear_loaded_pair(map->mlx, &map->textures.no_tx, &map->textures.no_img);
	clear_loaded_pair(map->mlx, &map->textures.so_tx, &map->textures.so_img);
	clear_loaded_pair(map->mlx, &map->textures.we_tx, &map->textures.we_img);
	clear_loaded_pair(map->mlx, &map->textures.ea_tx, &map->textures.ea_img);
}
