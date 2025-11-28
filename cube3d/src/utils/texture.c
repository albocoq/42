/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:03:00 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sample_tex_rgba(const mlx_texture_t *tx, int u, int v,
		uint8_t rgba[4])
{
	const uint8_t	*src;

	if (!tx || !tx->pixels || tx->width == 0 || tx->height == 0)
	{
		rgba[0] = 0;
		rgba[1] = 0;
		rgba[2] = 0;
		rgba[3] = 255;
		return ;
	}
	if (u < 0)
		u = 0;
	if (v < 0)
		v = 0;
	if ((uint32_t)u >= tx->width)
		u = (int)tx->width - 1;
	if ((uint32_t)v >= tx->height)
		v = (int)tx->height - 1;
	src = &tx->pixels[(v * tx->width + u) * 4];
	rgba[0] = src[0];
	rgba[1] = src[1];
	rgba[2] = src[2];
	rgba[3] = src[3];
}

void	shade_if_needed(uint8_t rgba[4], const t_ray *ray)
{
	if (ray->side == 1)
	{
		rgba[0] = (uint8_t)(rgba[0] * 0.8);
		rgba[1] = (uint8_t)(rgba[1] * 0.8);
		rgba[2] = (uint8_t)(rgba[2] * 0.8);
	}
}

void	init_textures_defaults(t_textures *t)
{
	if (!t)
		return ;
	t->no_tx = NULL;
	t->so_tx = NULL;
	t->we_tx = NULL;
	t->ea_tx = NULL;
	t->no_img = NULL;
	t->so_img = NULL;
	t->we_img = NULL;
	t->ea_img = NULL;
}

void	init_textures(t_map *map)
{
	init_textures_defaults(&map->textures);
	map->img_background = NULL;
	map->img_game = NULL;
	map->mlx = NULL;
	map->endian = 0;
	map->elements.no = NULL;
	map->elements.so = NULL;
	map->elements.we = NULL;
	map->elements.ea = NULL;
	map->elements.f = NULL;
	map->elements.c = NULL;
}
