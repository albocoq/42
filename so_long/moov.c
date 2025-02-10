/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:06:23 by aboussem          #+#    #+#             */
/*   Updated: 2025/02/03 10:03:46 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int goup(t_map *map, int x_temp, int y_temp)
{
	t_pos temp;

    if (map->mat.mat[map->elements.character.y][map->elements.character.x] != 'E')
        map->mat.mat[map->elements.character.y][map->elements.character.x] = '0';
    x_temp--;
    temp.x = y_temp * 100;
    temp.y = x_temp * 100;
    if (map->mat.mat[x_temp][map->elements.character.x] == 'C')
        map->elements.collect.colected++;
    if (map->mat.mat[x_temp][map->elements.character.x] == 'E' && map->elements.collect.colected == map->elements.collect.num)
    {
        mlx_close_window(map->mlx);
        ft_putstr_fd("GG You Won", 2);
    }
    else if (map->mat.mat[x_temp][map->elements.character.x] == 'E' && map->elements.collect.colected != map->elements.collect.num)
        ft_putstr_fd("You need all collection", 2);
    if (map->mat.mat[x_temp][map->elements.character.x] != '1')
    {
        map->elements.character.y--;
        if (map->mat.mat[x_temp][map->elements.character.x] != 'E')
            createwall(map->mlx, temp, "./texture/floor.png");
        createpers(map->mlx, temp, map->elements.character.img);
        return (1);
    }
    return (0);
}

int godown(t_map *map, int x_temp, int y_temp)
{
	t_pos temp;
    
    if (map->mat.mat[map->elements.character.y][map->elements.character.x] != 'E')
        map->mat.mat[map->elements.character.y][map->elements.character.x] = '0';
    x_temp++;
    temp.x = y_temp * 100;
    temp.y = x_temp * 100;
    if (map->mat.mat[x_temp][map->elements.character.x] == 'C')
        map->elements.collect.colected++;
    if (map->mat.mat[x_temp][map->elements.character.x] == 'E' && map->elements.collect.colected == map->elements.collect.num)
    {
        mlx_close_window(map->mlx);
        ft_putstr_fd("GG You Won", 2);
    }
    else if (map->mat.mat[x_temp][map->elements.character.x] == 'E' && map->elements.collect.colected != map->elements.collect.num)
        ft_putstr_fd("You need all collection", 2);
    if (map->mat.mat[x_temp][map->elements.character.x] != '1')
    {
        map->elements.character.y++;
        if (map->mat.mat[x_temp][map->elements.character.x] != 'E')
            createwall(map->mlx, temp, "./texture/floor.png");
        createpers(map->mlx, temp, map->elements.character.img);
        return (1);
    }
    return (0);
}

int goleft(t_map *map, int x_temp, int y_temp)
{
	t_pos temp;

    if (map->mat.mat[map->elements.character.y][map->elements.character.x] != 'E')
        map->mat.mat[map->elements.character.y][map->elements.character.x] = '0';
    y_temp--;
    temp.x = y_temp * 100;
    temp.y = x_temp * 100;
    if (map->mat.mat[map->elements.character.y][y_temp] == 'C')
        map->elements.collect.colected++;
    if (map->mat.mat[map->elements.character.y][y_temp] == 'E' && map->elements.collect.colected == map->elements.collect.num)
    {
        mlx_close_window(map->mlx);
        ft_putstr_fd("GG You Won", 2);
    }
    else if (map->mat.mat[map->elements.character.y][y_temp] == 'E' && map->elements.collect.colected != map->elements.collect.num)
        ft_putstr_fd("You need all collection", 2);
    if (map->mat.mat[map->elements.character.y][y_temp] != '1')
    {
        map->elements.character.x--;
        if (map->mat.mat[map->elements.character.y][y_temp] != 'E')
            createwall(map->mlx, temp, "./texture/floor.png");
        createpers(map->mlx, temp, map->elements.character.img);
        return (1);
    }
    return (0);
}

int goright(t_map *map, int x_temp, int y_temp)
{
	t_pos temp;
    
    if (map->mat.mat[map->elements.character.y][map->elements.character.x] != 'E')
        map->mat.mat[map->elements.character.y][map->elements.character.x] = '0';
    y_temp++;
    temp.x = y_temp * 100;
    temp.y = x_temp * 100;
    if (map->mat.mat[map->elements.character.y][y_temp] == 'C')
        map->elements.collect.colected++;
    if (map->mat.mat[map->elements.character.y][y_temp] == 'E' && map->elements.collect.colected == map->elements.collect.num)
    {
        mlx_close_window(map->mlx);
        ft_putstr_fd("GG You Won", 2);
    }
    else if (map->mat.mat[map->elements.character.y][y_temp] == 'E' && map->elements.collect.colected != map->elements.collect.num)
        ft_putstr_fd("You need all collection", 2);
    if (map->mat.mat[map->elements.character.y][y_temp] != '1')
    {
        map->elements.character.x++;
        if (map->mat.mat[map->elements.character.y][y_temp] != 'E')
            createwall(map->mlx, temp, "./texture/floor.png");
        createpers(map->mlx, temp, map->elements.character.img);
        return (1);
    }
    return (0);
}