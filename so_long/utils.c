/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:49:38 by aboussem          #+#    #+#             */
/*   Updated: 2025/02/03 10:12:50 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
void ft_perror(char *text, char *file)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(text, 2);
	if (file)
		ft_putstr_fd(file, 2);
	exit(EXIT_FAILURE);
}

void ft_hook(void* param)
{
	const mlx_t* mlx = param;
	static int width;
	static int height;
	
	if (!width)
		width = 0;
	if (!height)
		height = 0;
	if (mlx->width != width || mlx->height != height)
		printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	height = mlx->height;
	width = mlx->width;
}

static void ft_switch(t_map *map, char step)
{
	static int count;
	int x_temp;
	int y_temp;

	y_temp = map->elements.character.x;
	x_temp = map->elements.character.y;
	removewall(*map, (t_pos){y_temp * 100, x_temp * 100, NULL}, "./texture/floor.png", step);
	if (step == 't')
		count += goup(map, x_temp, y_temp);
	else if (step == 'b')
		count += godown(map, x_temp, y_temp);
	else if (step == 'l')
		count += goleft(map, x_temp, y_temp);
	else if (step == 'r')
		count += goright(map, x_temp, y_temp);
	ft_putstr_fd("\nNumber of steps: ", 2);		
	ft_putnbr_fd(count, 2);		
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_map	*data;

	data = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		else if (keydata.key == MLX_KEY_W)
			ft_switch(data, 't');
		else if (keydata.key == MLX_KEY_S)
			ft_switch(data, 'b');
		else if (keydata.key == MLX_KEY_A)
			ft_switch(data, 'l');
		else if (keydata.key == MLX_KEY_D)
			ft_switch(data, 'r');
	}
}