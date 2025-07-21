/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:03:16 by aboussem          #+#    #+#             */
/*   Updated: 2025/03/10 10:00:10 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_textures(t_map *map, t_pos pos, int x, int y)
{
	if (map->mat.mat[y][x] != '0' && map->mat.mat[y][x] != '1'
		&& map->mat.mat[y][x] != 'C' && map->mat.mat[y][x] != 'E'
		&& map->mat.mat[y][x] != 'P')
		ft_perror("One or more caracters are undefined", map, 1);
	if (map->mat.mat[y][x] == '0')
		createwall(map, pos, "./texture/floor.png");
	else if (map->mat.mat[y][x] == '1')
		createwall(map, pos, "./texture/wall.png");
	else if (map->mat.mat[y][x] == 'C')
	{
		createwall(map, pos, "./texture/item.png");
		map->elements.collect.num++;
	}
	else if (map->mat.mat[y][x] == 'E')
	{
		createwall(map, pos, "./texture/final.png");
		map->elements.end.x = x;
		map->elements.end.y = y;
	}
	else if (map->mat.mat[y][x] == 'P')
	{
		createwall(map, pos, "./texture/floor.png");
		map->elements.character.img = createpers(pos, map);
	}
}

void	printmap(t_map *map)
{
	int		x;
	int		y;
	t_pos	pos;

	x = 0;
	y = 0;
	pos.y = 0;
	pos.x = 0;
	map->elements.collect.num = 0;
	map->elements.collect.colected = 0;
	while (y < map->mat.height)
	{
		pos.y = y * 100;
		x = 0;
		while (x < map->mat.width)
		{
			pos.x = x * 100;
			print_textures(map, pos, x, y);
			x++;
		}
		y++;
	}
}

char	**createmat(int height, char *file, char *line, t_map *map)
{
	char	**mat;
	int		count;
	int		fd;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_perror("Could not find file", map, 0);
	mat = malloc((height * sizeof(char *)) + 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		mat[count] = ft_strdup(line);
		free(line);
		count++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (mat);
}

t_mat	getfileinfo(char *file, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map->mat.mat = NULL;
	if (fd == -1)
		ft_perror("Could not find file", map, 1);
	while (line != NULL)
	{
		if (map->mat.height == 0)
			map->mat.width = ft_strlenc(line, '\n');
		else if ((int)ft_strlenc(line, '\n') != map->mat.width)
		{
			free_remaining_gnl(fd, line);
			close(fd);
			ft_perror("Width must be the same size", map, 1);
		}
		map->mat.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->mat.mat = createmat(map->mat.height, file, line, map);
	return (map->mat);
}

int32_t	main(int argc, char **argv)
{
	t_map	*map;
	mlx_t	*mlx;

	map = NULL;
	if (argc != 2)
		ft_perror("Input must look like: ./so_long map.ber", map, 0);
	check_extension(argv[1], map);
	map = checkinput(argv[1]);
	ft_check_is_posible(map);
	if (map->mat.height && map->mat.width)
		mlx = mlx_init(map->mat.width * 100, map->mat.height * 100,
				"so_long albo", true);
	else
		mlx = mlx_init(WIDTH, HEIGHT, "so_long albo", true);
	if (!mlx)
		ft_perror("MLX", map, 0);
	map->mlx = mlx;
	printmap(map);
	mlx_key_hook(map->mlx, &my_keyhook, map);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	free_all(map, 1);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
