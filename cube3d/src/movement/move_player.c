/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:41:41 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/05 12:37:21 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	conditional_move_player(t_player *player, t_map *map,
	float cos_a, float sin_a)
{
	float	angle_s;

	angle_s = 0.04;
	if (player->key_plus && player->speed < MAX_SPEED)
		player->speed += 1;
	if (player->key_minus && player->speed > MIN_SPEED)
		player->speed -= 1;
	if (player->left_rotate)
		player->angle -= angle_s;
	if (player->right_rotate)
		player->angle += angle_s;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	if (player->key_up)
		move_up(map, cos_a, sin_a, player->speed);
	if (player->key_down)
		move_down(map, cos_a, sin_a, player->speed);
	if (player->key_left)
		move_left(map, cos_a, sin_a, player->speed);
	if (player->key_right)
		move_right(map, cos_a, sin_a, player->speed);
}

void	move_player(t_player *player, t_map *map)
{
	float	cos_a;
	float	sin_a;

	cos_a = cos(player->angle);
	sin_a = sin(player->angle);
	if (!player)
		return ;
	conditional_move_player(player, map, cos_a, sin_a);
}
