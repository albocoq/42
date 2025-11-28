/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:48:26 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/25 12:08:47 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_scanline(uint32_t *p32, int width, uint32_t color)
{
	int	x;

	x = 0;
	while (x < width)
		p32[x++] = color;
}

static void	fill_half_with_color(char *base, int width, int half_rows,
	uint32_t color)
{
	char		*scanline;
	uint32_t	*p32;
	int			y;

	scanline = malloc(width * 4);
	if (!scanline)
		return ;
	p32 = (uint32_t *)scanline;
	init_scanline(p32, width, color);
	y = 0;
	while (y < half_rows)
	{
		ft_memcpy(base + (size_t)y * (width * 4), scanline, width * 4);
		++y;
	}
	free(scanline);
}

void	draw_background(t_map *map)
{
	uint32_t	floor_color;
	uint32_t	ceil_color;
	size_t		stride;
	int			half;
	char		*dst;

	ceil_color = color_rgba(map->elements.c);
	floor_color = color_rgba(map->elements.f);
	stride = (size_t)map->img_background->width * 4;
	half = map->img_background->height / 2;
	dst = (char *)map->img_background->pixels;
	fill_half_with_color(dst, map->img_background->width, half, ceil_color);
	fill_half_with_color(dst + (size_t)half * stride,
		map->img_background->width, map->img_background->height - half,
		floor_color);
}
