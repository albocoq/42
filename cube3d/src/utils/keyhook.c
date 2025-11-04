#include "cube3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*data;

	data = param;
	t_player *player = data->player;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		else if (keydata.key == MLX_KEY_W)
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
	} else if (keydata.action == MLX_RELEASE)
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
	}
}