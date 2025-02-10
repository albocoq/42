/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:02:37 by aboussem          #+#    #+#             */
/*   Updated: 2025/02/07 12:25:33 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void checkwalls(t_mat mat)
{
    int x;
    
    x = 0;
    while (mat.width > x)
    {
        if (mat.mat[0][x] != '1')
            ft_perror("Top wall must be all 1", "");
        x++;
    }
    x = 0;
    while (mat.width > x)
    {
        if (mat.mat[mat.height - 1][x] != '1')
            ft_perror("bottom wall must be all 1", "");
        x++;
    }
    x = 0;
    while (mat.height > x)
    {
        if (mat.mat[x][0] != '1')
            ft_perror("left wall must be all 1", "");
        x++;
    }
    x = 0;
    while (mat.height > x)
    {
        if (mat.mat[x][mat.width - 1] != '1')
            ft_perror("right wall must be all 1", "");
        x++;
    }
}

static t_pos checkduplicate(t_mat mat)
{
    t_pos pos;
    t_pos character;
    int n;

    n = 0;
    pos.x = 0;
    pos.y = 0;
    while (pos.y < mat.height)
    {
        while (pos.x < mat.width)
        {
            if (mat.mat[pos.y][pos.x] == 'E')
                n++;
            if (mat.mat[pos.y][pos.x] == 'P')
            {
                character.x = pos.x;
                character.y = pos.y;
                n++;
            }
            pos.x++;
        }
        pos.x = 0;
        pos.y++;
    }
    if (n != 2)
        ft_perror("It muts have only one E and one P", "");
    return (character);
}

static void checkcollective(t_mat mat)
{
    t_pos pos;
    int n;

    n = 0;
    pos.x = 0;
    pos.y = 0;
    while (pos.y < mat.height)
    {
        while (pos.x < mat.width)
        {
            if (mat.mat[pos.y][pos.x] == 'C')
                n++;
            pos.x++;
        }
        pos.x = 0;
        pos.y++;
    }
    if (n < 1)
        ft_perror("It muts have at least on Collective item", "");
}

t_map *checkinput(char *file)
{
	t_map 	*map;

    map = (t_map *)malloc(sizeof(t_map));
    if (map == NULL) {
        ft_perror("Memory allocation failed", "");
        return NULL;
    }
	map->mat.height = 0;
	map->mat.width = 0;
	map->mat = getfileinfo(file, map->mat);
	if (map->mat.height >= map->mat.width)
		ft_perror("It must be a rectangule form", "");
	checkwalls(map->mat);
    map->elements.character = checkduplicate(map->mat);
    checkcollective(map->mat);
	return (map);
}

// void ft_check_is_posible(t_map *data)
// {
//     int i[2];
//     int j[2];
//     int left;

//     left = 0;
//     i[0] = -1;
    
//     while (data->mat.mat[++i[0]])
//     {
//         i[1] = -1;
//         while (data->mat.mat[i[0]][++i[1]])
//         {
//             if (data->mat.mat[i[0]][i[1]] == 'P')
//             {
//                 j[0] = i[0];
//                 j[1] = i[1];
//             }
//             if (data->mat.mat[i[0]][i[1]] == 'E' || data->mat.mat[i[0]][i[1]] == 'C')
//                 left++;
//         }
//     }
//     printf("J[0]: %d, J[1]: %d, left: %d\n", j[0], j[1], left);
//     ft_is_posible(&data->mat, j[0], j[1], left);
// }
