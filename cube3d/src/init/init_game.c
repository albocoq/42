#include "cube3d.h"

void draw_square(int x, int y, int size, int color, mlx_image_t *img)
{
  int i;

  i = 0;
  while (i < size)
  {
    mlx_put_pixel(img, x + i, y, (uint32_t)color);
    i++;
  }
  i = 0;
  while (i < size)
  {
    mlx_put_pixel(img, x, y + i, (uint32_t)color);
    i++;
  }
  i = 0;
  while (i < size)
  {
    mlx_put_pixel(img, x + size, y + i, (uint32_t)color);
    i++;
  }
  i = 0;
  while (i < size)
  {
    mlx_put_pixel(img, x + i, y + size, (uint32_t)color);
    i++;
  }
}

int init_game(t_map *map)
{
  if (!map->player)
  {
    map->player = (t_player *)malloc(sizeof(t_player));
    if (!map->player)
      return 1;
  }
  init_player(map->player, map);
  mlx_image_t *img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(map->mlx, img, 0, 0);
  map->img = img;

  draw_square(WIDTH / 2, HEIGHT / 2, 10, 0x00FF00FF, map->img);

  print_map(map);
  return 0;
}