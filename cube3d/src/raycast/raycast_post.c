/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_post.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:02:00 by albocoq           #+#    #+#             */
/*   Updated: 2025/12/01 10:47:55 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	compute_line_bounds(t_ray *ray)
{
	ray->line_h = (int)(HEIGHT / ray->perp);
	ray->draw_start = -ray->line_h / 2 + HEIGHT / 2;
	ray->draw_end = ray->line_h / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

int	compute_tex_x_for_column(const t_map *map, const t_ray *ray,
		const mlx_texture_t *tx)
{
	int		tex_x;
	double	wall_x;

	if (ray->side == 0)
		wall_x = (map->player->y / (double)BLOCK + ray->perp * ray->rdy);
	else
		wall_x = (map->player->x / (double)BLOCK + ray->perp * ray->rdx);
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tx->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= (int)tx->width)
		tex_x = (int)tx->width - 1;
	if (ray->side == 0 && ray->rdx < 0)
		tex_x = (int)tx->width - tex_x - 1;
	if (ray->side == 1 && ray->rdy > 0)
		tex_x = (int)tx->width - tex_x - 1;
	return (tex_x);
}
