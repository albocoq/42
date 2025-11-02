#include "cube3d.h"

int is_space_or_empty(char c)
{
    return (c == ' ' || c == '\0' || c == '\n');
}

int check_top_walls(t_mat *mat, int i, int j)
{
  while (j < mat->width)
  {
    if (mat->mat[0][j] == ' ' || mat->mat[0][j] == '\0')
    {
      i = 0;
      while (i < mat->height && is_space_or_empty(mat->mat[i][j]))
        i++;
      if (i >= mat->height || mat->mat[i][j] != '1') {
        printf("Error: Top row is not properly walled at column %d.\n", j);
        return 1;
      }
      j++;
      continue;
    }
    if (mat->mat[0][j] != '1' &&
      mat->mat[0][j] != '\n' &&
      mat->mat[0][j] != '\0')
    {
      printf("Error: Top row is not properly walled at column %d.\n", j);
      return 1;
    }
    j++;
  }
  return 0;
}

int check_bottom_walls(t_mat *mat, int i, int j)
{
  while (j < mat->width)
  {
    if (mat->mat[mat->height - 1][j] == ' ' || mat->mat[mat->height - 1][j] == '\0') {
      i = mat->height - 1;
      while (i >= 0 && is_space_or_empty(mat->mat[i][j]))
        i--;
      if (i < 0 || mat->mat[i][j] != '1') {
        printf("Error: 1 Bottom row is not properly walled at column %d.\n", j);
        return 1;
      }
      j++;
      continue;
    }
    if (mat->mat[mat->height - 1][j] != '1' &&
      mat->mat[mat->height - 1][j] != '\n' &&
      mat->mat[mat->height - 1][j] != '\0')
    {
      printf("Error: 2 Bottom row is not properly walled at column %d.\n", j);
      return 1;
    }
    j++;
  }
  return 0;
}

int check_left_walls(t_mat *mat, int i, int j)
{
  while (i < mat->height)
  {
    if (mat->mat[i][0] == ' ' || mat->mat[i][0] == '\0') {
      j = 0;
      while (j < mat->width && is_space_or_empty(mat->mat[i][j]))
        j++;
      if (j >= mat->width || mat->mat[i][j] != '1') {
        printf("Error: Left column is not properly walled at row %d.\n", i);
        return 1;
      }
      i++;
      continue;
    }
    if (mat->mat[i][0] != '1' &&
      mat->mat[i][0] != '\n' &&
      mat->mat[i][0] != '\0')
    {
      printf("Error: Left column is not properly walled at row %d.\n", i);
      return 1;
    }
    i++;
  }
  return 0;
}

int check_right_walls(t_mat *mat, int i, int j)
{
  while (i < mat->height)
  {
    if (mat->mat[i][mat->width - 1] == ' ' || mat->mat[i][mat->width - 1] == '\0' ) {
      j = mat->width - 1;
      while (j >= 0 && is_space_or_empty(mat->mat[i][j]))
        j--;
      if (j < 0 || mat->mat[i][j] != '1') {
        printf("Error: Right column is not properly walled at row %d.\n", i);
        return 1;
      }
      i++;
      continue;
    }
    if (mat->mat[i][mat->width - 1] != '1' &&
      mat->mat[i][mat->width - 1] != '\n' &&
      mat->mat[i][mat->width - 1] != '\0')
    {
      printf("Error: Right column is not properly walled at row %d.\n", i);
      return 1;
    }
    i++;
  }
  return 0;
}
