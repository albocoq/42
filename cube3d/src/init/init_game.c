/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:57:23 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	create_images(t_map *map, int img_width, int img_height)
{
	mlx_image_t	*img_game;
	mlx_image_t	*img_background;

	img_game = mlx_new_image(map->mlx, img_width, img_height);
	if (!img_game)
		return (1);
	img_background = mlx_new_image(map->mlx, img_width, img_height);
	if (!img_background)
	{
		mlx_delete_image(map->mlx, img_game);
		return (1);
	}
	mlx_image_to_window(map->mlx, img_background, 0, 0);
	mlx_image_to_window(map->mlx, img_game, 0, 0);
	map->img_game = img_game;
	map->img_background = img_background;
	return (0);
}

int	init_game(t_map *map)
{
	int	img_width;
	int	img_height;

	if (!map || !map->mlx)
		return (1);
	if (load_textures(map))
		return (1);
	if (!map->player)
	{
		map->player = (t_player *)ft_calloc(1, sizeof(t_player));
		if (!map->player)
			return (1);
	}
	init_player(map->player, map);
	get_img_dimensions(map, &img_width, &img_height);
	if (create_images(map, img_width, img_height))
		return (1);
	return (0);
}
