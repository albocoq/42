// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_bfs.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/03 10:26:10 by aboussem          #+#    #+#             */
// /*   Updated: 2025/02/07 11:41:46 by aboussem         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// void	malloc_and_fill(t_checker *c, t_mat *data)
// {
// 	int	i;
// 	int	j;

// 	c->map = malloc(sizeof(int *) * data->height);
// 	i = -1;
// 	while (++i < data->height)
// 		c->map[i] = malloc(sizeof(int *) * data->width);
// 	i = -1;
// 	while (++i < data->height)
// 	{
// 		j = -1;
// 		while (++j < data->width)
// 			c->map[i][j] = 0;
// 	}
// }

// void	free_checker(t_checker *c, int hight)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < hight)
// 		free(c->map[i]);
// 	free(c->map);
// 	c->map = NULL;
// }

// void	iter_checker(t_checker *c, t_mat *data, int i, int j)
// {
// 	if (c->coins_left == 0)
// 		return ;
// 	if (c->map[i][j] == 0 && data->mat[i][j] != '1')
// 	{
// 		c->map[i][j] = 1;
// 		if (data->mat[i][j] == 'C' || data->mat[i][j] == 'E')
// 			c->coins_left--;
// 		if (data->mat[i][j] == 'E')
// 			return ;
// 		iter_checker(c, data, i + 1, j);
// 		iter_checker(c, data, i - 1, j);
// 		iter_checker(c, data, i, j + 1);
// 		iter_checker(c, data, i, j - 1);
// 	}
// }

// void	ft_is_posible(t_mat *data, int j, int i, int left)
// {
// 	t_checker	c;

// 	c.coins_left = left;
// 	malloc_and_fill(&c, data);
// 	iter_checker(&c, data, j, i);
// 	if (c.coins_left != 0)
// 	{
// 		write(2, "Error\nMap is imposible\n", 23);
// 		exit(EXIT_FAILURE);
// 	}
// 	free_checker(&c, data->height);
// }