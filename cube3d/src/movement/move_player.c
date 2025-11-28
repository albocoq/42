/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:41:41 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	increase_speed(t_player *p)
{
	if (!p)
		return ;
	if (p->speed < MAX_SPEED)
		p->speed += 1;
}

void	decrease_speed(t_player *p)
{
	if (!p)
		return ;
	if (p->speed > MIN_SPEED)
		p->speed -= 1;
}

static void	conditional_move_player(t_player *player, t_map *map,
	float cos_a, float sin_a)
{
	int		sp;

	sp = player->speed;
	if (player->key_plus && sp < MAX_SPEED)
		increase_speed(player);
	if (player->key_minus && sp > MIN_SPEED)
		decrease_speed(player);
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
	float	angle_s;

	angle_s = 0.07;
	cos_a = cos(player->angle);
	sin_a = sin(player->angle);
	if (!player)
		return ;
	if (player->left_rotate)
		player->angle -= angle_s;
	if (player->right_rotate)
		player->angle += angle_s;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	conditional_move_player(player, map, cos_a, sin_a);
}
