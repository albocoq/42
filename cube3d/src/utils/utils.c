#include "cube3d.h"

int only_whitespace(const char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return 0;
        i++;
    }
    return 1;
}

bool touch(float px, float py, t_map *map)
{
    int x = px / BLOCK;
    int y = py / BLOCK;

    if (map->mat.mat[y][x] == '1')
        return true;
    return false;
}

float distance(float dx, float dy)
{
  return sqrtf(dx * dx + dy * dy);
}
