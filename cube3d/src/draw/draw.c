#include "cube3d.h"

void draw_map(t_map *map)
{
  char **mat = map->mat.mat;
  int color = 0x00FFFFFF;
  int y;
  int x;

  y = 0;
  while (mat[y])
  {
    x = 0;
    while (mat[y][x])
    {
      if (mat[y][x] == '1')
        draw_square(x * 64, y * 64, 64, color, map->img);
      x++;
    }
    y++;
  }
}

float fixed_dist(float x1, float y1, float x2, float y2, t_map *map)
{
  float delta_x = x2 - x1;
  float delta_y = y2 - y1;
  float angle = atan2f(delta_y, delta_x) - map->player->angle;
  float d = distance(delta_x, delta_y) * cosf(angle);
  if (!isfinite(d)) d = 1.0f;
  if (d < 0.0001f) d = 0.0001f;
  return fabsf(d);
}

void draw_line(t_player *player, t_map *map, float start_x, int i)
{
  float cos_angle = cos(start_x);
  float sin_angle = sin(start_x);
  float ray_x = player->x;
  float ray_y = player->y;

  (void)i;
  while (!touch(ray_x, ray_y, map))
  {
    if (DEBUG)
      mlx_put_pixel(map->img, ray_x, (int)ray_y, 0x0000FFFF);
    ray_x += cos_angle;
    ray_y += sin_angle;
  }

  if (!DEBUG)
  {
    float dist = fixed_dist(player->x, player->y, ray_x, ray_y, map);
    if (dist < 0.0001f) dist = 0.0001f;
    float height = (BLOCK / dist) * (WIDTH / 2.0f);
    if (!isfinite(height)) height = (float)HEIGHT * 4.0f;
    int start_y = (int)((HEIGHT - height) / 2.0f);
    int end_y   = start_y + (int)height;
    if (start_y < 0) start_y = 0;
    if (end_y > HEIGHT) end_y = HEIGHT;
    if (i >= 0 && i < WIDTH) {
      while (start_y < end_y)
      {
        mlx_put_pixel(map->img, i, start_y, 0x00FF00FF);
        start_y++;
      }
    }
  }

}

void draw_loop(void *param)
{
  t_map *map;
  t_player *player;

  map = (t_map *)param;
  player = map->player;
  move_player(player, map);
  clear_image(map);
  if (DEBUG)
  {
    draw_square((int)player->x - PLAYER_SIZE / 2, (int)player->y - PLAYER_SIZE / 2, PLAYER_SIZE, 0x00FF00FF, map->img);
    draw_map(map);
  }

  float fraction = PI / 2 / WIDTH;
  float start_x = player->angle - (PI / 6);
  int i = 0;

  while (i < WIDTH)
  {
    draw_line(player, map, start_x, i);
    start_x += fraction;
    i++;
  }

}