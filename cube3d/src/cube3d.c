#include "../include/cube3d.h"

int main(int argc, char **argv)
{
	t_map *map;

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return 1;
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		printf("Error: Memory allocation failed for map.\n");
		return 1;
	}
	if (global_check(argv[1], map) != 0)
		return 1;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (DEBUG)
		map->mlx = mlx_init(map->mat.width * BLOCK, map->mat.height * BLOCK, "cube3d albo", true);
	else
		map->mlx = mlx_init(WIDTH, HEIGHT, "cube3d albo", true);
	if (!map->mlx)
	{
		printf("Error: MLX initialization failed.\n");
		free_all(map);
		return 1;
	}

	init_game(map);
	mlx_key_hook(map->mlx, &my_keyhook, map);
	mlx_loop_hook(map->mlx, &draw_loop, map);
	mlx_loop(map->mlx);
	free_all(map);
	return 0;
}
