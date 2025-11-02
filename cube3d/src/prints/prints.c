#include "cube3d.h"
#include <stdio.h>

static void print_str_field(const char *label, const char *value)
{
    if (value)
        printf("%s: %s\n", label, value);
    else
        printf("%s: (null)\n", label);
}

void print_elements(const t_elements *el)
{
    if (!el)
    {
        printf("[elements] (null)\n");
        return;
    }
    printf("[elements]\n");
    print_str_field("  NO", el->no);
    print_str_field("  SO", el->so);
    print_str_field("  WE", el->we);
    print_str_field("  EA", el->ea);
    print_str_field("  F ", el->f);
    print_str_field("  C ", el->c);
}

void print_mat(const t_mat *mat)
{
    int y;

    if (!mat)
    {
        printf("[map] (null)\n");
        return;
    }
    printf("[map] width=%d height=%d\n", mat->width, mat->height);
    if (!mat->mat)
    {
        printf("  (matrix null)\n");
        return;
    }
    if (mat->height > 0)
    {
        for (y = 0; y < mat->height; ++y)
        {
            if (mat->mat[y])
                printf("  %s", mat->mat[y]);
            else
                printf("  (null)\n");
        }
    }
    else
    {
        /* Fallback: print until NULL terminator if height is unknown */
        y = 0;
        while (mat->mat[y])
        {
            printf("  %s", mat->mat[y]);
            y++;
        }
    }
}

void print_map(const t_map *map)
{
    if (!map)
    {
        printf("[map] (null)\n");
        return;
    }
    printf("================ DEBUG MAP ================\n");
    print_elements(&((t_map *)map)->elements);
    printf("-------------------------------------------\n");
    print_mat(&((t_map *)map)->mat);
    printf("===========================================\n");
}
