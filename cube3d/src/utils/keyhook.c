#include "cube3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*data;

	data = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		// else if (keydata.key == MLX_KEY_W)
		// 	ft_switch(data, 't');
		// else if (keydata.key == MLX_KEY_S)
		// 	ft_switch(data, 'b');
		// else if (keydata.key == MLX_KEY_A)
		// 	ft_switch(data, 'l');
		// else if (keydata.key == MLX_KEY_D)
		// 	ft_switch(data, 'r');
	}
}