#include "cube3d.h"

void init_player(t_player *player, t_map *map)
{
  char **mat = map->mat.mat;
  int y;
  int x;

  y = 0;
  while (mat[y])
  {
    x = 0;
    while (mat[y][x])
    {
      if (mat[y][x] == 'N' || mat[y][x] == 'S' ||
          mat[y][x] == 'E' || mat[y][x] == 'W')
      {
        player->x = x * BLOCK + BLOCK / 2;
        player->y = y * BLOCK + BLOCK / 2;
      }
      x++;
    }
    y++;
  }
  player->angle = PI / 2;

  player->key_up = false;
  player->key_down = false;
  player->key_left = false;
  player->key_right = false;

  player->left_rotate = false;
  player->right_rotate = false;
}

static int is_wall(t_map *map, int mx, int my)
{
  if (my < 0 || mx < 0 || my >= map->mat.height || mx >= map->mat.width)
    return 1;
  return (map->mat.mat[my][mx] == '1');
}

int check_next_move(float new_x, float new_y, t_map *map)
{
  float m = 15;

  int mx0 = (int)((new_x - m) / BLOCK);
  int mx1 = (int)((new_x + m) / BLOCK);
  int my0 = (int)((new_y - m) / BLOCK);
  int my1 = (int)((new_y + m) / BLOCK);

  if (is_wall(map, mx0, my0)) return 0;
  if (is_wall(map, mx1, my0)) return 0;
  if (is_wall(map, mx0, my1)) return 0;
  if (is_wall(map, mx1, my1)) return 0;
  return 1;
}

void move_player(t_player *player, t_map *map)
{
  if (!player) return;
  int speed = 3;
  float angle_speed = 0.01;
  float cos_angle = cos(player->angle);
  float sin_angle = sin(player->angle);

  if (player->left_rotate)
    player->angle -= angle_speed;
  if (player->right_rotate)
    player->angle += angle_speed;
  if (player->angle > 2 * PI)
    player->angle = 0;
  if (player->angle < 0)
    player->angle = 2 * PI;

  if (player->key_up)
  {
    if (check_next_move(player->x + cos_angle * speed, player->y + sin_angle * speed, map))
    {
      player->x += cos_angle * speed;
      player->y += sin_angle * speed;
    }
  }
  if (player->key_down)
  {
    if (check_next_move(player->x - cos_angle * speed, player->y - sin_angle * speed, map))
    {
      player->x -= cos_angle * speed;
      player->y -= sin_angle * speed;
    }
  }
  if (player->key_left)
  {
    if (check_next_move(player->x + cos_angle * speed, player->y - sin_angle * speed, map))
    {
      player->x += cos_angle * speed;
      player->y -= sin_angle * speed;
    }
  }
  if (player->key_right)
  {
    if (check_next_move(player->x - cos_angle * speed, player->y + sin_angle * speed, map))
    {
      player->x -= cos_angle * speed;
      player->y += sin_angle * speed;
    }
  }
}