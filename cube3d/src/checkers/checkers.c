#include "cube3d.h"

int check_commands(char *filename)
{
  int i;
  char **file;

  file = ft_split(filename, '.');
  i = 0;
  if (!file) {
    printf("Error: Unable to split filename.\n");
    i = 1;
  } else if (!file[1]) {
    printf("Error: Invalid file format: <%s>.cub\n", filename);
    i = 1;
  } else if (ft_strcmp(file[1], "cub") != 0) {
    printf("Error: Invalid file format: <%s>.cub\n", filename);
    i = 1;
  }
  free_splits(file);
  return i;
}

int check_existence_file(char *filename)
{
  int fd;

  fd = open(filename, O_RDONLY);
  if (fd < 0)
    printf("Error: File <%s> does not exist or cannot be opened.\n", filename);
  return fd;
}

int check_elements(t_elements *elements)
{
  const char *paths[4];
  int fd;
  int i;

  i = 0;
  paths[0] = elements->no;
  paths[1] = elements->so;
  paths[2] = elements->we;
  paths[3] = elements->ea;
  while (i < 4)
  {
    if (!paths[i] || paths[i][0] == '\0')
    {
      printf("Error: Texture path is missing.\n");
      return 1;
    }
    fd = open(paths[i], O_RDONLY);
    if (fd < 0)
    {
      printf("Error: Texture file <%s> does not exist or cannot be opened.\n", paths[i]);
      return 1;
    }
    close(fd);
    i++;
  }
  return 0;
}

int check_inputs(t_map *map)
{
  if (check_elements(&map->elements) != 0)
    return 1;
  if (check_mat(&map->mat) != 0)
    return 1;
  return 0;
}