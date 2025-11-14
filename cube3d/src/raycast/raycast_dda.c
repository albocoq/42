/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:01:00 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/06 19:46:51 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ray_map_is_wall(const t_map *map, int mx, int my)
{
	int			rowlen;
	const char	*row;
	char		c;

	if (!map || !map->mat.mat)
		return (1);
	if (my < 0 || mx < 0 || my >= map->mat.height)
		return (1);
	row = map->mat.mat[my];
	rowlen = (int)line_len_no_nl(row);
	if (mx >= rowlen)
		return (1);
	c = row[mx];
	return (c == '1' || c == ' ');
}

int	step_until_hit(const t_map *map, t_ray *ray)
{
	int	guard;
	int	hit;

	guard = 0;
	hit = 0;
	ray->side = 0;
	while (!hit && guard++ < 8192)
	{
		if (ray->sdx < ray->sdy)
		{
			ray->sdx += ray->ddx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sdy += ray->ddy;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (ray_map_is_wall(map, ray->mapx, ray->mapy))
			hit = 1;
	}
	return (hit);
}

void	compute_perp_distance(t_ray *ray, double posx, double posy)
{
	if (ray->side == 0)
		ray->perp = (ray->mapx - posx + (1 - ray->stepx) / 2.0) / ray->rdx;
	else
		ray->perp = (ray->mapy - posy + (1 - ray->stepy) / 2.0) / ray->rdy;
	if (ray->perp <= 1e-6)
		ray->perp = 1e-6;
}

int	perform_dda_and_compute_perp(const t_map *map,
		t_ray *ray, double posx, double posy)
{
	if (!step_until_hit(map, ray))
		return (0);
	compute_perp_distance(ray, posx, posy);
	return (1);
}
