/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:32:37 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/05 10:33:16 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		printf("Error: Memory allocation failed for map.\n");
		return (1);
	}
	if (global_check(argv[1], map) != 0)
		return (1);
	if (init_mlx(map) != 0)
		return (1);
	if (init_game(map) != 0)
		return (1);
	mlx_key_hook(map->mlx, &my_keyhook, map);
	mlx_loop_hook(map->mlx, &draw_loop, map);
	mlx_loop(map->mlx);
	free_all(map);
	return (0);
}
