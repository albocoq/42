/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:41:46 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/10 09:27:37 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	createwall(t_map *map, t_pos pos, char *link)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(link);
	if (!texture)
		ft_perror("Texture", map, 0);
	img = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(map->mlx, img, pos.x, pos.y);
}

mlx_image_t	*createpers(t_pos pos, t_map *map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./texture/knight.png");
	if (!texture)
		ft_perror("Texture", map, 0);
	img = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(map->mlx, img, pos.x, pos.y);
	return (img);
}

void	removewall(t_map *map, t_pos pos, char *link, char step)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int				x_temp;
	int				y_temp;

	texture = mlx_load_png(link);
	if (!texture)
		ft_perror("Texture", map, 0);
	img = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	x_temp = map->elements.character.y;
	y_temp = map->elements.character.x;
	if (step == 't')
		remove_up_texture(img, pos, map, x_temp);
	else if (step == 'b')
		remove_down_texture(img, pos, map, x_temp);
	else if (step == 'l')
		remove_left_texture(img, pos, map, y_temp);
	else if (step == 'r')
		remove_right_texture(img, pos, map, y_temp);
}
