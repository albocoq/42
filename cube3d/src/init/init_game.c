/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:57:23 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/06 10:51:33 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_square(int x, int y, int size, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_put_pixel(img, x + i, y + j, (uint32_t)0x00FF00FF);
			j++;
		}
		i++;
	}
}

static void	get_img_dimensions(t_map *map, int *width, int *height)
{
	if (DEBUG)
	{
		*width = map->mat.width * BLOCK;
		*height = map->mat.height * BLOCK;
	}
	else
	{
		*width = WIDTH;
		*height = HEIGHT;
	}
}

int	init_game(t_map *map)
{
	mlx_image_t	*img_game;
	mlx_image_t	*img_background;
	int			img_width;
	int			img_height;

	if (!map->player)
	{
		map->player = (t_player *)malloc(sizeof(t_player));
		if (!map->player)
			return (1);
	}
	init_player(map->player, map);
	get_img_dimensions(map, &img_width, &img_height);
	img_game = mlx_new_image(map->mlx, img_width, img_height);
	img_background = mlx_new_image(map->mlx, img_width, img_height);
	mlx_image_to_window(map->mlx, img_background, 0, 0);
	mlx_image_to_window(map->mlx, img_game, 0, 0);
	map->img_game = img_game;
	map->img_background = img_background;
	draw_square(img_width / 2, img_height / 2, 10, map->img_game);
	draw_background(map);
	return (0);
}
