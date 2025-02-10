#include "so_long.h"

static void printmap(t_map *map, mlx_t* mlx) 
{
    int     x;
    int     y;
    t_pos   pos;

    x = 0;
    y = 0;
    pos.y = 0;
    pos.x = 0;
    map->elements.collect.num = 0;
    
    while (y < map->mat.height)
    {
        pos.y = y * 100;
        x = 0;
        while (x < map->mat.width)
        {
            pos.x = x * 100;
            if (map->mat.mat[y][x] == '0')
                createwall(mlx, pos, "./texture/floor.png");
            else if (map->mat.mat[y][x] == '1')
                createwall(mlx, pos, "./texture/wall.png");
            else if (map->mat.mat[y][x] == 'C')
            {
                createwall(mlx, pos, "./texture/item.png");
                map->elements.collect.num++;
            }
            else if (map->mat.mat[y][x] == 'E')
            {
                createwall(mlx, pos, "./texture/final.png");
                map->elements.end.x = x;
                map->elements.end.y = y;
            }
            else if (map->mat.mat[y][x] == 'P')
            {
                createwall(mlx, pos, "./texture/floor.png");
                map->elements.character.img = createpers(mlx, pos, map->elements.character.img);
            }
            x++;
        }
        y++;
    }
}

static char **createmat(int width, int height, char *file) 
{
    char    **mat;
    int     count;
    int     fd;
    char    *line;

    count = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        ft_perror("Could not find file: ", file);
    mat = ft_calloc(height, sizeof(char *));
    while (count < height)
    {
        mat[count] = ft_calloc(width + 1, sizeof(char));
        count++;
    }
    count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        mat[count] = ft_strdup(line);
        free(line);
        count++;
    }
    close(fd);
    return (mat);
}

t_mat getfileinfo(char *file, t_mat mat)
{
    char    *line;
    int     fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        ft_perror("Could not find file: ", file);

    while ((line = get_next_line(fd)) != NULL)
    {
        if (mat.height == 0)
            mat.width = ft_strlenc(line, '\n');
        else if ((int)ft_strlenc(line, '\n') != mat.width)
            ft_perror("Width must be the same size: ", line);
        mat.height++;
        free(line);
    }
    close(fd);
    mat.mat = createmat(mat.width, mat.height, file);
    return (mat);
}

int32_t main(int argc, char **argv)
{
    t_map *map;
    mlx_t* mlx;

    if (argc != 2)
        ft_perror("Error: Input must look like: ./so_long map.ber", "");

    map = checkinput(argv[1]);
    if (map->mat.height && map->mat.width)
        mlx = mlx_init(map->mat.width * 100, map->mat.height * 100, "so_long albo", true);
    else
        mlx = mlx_init(WIDTH, HEIGHT, "so_long albo", true);
    if (!mlx)
        ft_error();

    map->mlx = mlx;

    printmap(map, mlx);
    // ft_check_is_posible(map);

    mlx_key_hook(map->mlx, &my_keyhook, map);
    mlx_loop_hook(mlx, ft_hook, mlx);

    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}
