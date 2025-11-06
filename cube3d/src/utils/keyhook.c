/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:11:04 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/05 11:17:43 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	handle_key_press(mlx_key_data_t keydata, t_player *player)
{
	if (keydata.key == MLX_KEY_W)
		player->key_up = true;
	else if (keydata.key == MLX_KEY_S)
		player->key_down = true;
	else if (keydata.key == MLX_KEY_A)
		player->key_left = true;
	else if (keydata.key == MLX_KEY_D)
		player->key_right = true;
	else if (keydata.key == MLX_KEY_LEFT)
		player->left_rotate = true;
	else if (keydata.key == MLX_KEY_RIGHT)
		player->right_rotate = true;
	else if (keydata.key == 107)
		player->key_plus = true;
	else if (keydata.key == 109)
		player->key_minus = true;
}

static void	handle_key_released(mlx_key_data_t keydata, t_player *player)
{
	if (keydata.key == MLX_KEY_W)
		player->key_up = false;
	else if (keydata.key == MLX_KEY_S)
		player->key_down = false;
	else if (keydata.key == MLX_KEY_A)
		player->key_left = false;
	else if (keydata.key == MLX_KEY_D)
		player->key_right = false;
	else if (keydata.key == MLX_KEY_LEFT)
		player->left_rotate = false;
	else if (keydata.key == MLX_KEY_RIGHT)
		player->right_rotate = false;
	else if (keydata.key == 107)
		player->key_plus = false;
	else if (keydata.key == 109)
		player->key_minus = false;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map		*data;
	t_player	*player;

	data = param;
	player = data->player;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		handle_key_press(keydata, player);
	}
	else if (keydata.action == MLX_RELEASE)
		handle_key_released(keydata, player);
}
