#include "cube3d.h"

static char *dup_trim_ws(const char *s)
{
  size_t start = 0;
  size_t end;
  char *out;

  if (!s)
    return NULL;
  while (s[start] && (s[start] == ' ' || s[start] == '\t' || s[start] == '\n'))
    start++;
  end = ft_strlen(s);
  while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n'))
    end--;
  out = (char *)malloc((end - start) + 1);
  if (!out)
    return NULL;
  ft_memcpy(out, s + start, end - start);
  out[end - start] = '\0';
  return out;
}

static int init_elements(t_elements *elements, char *line) {
  const char *p;
  char *tmp;

  if ((line[0] == 'N' && line[1] == 'O') ||
      (line[0] == 'S' && line[1] == 'O') ||
      (line[0] == 'W' && line[1] == 'E') ||
      (line[0] == 'E' && line[1] == 'A'))
  {
    p = line + 2;
    while (*p == ' ' || *p == '\t') p++;
    tmp = dup_trim_ws(p);
    if (!tmp)
      return 0;
    if (line[0] == 'N' && line[1] == 'O')
    {
      if (elements->no)
        free(elements->no);
      elements->no = tmp;
    }
    else if (line[0] == 'S' && line[1] == 'O')
    {
      if (elements->so)
        free(elements->so);
      elements->so = tmp;
    }
    else if (line[0] == 'W' && line[1] == 'E')
    {
      if (elements->we)
        free(elements->we);
      elements->we = tmp;
    }
    else if (line[0] == 'E' && line[1] == 'A')
    {
      if (elements->ea)
        free(elements->ea);
      elements->ea = tmp;
    }
    return 0;
  }
  else if (line[0] == 'F' || line[0] == 'C')
  {
    p = line + 1;
    while (*p == ' ' || *p == '\t')
      p++;
    tmp = dup_trim_ws(p);
    if (!tmp)
      return 0;
    if (line[0] == 'F')
    {
      if (elements->f)
        free(elements->f);
      elements->f = tmp;
    }
    else
    {
      if (elements->c)
        free(elements->c);
      elements->c = tmp;
    }
    return 0;
  }
  return 1;
}

static void pad_existing_rows(t_mat *mat, int new_width)
{
  int i;

  i = 0;
  while (i < mat->height)
  {
    size_t old_len = ft_strlen(mat->mat[i]);
    if ((int)old_len < new_width)
    {
      char *newrow = (char *)malloc(new_width + 1);
      if (!newrow)
        return;
      ft_memcpy(newrow, mat->mat[i], old_len);
      ft_memset(newrow + old_len, ' ', new_width - (int)old_len);
      newrow[new_width] = '\0';
      free(mat->mat[i]);
      mat->mat[i] = newrow;
    }
    i++;
  }
}

static size_t line_len_no_nl(const char *line)
{
  size_t len = ft_strlen(line);
  if (len > 0 && line[len - 1] == '\n')
    return len - 1;
  return len;
}

static void init_mat(t_mat *mat, char *line) {
  size_t linelen = line_len_no_nl(line);

  if ((int)linelen > mat->width)
  {
    int new_width = (int)linelen;
    pad_existing_rows(mat, new_width);
    mat->width = new_width;
  }
  if (mat->height == 0)
    mat->height = 1;
  else
    mat->height++;

  mat->mat = ft_realloc(mat->mat, sizeof(char *) * (mat->height + 1));
  mat->mat[mat->height - 1] = (char *)malloc(mat->width + 1);
  if (mat->mat[mat->height - 1])
  {
    ft_memcpy(mat->mat[mat->height - 1], line, linelen);
    if (linelen < (size_t)mat->width)
      ft_memset(mat->mat[mat->height - 1] + linelen, ' ', mat->width - (int)linelen);
    mat->mat[mat->height - 1][mat->width] = '\0';
  }
  mat->mat[mat->height] = NULL;
}

int init_map(t_map *map, int fd) {
  char *line;

  while ((line = get_next_line(fd)) != NULL)
  {
    if (only_whitespace(line))
    {
      free(line);
      continue;
    }
    if (!init_elements(&map->elements, line))
    {
      free(line);
      continue;
    }
    init_mat(&map->mat, line);
    free(line);
  }
  if (line)
    free(line);
  return 0;
}
