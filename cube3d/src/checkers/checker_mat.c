#include "cube3d.h"

static int char_invalid_character(t_mat *mat)
{
  int i;
  int j;

  i = 0;
  while (i < mat->height)
  {
    j = 0;
    while (j < mat->width)
    {
      if (mat->mat[i][j] != '0' && mat->mat[i][j] != '1' &&
          mat->mat[i][j] != 'N' && mat->mat[i][j] != 'S' &&
          mat->mat[i][j] != 'E' && mat->mat[i][j] != 'W' &&
          mat->mat[i][j] != ' ' && mat->mat[i][j] != '\n' &&
          mat->mat[i][j] != '\0')
      {
        printf("Error: Invalid character '%c' in map at (%d, %d).\n", mat->mat[i][j], i, j);
        return 1;
      }
      j++;
    }
    i++;
  }
  return 0;
}

static int check_exterior_walls(t_mat *mat)
{
  int i;
  int j;

  i = 0;
  j = 0;
  if (check_top_walls(mat, i, j) != 0)
    return 1;
  i = mat->height - 1;
  j = 0;
  if (check_bottom_walls(mat, i, j) != 0)
    return 1;
  i = 0;
  j = 0;
  if (check_left_walls(mat, i, j) != 0)
    return 1;
  i = 0;
  j = mat->width - 1;
  if (check_right_walls(mat, i, j) != 0)
    return 1;
  return 0;
}


int check_mat(t_mat *mat)
{
  if (char_invalid_character(mat) != 0)
    return 1;
  if (check_exterior_walls(mat) != 0)
    return 1;
  return 0;
}