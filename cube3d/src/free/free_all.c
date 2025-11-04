#include "cube3d.h"

void	free_all(t_map *map)
{
	if (!map)
		return;
	if (map->mlx)
		mlx_terminate(map->mlx);
  if (map->player)
    free(map->player);
  if (map->mat.mat)
  {
    for (int i = 0; i < map->mat.height; i++)
      free(map->mat.mat[i]);
    free(map->mat.mat);
  }
  if (map->elements.no)
    free(map->elements.no);
  if (map->elements.so)
    free(map->elements.so);
  if (map->elements.we)
    free(map->elements.we);
  if (map->elements.ea)
    free(map->elements.ea);
  if (map->elements.f)
    free(map->elements.f);
  if (map->elements.c)
    free(map->elements.c);
	free(map);
}

void clear_image(t_map *map)
{
  int i;

  i = 0;

  while (i < HEIGHT)
  {
    int j = 0;
    while (j < WIDTH)
    {
      mlx_put_pixel(map->img, j, i, 0x00000000);
      j++;
    }
    i++;
  }
}
