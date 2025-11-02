#include "../include/cube3d.h"

int global_check(char *filename, t_map *map) {
  int fd;

  map->mat.width = 0;
  map->mat.height = 0;
  map->mat.mat = NULL;
  /* ensure elements pointers are initialized to NULL to avoid freeing garbage */
  map->elements.no = NULL;
  map->elements.so = NULL;
  map->elements.we = NULL;
  map->elements.ea = NULL;
  map->elements.f = NULL;
  map->elements.c = NULL;
  if (check_commands(filename) != 0)
    return 1;
  if ((fd = check_existence_file(filename)) < 0)
    return 1;
  if (init_map(map, fd) != 0)
    return 1;
  if (check_inputs(map) != 0)
    return 1;
  if (fd > 0)
    close(fd);
  return 0;
}