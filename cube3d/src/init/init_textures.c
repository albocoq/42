/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:37:40 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/25 14:02:13 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*load_texture_file(const char *path)
{
	if (!path)
		return (NULL);
	return (mlx_load_png(path));
}

static void	print_load_error(const char *path)
{
	if (path)
		fprintf(stderr, "Error: failed to load PNG texture: %s\n", path);
	else
		fprintf(stderr, "Error: failed to load PNG texture: (null)\n");
}

static void	init_content(const char *paths[4], mlx_texture_t	**txs[4],
		mlx_image_t **imgs[4], t_map *map)
{
	paths[0] = map->elements.no;
	paths[1] = map->elements.so;
	paths[2] = map->elements.we;
	paths[3] = map->elements.ea;
	txs[0] = &map->textures.no_tx;
	txs[1] = &map->textures.so_tx;
	txs[2] = &map->textures.we_tx;
	txs[3] = &map->textures.ea_tx;
	imgs[0] = &map->textures.no_img;
	imgs[1] = &map->textures.so_img;
	imgs[2] = &map->textures.we_img;
	imgs[3] = &map->textures.ea_img;
}

static int	load_one(mlx_t *mlx, const char *path, mlx_texture_t **out_tx,
	mlx_image_t **out_img)
{
	mlx_texture_t	*tx;
	mlx_image_t		*img;

	tx = load_texture_file(path);
	if (!tx)
	{
		print_load_error(path);
		return (1);
	}
	img = mlx_texture_to_image(mlx, tx);
	if (!img)
	{
		print_load_error(path);
		mlx_delete_texture(tx);
		return (1);
	}
	*out_tx = tx;
	*out_img = img;
	return (0);
}

int	load_textures(t_map *map)
{
	const char		*paths[4];
	mlx_texture_t	**txs[4];
	mlx_image_t		**imgs[4];
	int				i;

	init_content(paths, txs, imgs, map);
	if (!map || !map->mlx)
		return (1);
	destroy_textures(map);
	i = 0;
	while (i < 4)
	{
		if (load_one(map->mlx, paths[i], txs[i], imgs[i]))
		{
			destroy_textures(map);
			return (1);
		}
		++i;
	}
	return (0);
}
