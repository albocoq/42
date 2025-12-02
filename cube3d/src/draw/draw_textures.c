/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:29:55 by emilgarc          #+#    #+#             */
/*   Updated: 2025/12/02 10:27:22 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_textured_span(t_map *map, int x, const t_ray *ray,
			t_texspan span)
{
	int				y;
	int				tex_y;
	double			tex_pos;
	uint8_t			rgba[4];
	const double	step = (double)span.tx->height / (double)ray->line_h;

	tex_pos = (ray->draw_start - HEIGHT / 2.0 + ray->line_h / 2.0) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		sample_tex_rgba(span.tx, span.tex_x, tex_y, rgba);
		shade_if_needed(rgba, ray);
		mlx_put_pixel(map->img_game, x, y,
			get_rgba(rgba[0], rgba[1], rgba[2], rgba[3]));
		++y;
	}
}

static const mlx_texture_t	*pick_wall_texture(const t_map *map,
		int side, double rdx, double rdy)
{
	if (side == 0)
	{
		if (rdx > 0)
			return (map->textures.ea_tx);
		else
			return (map->textures.we_tx);
	}
	if (rdy > 0)
		return (map->textures.so_tx);
	return (map->textures.no_tx);
}

static const mlx_texture_t	*select_valid_texture(t_map *map, const t_ray *ray)
{
	const mlx_texture_t	*tx;

	tx = pick_wall_texture(map, ray->side, ray->rdx, ray->rdy);
	if (!tx || !tx->pixels || tx->width == 0 || tx->height == 0)
		return (NULL);
	return (tx);
}

static void	draw_textured_column(t_map *map, const t_ray *ray, int x)
{
	t_texspan			span;

	span.tx = select_valid_texture(map, ray);
	if (!span.tx)
		return ;
	span.tex_x = compute_tex_x_for_column(map, ray, span.tx);
	draw_textured_span(map, x, ray, span);
}

void	draw_walls_textured(t_map *map)
{
	int			x;
	t_ray		ray;
	t_camera	cam;
	double		posx;
	double		posy;

	if (!map || !map->player || !map->img_game || !map->img_game->pixels)
		return ;
	posx = map->player->x / (double)BLOCK;
	posy = map->player->y / (double)BLOCK;
	build_camera_from_player(map->player, &cam);
	x = 0;
	while (x < WIDTH)
	{
		set_ray_dir(x, &cam, &ray);
		set_ray_steps(posx, posy, &ray);
		if (!perform_dda_and_compute_perp(map, &ray, posx, posy))
			continue ;
		compute_line_bounds(&ray);
		draw_textured_column(map, &ray, x);
		x++;
	}
}
