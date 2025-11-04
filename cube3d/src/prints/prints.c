#include "cube3d.h"
#include <stdio.h>

static void print_str_field(const char *label, const char *value)
{
    if (value)
        printf("%s: %s\n", label, value);
    else
        printf("%s: (null)\n", label);
}

static const char *bool_str(bool v)
{
    return v ? "true" : "false";
}

void print_player(const t_player *pl)
{
    if (!pl)
    {
        printf("[player] (null)\n");
        return;
    }
    printf("[player]\n");
    printf("  pos: x=%.2f y=%.2f\n", pl->x, pl->y);
    printf("  keys: up=%s down=%s left=%s right=%s\n",
           bool_str(pl->key_up), bool_str(pl->key_down),
           bool_str(pl->key_left), bool_str(pl->key_right));
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
        printf("\n");
    }
    else
    {
        y = 0;
        while (mat->mat[y])
        {
            printf("  %s", mat->mat[y]);
            y++;
        }
        printf("\n");
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
    print_player(((t_map *)map)->player);
    printf("-------------------------------------------\n");
    print_mat(&((t_map *)map)->mat);
    printf("===========================================\n");
}
