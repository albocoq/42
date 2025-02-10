/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:41:46 by aboussem          #+#    #+#             */
/*   Updated: 2025/01/30 13:54:23 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void createwall(mlx_t* mlx, t_pos pos, char *link)
{
	mlx_texture_t* texture = mlx_load_png(link);
	if (!texture)
		ft_error();
		
  	mlx_image_t* img = mlx_texture_to_image(mlx, texture);

    mlx_image_to_window(mlx, img, pos.x, pos.y);
}

mlx_image_t* createpers(mlx_t* mlx, t_pos pos, mlx_image_t* last)
{
	(void)last;
	mlx_texture_t* texture = mlx_load_png("./texture/knight.png");
	if (!texture)
		ft_error();
		
  	mlx_image_t* img = mlx_texture_to_image(mlx, texture);

    mlx_image_to_window(mlx, img, pos.x, pos.y);
	return (img);
}

void removewall(t_map map, t_pos pos, char *link, char step)
{
	mlx_texture_t* texture;
  	mlx_image_t* img;
	int x_temp;
	int y_temp;
	
	texture = mlx_load_png(link);
	if (!texture)
		ft_error();
	img = mlx_texture_to_image(map.mlx, texture);
	x_temp = map.elements.character.y;
	y_temp = map.elements.character.x;
	
	if (step == 't')	
	{
		x_temp--;
		if (map.mat.mat[x_temp][map.elements.character.x] != '1')
    		mlx_image_to_window(map.mlx, img, pos.x, pos.y);
		if (map.mat.mat[x_temp][map.elements.character.x] != 'E' && map.mat.mat[map.elements.character.y][map.elements.character.x] == 'E')
			createwall(map.mlx, pos, "./texture/final.png");
	}
	else if (step == 'b')
	{
		x_temp++;
		if (map.mat.mat[x_temp][map.elements.character.x] != '1')
    		mlx_image_to_window(map.mlx, img, pos.x, pos.y);
		if (map.mat.mat[x_temp][map.elements.character.x] != 'E' && map.mat.mat[map.elements.character.y][map.elements.character.x] == 'E')
			createwall(map.mlx, pos, "./texture/final.png");
	}
	else if (step == 'l')
	{
		y_temp--;
		if (map.mat.mat[map.elements.character.y][y_temp] != '1')
    		mlx_image_to_window(map.mlx, img, pos.x, pos.y);
		if (map.mat.mat[map.elements.character.y][y_temp] != 'E' && map.mat.mat[map.elements.character.y][map.elements.character.x] == 'E')
			createwall(map.mlx, pos, "./texture/final.png");
	}
	else if (step == 'r')
	{
		y_temp++;
		if (map.mat.mat[map.elements.character.y][y_temp] != '1')
    		mlx_image_to_window(map.mlx, img, pos.x, pos.y);
		if (map.mat.mat[map.elements.character.y][y_temp] != 'E' && map.mat.mat[map.elements.character.y][map.elements.character.x] == 'E')
			createwall(map.mlx, pos, "./texture/final.png");
	}
}