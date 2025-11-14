/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:32:37 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/06 19:54:34 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (printf("Usage: %s <map_file>\n", argv[0]), 1);
	map = malloc(sizeof * map);
	if (!map)
		return (printf("Error: Memory allocation failed for map.\n"), 1);
	if (global_check(argv[1], map) || init_mlx(map) || load_textures(map)
		|| init_game(map))
	{
		free_all(map);
		return (1);
	}
	mlx_key_hook(map->mlx, my_keyhook, map);
	mlx_loop_hook(map->mlx, draw_loop, map);
	mlx_loop(map->mlx);
	free_all(map);
	return (0);
}
